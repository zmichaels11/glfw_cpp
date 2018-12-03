#include <iostream>

#include "GLFW/Window.hpp"

static void errorcb(int error, const char* desc) {
    std::cerr << "Error: " 
        << std::dec << error 
        << " (" << desc << ")"
        << std::endl;
}

int main(int argc, char** argv) {
    auto& ctx = glfw::Context::getInstance();

    ctx.setErrorCallback(errorcb);

    auto hints = glfw::WindowHints::defaults();

    glfw::Window::setHints(hints);

    auto window = glfw::Window(640, 480, "Hello World!");

    window.makeContextCurrent();
    window.show();

    glClearColor(1.0F, 0.0F, 0.0F, 1.0F);

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        ctx.pollEvents();
        window.swapBuffers();
    }

    return 0;
}
