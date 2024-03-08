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
        /** chassis_control **/
        fp32 vx_set = 0.f;
        fp32 vy_set = 0.f;
        fp32 wz_set = 0.f;

        /** gimbal_control **/
        fp32 v_yaw_set = 0.f;
        fp32 v_pitch_set = 0.f;

        /** IMU **/
        fp32 ins_yaw = 0.f;
        fp32 ins_pitch = 0.f;
        fp32 ins_roll = 0.f;

        /** other **/
        fp32 chassis_relative_angle = 0.f;
        uint8_t mode = Types::ROBOT_MODE::ROBOT_NOT_FOLLOW;
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
