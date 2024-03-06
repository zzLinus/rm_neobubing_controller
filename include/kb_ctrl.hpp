#ifndef __KB_CTRL__
#define __KB_CTRL__

#include <chrono>
#include <cmath>
#include <memory>

#include "ramp_controller.hpp"
#include "types.hpp"

namespace Input
{
    class Kb_ctrl
    {
       public:
        Kb_ctrl();
        ~Kb_ctrl();
        fp32 event_handler(std::shared_ptr<Types::Robot_set> p_robot_set, Types::Kb_event event, fp32 spdslider);

       public:
        Ramp::Ramp_ctrller *kb_vx_ramp;  // 用于键盘控制的斜波函数
        Ramp::Ramp_ctrller *kb_vy_ramp;  // 用于键盘控制的斜波函数

       private:
    };
}  // namespace Input

#endif
