class Solution {
public:
    double angleClock(int hour, int minutes) {
        double pos_h = hour % 12;
        double pos_m = (minutes * 1.0 / 60) * 12;
        double delta_h = pos_m / 12;
        double angle = abs(pos_m - (pos_h + delta_h)) / 12 * 360;
        return min(360 - angle, angle);
    }
};


// -- degree
// 1 round = 360
// 1 gap = 360 / 12 = 30
// 1 unit = 30 / 5 = 6

// -- time (minutes)
// 1 round = 60
// 1 gap = 60 / 12 = 5
// 1 unit = 5 / 5 = 1

// hours = 12 -> pos_h = 12 % 12 = 0
// minutes = 30 -> pos_m = (30 / 60) * 12 = 6
// delta = pos_m / 12 = 6 / 12 = 0.5

// angle = (pos_m - pos_h + delta) / 12 * 360 = (6 - (0 + 0.5)) / 12 * 360
// result = max(360 - angle, angle)

// hours = 4
// minutes = 50

