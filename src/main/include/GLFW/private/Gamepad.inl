namespace glfw {
    inline std::string Gamepad::getName() const noexcept {
        return glfwGetGamepadName(_id);
    }

    inline Gamepad::State Gamepad::getState() const noexcept {
        GLFWgamepadstate state;

        glfwGetGamepadState(_id, &state);

        auto out = Gamepad::State {};
        out.A = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_A]);
        out.B = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_B]);
        out.X = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_X]);
        out.Y = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_Y]);
        out.leftBumper = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_LEFT_BUMPER]);
        out.rightBumper = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER]);
        out.back = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_BACK]);
        out.start = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_START]);
        out.guide = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_GUIDE]);
        out.leftThumb = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB]);
        out.rightThumb = static_cast<ButtonState> (state.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB]);
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
