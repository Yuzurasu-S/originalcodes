#include "MecanumControl.hpp"
#include <cmath>

// MecanumControl::MecanumControl() {
//     // 必要なら初期化処理を書く
// }

void MecanumControl::calc(double stick_angle, int stick_value,
                        uint16_t& MV1, uint8_t& MC1,
                        uint16_t& MV2, uint8_t& MC2,
                        uint16_t& MV3, uint8_t& MC3,
                        uint16_t& MV4, uint8_t& MC4) {
    double power_ratio = static_cast<double>(stick_value) / 17000.0;
    double phi = 90.0 - stick_angle;
    double Vx = cos(phi * DEG2RAD) * power_ratio;
    double Vy = sin(phi * DEG2RAD) * power_ratio;
    double M1 = Vy - Vx;
    double M2 = Vy + Vx;
    double M3 = Vy + Vx;
    double M4 = Vy - Vx;

    auto setMotor = [](double value, uint16_t& power, uint8_t& dir) {
        if (value >= 0) {
            dir = CW;
            power = static_cast<uint16_t>(value * 1000);
        } else {
            dir = CCW;
            power = static_cast<uint16_t>(-value * 1000);
        }
    };

    setMotor(M1, MV1, MC1);
    setMotor(M2, MV2, MC2);
    setMotor(M3, MV3, MC3);
    setMotor(M4, MV4, MC4);
}
