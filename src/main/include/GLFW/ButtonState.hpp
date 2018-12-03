#pragma once

#include <GLFW/glfw3.h>

namespace glfw {
    enum class ButtonState : int {
        PRESS = GLFW_PRESS,
        RELEASE = GLFW_RELEASE
    };
}
