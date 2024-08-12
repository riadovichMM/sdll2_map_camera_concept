#pragma once
#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2_image/SDL_image.h"
#include "./camera.hpp"


class Map {
    public:
        Map(SDL_Renderer* ptr_renderer, int row, int col, Camera* camera);
        ~Map();


        void update();
        void render();

        int get_size_x();
        int get_size_y();

    private:
        SDL_Renderer* ptr_renderer;
        int **matrix;
        SDL_Texture* tiles;
        int row;
        int col;
        Camera* camera;
        SDL_Rect src_rect;
        SDL_Rect dest_rect;
};

