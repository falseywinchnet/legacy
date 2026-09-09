// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_CHANNEL_RATING_HPP
#define FEQ_CHANNEL_RATING_HPP

namespace feq {
// FRFCHN retains the upstream elevation across profile/root calculations.
double channel_upstream_elevation(float head, float datum);

// Both free-flow exits subtract the wide downstream elevation before the
// REAL output store. The depth is the stored downstream section depth.
float channel_free_drop(double upstream_elevation, float downstream_depth,
    float downstream_bed);

// CHNTAB's partial free-drop fraction for one-based index 1..count.
// Require count >= 2 and a finite positive power.
float channel_partial_free_drop(int index, int count, float power);
}
#endif
