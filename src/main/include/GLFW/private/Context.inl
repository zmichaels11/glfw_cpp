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

    inline bool Context::extensionSupported(const std::string& ext) const noexcept {
        return glfwExtensionSupported(ext.c_str());
    }

    inline int Context::getError(const char ** pDescription) const noexcept {
        return glfwGetError(pDescription);
    }

    inline std::string Context::getKeyName(int key, int scancode) const noexcept {
        return glfwGetKeyName(key, scancode);
    }

    inline int Context::getKeyScancode(int key) const noexcept {
        return glfwGetKeyScancode(key);
    }

    inline GLFWglproc Context::getProcAddress(const std::string& procname) const noexcept {
        return glfwGetProcAddress(procname.c_str());
    }

    inline void Context::postEmptyEvent() noexcept {
        glfwPostEmptyEvent();
    }

    inline double Context::getTime() const noexcept {
        return glfwGetTime();
    }

    inline std::uint64_t Context::getTimerFrequency() const noexcept {
        return glfwGetTimerFrequency();
    }

    inline std::uint64_t Context::getTimerValue() const noexcept {
        return glfwGetTimerValue();
    }

    inline void Context::setTime(double time) noexcept {
        glfwSetTime(time);
    }

    inline void Context::swapInterval(int interval) noexcept {
        glfwSwapInterval(interval);
    }

    void Context::waitEvents() noexcept {
        glfwWaitEvents();
    }

    void Context::waitEventsTimeout(double timeout) noexcept {
        glfwWaitEventsTimeout(timeout);
    }
}
