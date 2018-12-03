#include <GLFW/glfw3.h>

namespace glfw {
    inline Context& Context::getInstance() noexcept {
        static auto THE_INSTANCE = Context();

        return THE_INSTANCE;
    }
    
    inline Context::Context() noexcept {
        _initialized = glfwInit();
    }

    inline Context::Context(Context&& other) noexcept {
        _initialized = other._initialized;
        other._initialized = false;
    }

    inline Context::~Context() noexcept {
        if (_initialized) {
            glfwTerminate();
        }
    }

    inline Context& Context::operator= (Context&& other) noexcept {
        auto tmp = _initialized;

        _initialized = other._initialized;
        other._initialized = tmp;

        return *this;
    }

    inline bool Context::isInitialized() const noexcept {
        return _initialized;
    }

    inline void Context::pollEvents() noexcept {
        glfwPollEvents();
    }

    inline void Context::setErrorCallback(GLFWerrorfun cb) noexcept {
        glfwSetErrorCallback(cb);
    }
}
