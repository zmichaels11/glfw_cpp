#pragma once

#include <string>

#include "GLFW/ButtonState.hpp"
#include "GLFW/Hat.hpp"
#include "GLFW/Joystick.hpp"

namespace glfw {
    class Gamepad {
        int _id;

    public:
        struct State {
            union { 
                ButtonState A;
                ButtonState CROSS; 
            };

            union { 
                ButtonState B; 
                ButtonState CIRCLE;
            };

            union {
                ButtonState X;
                ButtonState SQUARE;
            };

            union {
                ButtonState Y; 
                ButtonState TRIANGLE;
            };

            ButtonState leftBumper, rightBumper;
            ButtonState back, start, guide;
            ButtonState leftThumb, rightThumb;
            Hat dpad;
            float axisLeftX, axisLeftY;
            float axisRightX, axisRightY;
            float axisLeftTrigger,axisRightTrigger;
        };

        static void updateMappings(const std::string& path) noexcept;

        Gamepad(const Joystick joystick) noexcept: 
            _id(joystick.getId()) {}

        int getId() const noexcept;

        operator int() const noexcept;

        std::string getName() const noexcept;

        State getState() const noexcept;
    };
}

#include "GLFW/private/Gamepad.inl"
