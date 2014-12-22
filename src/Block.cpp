#include "Block.h"

Game::Block::Block() {
    this->height = 0;
    this->width = 0;
    this->position_x = 0;
    this->position_y = 0;
}

void Game::Block::SetWidth(float width) {
    this->width = width;
}

void Game::Block::SetHeight(float height) {
    this->height = height;
}

void Game::Block::SetPosition(float x, float y) {
    this->position_x = x;
    this->position_y = y;
}

void Game::Block::SetColor(float red, float green, float blue) {
    this->color_red = red;
    this->color_green = green;
    this->color_blue = blue;
}