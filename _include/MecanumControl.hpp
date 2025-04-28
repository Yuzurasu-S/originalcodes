#ifndef MECANUM_CONTROL_HPP
#define MECANUM_CONTROL_HPP

#include <cstdint>

class MecanumControl {
public:
    static const int CW = 0;
    static const int CCW = 1;
    static constexpr double DEG2RAD = 3.14159265358979323846 / 180.0;

    MecanumControl(); // コンストラクタ（必要なら）

    void calc(double stick_angle, int stick_value,
            uint16_t& MV1, uint8_t& MC1,
            uint16_t& MV2, uint8_t& MC2,
            uint16_t& MV3, uint8_t& MC3,
            uint16_t& MV4, uint8_t& MC4);
};

#endif // MECANUM_CONTROL_HPP
