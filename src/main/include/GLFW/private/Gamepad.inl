namespace glfw {
    inline std::string Gamepad::getName() const noexcept {
        return glfwGetGamepadName(_id);
    }

    inline Gamepad::State Gamepad::getState() const noexcept {
        GLFWgamepadstate state;

        glfwGetGamepadState(_id, &state);

        auto out = Gamepad::State {};
        out.A = state.buttons[GLFW_GAMEPAD_BUTTON_A];
        out.B = state.buttons[GLFW_GAMEPAD_BUTTON_B];
        out.X = state.buttons[GLFW_GAMEPAD_BUTTON_X];
        out.Y = state.buttons[GLFW_GAMEPAD_BUTTON_Y];
        out.leftBumper = state.buttons[GLFW_GAMEPAD_LEFT_BUMPER];
        out.rightBumper = state.buttons[GLFW_GAMEPAD_RIGHT_BUMPER];
        out.back = state.buttons[GLFW_GAMEPAD_BUTTON_BACK];
        out.start = state.buttons[GLFW_GAMEPAD_BUTTON_START];
        out.guide = state.buttons[GLFW_GAMEPAD_BUTTON_GUIDE];
        out.leftThumb = state.buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB];
        out.rightThumb = state.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB];
        out.dpad = Hat::CENTERED;
        
        if (state.buttons[GLFW_GAMEPAD_BUTTON_DPAD_UP]) {
            out.dpad |= Hat::UP;
        } else if (state.buttons[GLFW_GAMEPAD_BUTTON_DPAD_DOWN]) {
            out.dpad |= Hat::DOWN;
        }

        if (state.buttons[GLFW_GAMEPAD_BUTTON_DPAD_LEFT]) {
            out.dpad |= Hat::LEFT;
        } else if (state.buttons[GLFW_GAMEPAD_BUTTON_DPAD_DOWN]) {
            out.dpad |= Hat::RIGHT;
        }

        out.axisLeftX = state.axes[GLFW_GAMEPAD_AXIS_LEFT_X];
        out.axisLeftY = state.axes[GLFW_GAMEPAD_AXIS_LEFT_Y];
        out.axisRightX = state.axes[GLFW_GAMEPAD_AXIS_RIGHT_X];
        out.axisRightY = state.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];
        out.axisLeftTrigger = state.axes[GLFW_GAMEPAD_AXIS_LEFT_TRIGGER];
        out.axisRightTrigger = state.axes[GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER];

        return out;
    }

    inline int Gamepad::getId() const noexcept {
        return _id;
    }

    inline Gamepad::operator int() const noexcept {
        return _id;
    }    
}
