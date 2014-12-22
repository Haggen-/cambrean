#include "main.h"

static void error_callback(int error, const char* desc) {
    fputs(desc + error, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
        printf("EXITED");
    }
}

static void window_closecallback(GLFWwindow* window) {
    printf("CLOSING!");
}

void GameLoop() {
    double timeLastRendered = glfwGetTime();
    double deltaTime = timeLastRendered - glfwGetTime();
    // Handle Keys
    // Update objects.
    // Render, swap buffer
    timeLastRendered = glfwGetTime();
}

int main(int argc, char* argv[]) {
    GLFWwindow *window;
    double glfwTime = glfwGetTime();
    glfwSetErrorCallback(error_callback);
    if(!glfwInit()) {
        printf("Initiation failed.");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(640, 480, "Testwindow", NULL, NULL);
    glfwSetWindowCloseCallback(window, window_closecallback);
    if(!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    GameEngine::Renderer *renderer = new GameEngine::Renderer();

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents(); // TODO: Create EventHandler
        // TODO: Create GameLogic Updater
        renderer->Render(window, NULL);
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);
}