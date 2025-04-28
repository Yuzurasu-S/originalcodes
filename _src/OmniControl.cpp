#include "OmniControl.hpp"
#include <cmath>

void OmniControl::calc1(double stick_angle, int stick_value,
                        uint16_t& MV1, uint8_t& MC1,
                        uint16_t& MV2, uint8_t& MC2,
                        uint16_t& MV3, uint8_t& MC3,
                        uint16_t& MV4, uint8_t& MC4) {
    double power_ratio = static_cast<double>(stick_value) / 17000.0;

    double angle_rad = stick_angle * DEG2RAD;
    double Vx = cos(angle_rad) * power_ratio;
    double Vy = sin(angle_rad) * power_ratio;

    double M1 = Vy + Vx;  // 左前
    double M2 = Vy - Vx;  // 右前
    double M3 = Vy + Vx;  // 右後
    double M4 = Vy - Vx;  // 左後

    auto setMotor = [](double value, uint16_t& power, uint8_t& dir) {
        if (value >= 0) {
            dir = CCW;
            power = static_cast<uint16_t>(value * 1000);
        } else {
            dir = CW;
            power = static_cast<uint16_t>(-value * 1000);
        }
    };

    setMotor(M1, MV1, MC1);
    setMotor(M2, MV2, MC2);
    setMotor(M3, MV3, MC3);
    setMotor(M4, MV4, MC4);
}
