#pragma once

#include <stdexcept>
#include <string>

#include <GLFW/glfw3.h>
#include "GLFW/Monitor.hpp"
#include "GLFW/WindowHints.hpp"

namespace glfw {
    class Window {
        GLFWwindow * _window;

        Window(const Window&) = delete;
        Window& operator= (const Window&) = delete;

    public:
        static void setHints(const WindowHints& hints);

        Window() noexcept:
            _window(nullptr) {}

        Window(int width, int height, const std::string& title, const Monitor * pMonitor = nullptr, const Window * pShared = nullptr);

        Window(Window&& other) noexcept;

        ~Window() noexcept;

        Window& operator= (Window&& other) noexcept;

        Window& operator= (GLFWwindow* pWindow) noexcept;

        operator GLFWwindow*() const noexcept;

        GLFWwindow* getHandle() const noexcept;

        void focus() noexcept;

        void getFramebufferSize(int& width, int& height) const noexcept;

        void getFrameSize(int& left, int& top, int& right, int& bottom) const noexcept;

        Monitor getMonitor() const noexcept;

        void getPosition(int& xPos, int& yPos) const noexcept;

        void getSize(int& width, int& height) const noexcept;

        void* getUserPointer() const noexcept;

        void hide() noexcept;

        void iconify() noexcept;

        void maximize() noexcept;

        void restore() noexcept;

        void setFramebufferSizeCallback(GLFWframebuffersizefun cb) noexcept;

        void setAspectRatio(int numerator, int denominator) noexcept;

        void setCloseCallback(GLFWwindowclosefun cb) noexcept;

        void setFocusCallback(GLFWwindowfocusfun cb) noexcept;

        void setIconifyCallback(GLFWwindowiconifyfun cb) noexcept;

        void setMonitor(const Monitor& monitor, int xpos, int ypos, int width, int height, int refreshRate = GLFW_DONT_CARE) noexcept;

        void setPosition(int xpos, int ypos) noexcept;

        void setPositionCallback(GLFWwindowposfun cb) noexcept;

        void setRefreshCallback(GLFWwindowrefreshfun cb) noexcept;

        void setShouldClose(bool value) noexcept;

        void setSize(int width, int height) noexcept;

        void setSizeCallback(GLFWwindowsizefun cb) noexcept;

        void setSizeLimits(int minWidth, int minHeight, int maxWidth, int maxHeight) noexcept;

        void setTitle(const std::string& title) noexcept;

        void setUserPointer(void * ptr) noexcept;

        void show() noexcept;

        void swapBuffers() noexcept;

        bool shouldClose() const noexcept;

        void makeContextCurrent() noexcept;
    };
}

#include "GLFW/private/Window.inl"
