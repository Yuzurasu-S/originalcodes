#pragma once
#include <cstdint>

#define CW  0
#define CCW 1
#define DEG2RAD (M_PI / 180.0)

class OmniControl {
public:
    void calc1(double stick_angle, int stick_value,
            uint16_t& MV1, uint8_t& MC1,
            uint16_t& MV2, uint8_t& MC2,
            uint16_t& MV3, uint8_t& MC3,
            uint16_t& MV4, uint8_t& MC4);
};
