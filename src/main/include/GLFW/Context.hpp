#pragma once

namespace glfw {
    class Context {
        bool _initialized;

        Context() noexcept;
        Context(const Context&) = delete;
        Context(Context&& other) noexcept;
        
        Context& operator= (const Context&) = delete;
        Context& operator= (Context&& other) noexcept;

    public:
        ~Context() noexcept;

        static Context& getInstance() noexcept;

        bool isInitialized() const noexcept;

        void pollEvents() noexcept;

        void setErrorCallback(GLFWerrorfun cb) noexcept;
    };
}

#include "GLFW/private/Context.inl"
