#pragma once

#include <GLFW/glfw3.h>

namespace glfw {
    enum class KeyState : int {
        PRESS = GLFW_PRESS,
        RELEASE = GLFW_RELEASE,
        REPEAT = GLFW_REPEAT
    };
}
