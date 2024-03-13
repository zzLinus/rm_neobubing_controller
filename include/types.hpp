#ifndef __TYPES__
#define __TYPES__
#include <linux/can.h>

#include <cstdint>

#include "string"

// NOTE: defines and type defines
typedef signed char int8_t;
typedef signed short int int16_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned char bool_t;
typedef float fp32;
typedef double fp64;

namespace Types
{

    enum ROBOT_MODE
    {
        ROBOT_NO_FORCE,
        ROBOT_FOLLOW_GIMBAL,
        ROBOT_NOT_FOLLOW
    };

    struct Robot_set
    {
        /*       导航部分       */
        uint8_t header;
        // 线速度 m/s
        float vx_set;
        float vy_set;
        // 旋转角速度 rad/s
        float wz_set;
        // 欧拉角
        float yaw_set;
        float pitch_set;
        Types::ROBOT_MODE mode = Types::ROBOT_MODE::ROBOT_NO_FORCE;
    } __attribute__((packed));

    enum Kb_event
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT,
        SPIN_R,
        SPIN_L,
        STOP_X,
        STOP_Y,
    };
}  // namespace Types
#endif
