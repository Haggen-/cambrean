#ifndef RENDERER_H
#define RENDERER_H
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Block.h"

namespace GameEngine {
    class Renderer {
    public:
        Renderer();
        void Initialize();
        void Render(GLFWwindow *window, Game::Block* block);
    private:
        GLfloat projectionScale = 1.f;
    };
}

#endif