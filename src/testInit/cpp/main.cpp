#include <iostream>

#include "GLFW/glfw3.hpp"

int main(int argc, char** argv) {
    auto& ctx = glfw::Context::getInstance();
    
    ctx.setErrorCallback([] (int err, const char * desc) {
        std::cerr << "Error: " 
                    << std::dec << err 
                    << " (" << desc << ")"
                    << std::endl;
    });

    auto hints = glfw::WindowHints::defaults();

    glfw::Window::setHints(hints);

    auto window = glfw::Window(640, 480, "Hello World!");

    window.setCharCallback([] (auto pWindow, auto key) {
        std::cout << "Key: 0x" << std::hex << key << std::endl;
    });

    window.setKeyCallback([] (auto pWindow, auto key, auto scancode, auto action, auto mods) {
        auto window = glfw::Window(pWindow);

        if (GLFW_RELEASE == action && GLFW_KEY_ESCAPE == key) {
            window.setShouldClose(true);
        }
    });

    window.makeContextCurrent();
    window.show();

    glClearColor(1.0F, 0.0F, 0.0F, 1.0F);

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        window.swapBuffers();
        ctx.pollEvents();
    }

    return 0;
}
