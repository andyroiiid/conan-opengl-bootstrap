#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[]) {
    GLFWwindow *window;

    if (!glfwInit()) {
        fprintf(stderr, "failed to initialize glfw\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(640, 480, "conan-opengl-bootstrap", nullptr, nullptr);
    if (!window) {
        fprintf(stderr, "failed to create glfw window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "failed to initialize glad\n");
        glfwTerminate();
        return -1;
    }

    printf(
            "OpenGL version: %s, GLSL version: %s",
            glGetString(GL_VERSION),
            glGetString(GL_SHADING_LANGUAGE_VERSION)
    );

    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.4f, 0.8f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}