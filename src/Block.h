#ifndef BLOCK_H
#define BLOCK_H

namespace Game {
    class Block {
    public:
        Block();
        void SetColor(float, float, float);
        void SetPosition(float, float);
        void SetHeight(float);
        void SetWidth(float);

        float GetColorBlue() { return this->color_blue; };
        float GetColorRed() { return this->color_red; };
        float GetColorGreen() { return this->color_green; };
        float GetPositionX() { return this->position_x; };
        float GetPositionY() { return this->position_y; };
        float GetWidth() { return this->width; };
        float GetHeight() { return this->height; };
    private:
        float color_red, color_green, color_blue;
        float position_x, position_y, height, width;
    };
}

#endif