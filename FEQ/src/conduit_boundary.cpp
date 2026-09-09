// Released FEQUTL 5.80 conduit boundary constructors.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/conduit_boundary.hpp>
#include <cmath>
#include <stdexcept>

namespace feq {
namespace {
struct CircleTrig { double sine; double cosine; };
CircleTrig circle_trig(double angle) {
    // MKPIPE uses x87 FSINCOS on DOUBLE angles in [0,2*pi]. Its internal
    // pi is rounded to 66 significant bits. Near the invert, replacing it
    // with mathematical pi changes even the final REAL x coordinate.
    // pi/2 = 0x1.921fb54442d18p+0 + 0x1.1a6p-54 at that precision.
    // Reduce about the nearest quadrant using both parts; subtraction of
    // the high part is exact here. Keep the low correction before SIN/COS.
    constexpr double half_pi_high = 0x1.921fb54442d18p+0;
    constexpr double half_pi_low = 0x1.1a6p-54;
    const int quadrant = static_cast<int>(angle/half_pi_high+0.5);
    const double reduced = (angle-static_cast<double>(quadrant)*half_pi_high)-
        static_cast<double>(quadrant)*half_pi_low;
    const double sine = std::sin(reduced);
    const double cosine = std::cos(reduced);
    if (quadrant == 1) { return CircleTrig{cosine,-sine}; }
    if (quadrant == 2) { return CircleTrig{-sine,-cosine}; }
    if (quadrant == 3) { return CircleTrig{-cosine,sine}; }
    return CircleTrig{sine,cosine};
}
void dimensions(float rise, float span) {
    if (!std::isfinite(rise) || !std::isfinite(span) || rise <= 0.0F || span <= 0.0F) {
        throw std::invalid_argument("Conduit dimensions must be finite and positive.");
    }
}
void placement_valid(const ConduitPlacement& placement) {
    if (!std::isfinite(placement.slot_width) || placement.slot_width < 0.0F ||
        !std::isfinite(placement.slot_height) || !std::isfinite(placement.x_offset) ||
        !std::isfinite(placement.y_offset)) {
        throw std::invalid_argument("Invalid conduit slot or placement.");
    }
}
void append(ConduitBoundary& boundary, double x, double y) {
    boundary.x.push_back(static_cast<float>(x));
    boundary.y.push_back(static_cast<float>(y));
}
ConduitBoundary mirrored(std::span<const float> x, std::span<const float> y,
    const ConduitPlacement& placement, bool quadrant) {
    placement_valid(placement);
    if (x.size() != y.size() || x.size() < 2 || x.size() > 1000000 || x[1] == 0.0F) {
        throw std::invalid_argument("Invalid conduit semi-perimeter extent or slot intersection.");
    }
    for (std::size_t index = 0; index < x.size(); ++index) {
        if (!std::isfinite(x[index]) || !std::isfinite(y[index])) {
            throw std::invalid_argument("Non-finite conduit semi-perimeter coordinate.");
        }
    }
    ConduitBoundary boundary;
    const std::size_t count = quadrant ? 4*x.size() : 2*x.size()+2;
    boundary.x.reserve(count); boundary.y.reserve(count);
    const double half_slot = static_cast<double>(placement.slot_width)*0.5;
    // YR = y1 + (y2-y1)*(WSLOT/2)/x2. Original 0x4107a4-0x4107da
    // and 0x4109ab-0x4109e5 retain YR through addition of YOFF.
    const double slot_y = y[0]+((static_cast<double>(y[1])-y[0])*half_slot)/x[1]+placement.y_offset;
    const double left = placement.x_offset-half_slot;
    const double right = placement.x_offset+half_slot;
    append(boundary,left,static_cast<double>(placement.slot_height)+static_cast<double>(0.01F));
    append(boundary,left,placement.slot_height);
    append(boundary,left,slot_y);
    for (std::size_t index = 1; index < x.size(); ++index) {
        append(boundary,static_cast<double>(placement.x_offset)-x[index],
            static_cast<double>(y[index])+placement.y_offset);
    }
    if (quadrant) {
        for (std::size_t index = x.size()-1; index > 0; --index) {
            append(boundary,static_cast<double>(placement.x_offset)-x[index-1],
                static_cast<double>(placement.y_offset)-y[index-1]);
        }
        for (std::size_t index = 1; index < x.size(); ++index) {
            append(boundary,static_cast<double>(placement.x_offset)+x[index],
                static_cast<double>(placement.y_offset)-y[index]);
        }
    }
    for (std::size_t index = x.size()-1; index > 1; --index) {
        append(boundary,static_cast<double>(placement.x_offset)+x[index-1],
            static_cast<double>(y[index-1])+placement.y_offset);
    }
    append(boundary,right,slot_y);
    append(boundary,right,placement.slot_height);
    return boundary;
}
}

ConduitBoundary ellipse_quadrant(float rise, float span) {
    dimensions(rise,span);
    ConduitBoundary boundary;
    boundary.x.resize(11); boundary.y.resize(11);
    const double a = static_cast<double>(span)*0.5;
    const double b = static_cast<double>(rise)*0.5;
    const double product = a*b;
    const double numerator = product*product;
    for (std::size_t index = 0; index < 11; ++index) {
        // THETA = REAL((10-i)*REAL(1.570796)*REAL(1/10)). The original
        // uses a rounded reciprocal constant, not binary64 division.
        const float theta = static_cast<float>((static_cast<double>(10-index)*
            static_cast<double>(1.570796F))*static_cast<double>(0.1F));
        const double sine = std::sin(static_cast<double>(theta));
        const double cosine = std::cos(static_cast<double>(theta));
        const double first = a*sine;
        const double second = b*cosine;
        // R = REAL(sqrt((ab)^2/((a*sin(theta))^2+(b*cos(theta))^2))).
        // The REAL square-root store at 0x410db6 precedes both products.
        const float radius = static_cast<float>(std::sqrt(numerator/(first*first+second*second)));
        boundary.x[index] = static_cast<float>(radius*cosine);
        boundary.y[index] = static_cast<float>(radius*sine);
    }
    const double true_area = ((static_cast<double>(rise)*span)*static_cast<double>(3.141593F))*0.25;
    double polygon_area = 0.0;
    for (std::size_t index = 1; index < 11; ++index) {
        polygon_area += ((static_cast<double>(boundary.y[index])+boundary.y[index-1])*0.5)*
            (static_cast<double>(boundary.x[index])-boundary.x[index-1]);
    }
    // FAC = REAL(sqrt(TA/(4*EA))); TA stays wide at 0x410f64.
    const float scale = static_cast<float>(std::sqrt(true_area/(polygon_area*4.0)));
    for (std::size_t index = 0; index < 11; ++index) {
        boundary.x[index] = static_cast<float>(static_cast<double>(scale)*boundary.x[index]);
        boundary.y[index] = static_cast<float>(static_cast<double>(scale)*boundary.y[index]);
    }
    return boundary;
}
ConduitBoundary right_half_boundary(std::span<const float> x, std::span<const float> y,
    const ConduitPlacement& placement) { return mirrored(x,y,placement,false); }
ConduitBoundary quadrant_boundary(std::span<const float> x, std::span<const float> y,
    const ConduitPlacement& placement) { return mirrored(x,y,placement,true); }

ConduitBoundary circular_boundary(std::size_t sides, float diameter, const ConduitPlacement& placement) {
    dimensions(diameter,diameter); placement_valid(placement);
    if (sides < 3 || sides > 1000000) { throw std::invalid_argument("Invalid circular conduit side count."); }
    ConduitBoundary boundary;
    boundary.x.reserve(sides+4); boundary.y.reserve(sides+4);
    const double theta = 6.283185307179586/static_cast<double>(sides);
    const CircleTrig theta_trig = circle_trig(theta);
    // Match the sewer area: n*R^2*sin(theta)/2 = pi*D^2/4.
    const double diameter_square = static_cast<double>(diameter)*diameter;
    const double radius = std::sqrt((diameter_square*1.57079632679489)/
        (static_cast<double>(sides)*theta_trig.sine));
    const double left_slot = -static_cast<double>(placement.slot_width)*0.5;
    const double half_diameter = static_cast<double>(diameter)*0.5;
    // ZL alone stores REAL at 0x40ee74. Radius and running angle are DOUBLE.
    const float slot_y = static_cast<float>(((radius+((1.0-theta_trig.cosine)*left_slot)/
        theta_trig.sine)+half_diameter)+placement.y_offset);
    append(boundary,left_slot+placement.x_offset,static_cast<double>(placement.slot_height)+static_cast<double>(0.01F));
    append(boundary,left_slot+placement.x_offset,placement.slot_height);
    append(boundary,left_slot+placement.x_offset,slot_y);
    double angle = theta;
    for (std::size_t index = 1; index < sides; ++index) {
        const CircleTrig direction = circle_trig(angle);
        append(boundary,placement.x_offset-radius*direction.sine,
            (radius*direction.cosine+half_diameter)+placement.y_offset);
        angle += theta;
    }
    append(boundary,placement.x_offset-left_slot,slot_y);
    append(boundary,placement.x_offset-left_slot,placement.slot_height);
    return boundary;
}
ConduitBoundary box_boundary(float rise, float span, const ConduitPlacement& placement) {
    dimensions(rise,span); placement_valid(placement);
    ConduitBoundary boundary;
    boundary.x.resize(41); boundary.y.resize(41);
    const double half_slot = static_cast<double>(placement.slot_width)*0.5;
    const float left_slot = static_cast<float>(placement.x_offset-half_slot);
    boundary.x[0] = left_slot; boundary.x[1] = left_slot; boundary.x[2] = left_slot;
    boundary.y[0] = static_cast<float>(static_cast<double>(placement.slot_height)+static_cast<double>(0.01F));
    boundary.y[1] = placement.slot_height;
    boundary.y[2] = static_cast<float>((static_cast<double>(rise)+placement.slot_width)+placement.y_offset);
    const double height = static_cast<double>(rise)-placement.slot_width;
    const float left_wall = static_cast<float>(-static_cast<double>(span)*0.5);
    for (std::size_t index = 0; index < 18; ++index) {
        // Z = (RISE-WSLOT)*(1-REAL(sqrt(i*REAL(1/17))))+ZOFF.
        // H remains wide; the square root stores REAL at 0x40f7d4.
        const float root = static_cast<float>(std::sqrt(static_cast<double>(index)*static_cast<double>(0.05882352963089943F)));
        boundary.x[index+3] = left_wall;
        boundary.y[index+3] = static_cast<float>(height*(1.0-root)+placement.y_offset);
    }
    for (std::size_t index = 0; index < 18; ++index) {
        boundary.x[index+21] = static_cast<float>(static_cast<double>(placement.x_offset)-boundary.x[20-index]);
        boundary.y[index+21] = boundary.y[20-index];
        boundary.x[20-index] = static_cast<float>(static_cast<double>(placement.x_offset)+boundary.x[20-index]);
    }
    boundary.x[39] = static_cast<float>(placement.x_offset+half_slot);
    boundary.x[40] = boundary.x[39];
    boundary.y[39] = boundary.y[2]; boundary.y[40] = boundary.y[1];
    return boundary;
}
}
