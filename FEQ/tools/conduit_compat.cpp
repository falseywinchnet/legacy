// Connect original-verified conduit boundaries to the research utility.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <feq/conduit_boundary.hpp>
#include <span>
#include <stdexcept>

extern "C" void feq_conduit_boundary(int kind, int count, float rise, float span,
    float slot_width, float slot_height, float x_offset, float y_offset,
    const float* input_x, const float* input_y, int* output_count, float* x, float* y) {
    if (count < 0) { throw std::invalid_argument("Negative conduit boundary extent."); }
    const feq::ConduitPlacement placement{slot_width,slot_height,x_offset,y_offset};
    feq::ConduitBoundary result;
    if (kind == 0) { result = feq::ellipse_quadrant(rise,span); }
    else if (kind == 1) { result = feq::circular_boundary(static_cast<std::size_t>(count),rise,placement); }
    else if (kind == 2) { result = feq::box_boundary(rise,span,placement); }
    else if (kind == 3 || kind == 4) {
        const std::span<const float> input_x_values(input_x,static_cast<std::size_t>(count));
        const std::span<const float> input_y_values(input_y,static_cast<std::size_t>(count));
        result = kind == 3 ? feq::right_half_boundary(input_x_values,input_y_values,placement) :
            feq::quadrant_boundary(input_x_values,input_y_values,placement);
    } else { throw std::invalid_argument("Unknown conduit boundary constructor."); }
    *output_count = static_cast<int>(result.x.size());
    for (std::size_t index = 0; index < result.x.size(); ++index) {
        x[index] = result.x[index]; y[index] = result.y[index];
    }
}
