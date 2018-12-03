namespace glfw {
    inline Joystick::operator int() const noexcept {
        return _id;
    }   
    
    inline int Joystick::getId() const noexcept {
        return _id;
    }

    inline bool Joystick::isPresent() const noexcept {
        return glfwJoystickPresent(_id);
    }

    inline std::vector<ButtonState> Joystick::getButtons() const noexcept {
        auto out = std::vector<ButtonState> ();
        int count;
        auto buttons = glfwGetJoystickButtons(_id, &count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(static_cast<ButtonState> (buttons[i]));
        }

        return out;
    }

    inline std::vector<float> Joystick::getAxes() const noexcept {
        auto out = std::vector<float> ();
        int count;
        auto axes = glfwGetJoystickAxes(_id, &count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(axes[i]);
        }

        return out;
    }

    inline std::string Joystick::getName() const noexcept {
        return glfwGetJoystickName(_id);
    }

    inline std::string Joystick::getGUID() const noexcept {        
        return glfwGetJoystickGUID(_id);
    }

    inline std::vector<Hat> Joystick::getHats() const noexcept {
        auto out = std::vector<Hat> ();
        int count;
        auto hats = glfwGetJoystickHats(_id, &count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(static_cast<Hat> (hats[i]));
        }

        return out;
    }

    inline void Joystick::setUserPointer(void * ptr) noexcept {
        glfwSetJoystickUserPointer(_id, ptr);
    }

    inline void * Joystick::getUserPointer() const noexcept {
        return glfwGetJoystickUserPointer(_id);
    }

    inline bool Joystick::isGamepad() const noexcept {
        return glfwJoystickIsGamepad(_id);
    }    
}