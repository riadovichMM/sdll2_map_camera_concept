#pragma once
#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2_image/SDL_image.h"
#include "./camera.hpp"


class Player {
    public:
        int x = 0;
        int y = 0;
        int x_dir;
        int y_dir;
        SDL_Texture* player_texture;
        SDL_Renderer* ptr_renderer;
        Camera* camera;
        SDL_Rect src_rect;
        SDL_Rect dest_rect;


        Player(SDL_Renderer* ptr_renderer, Camera* camera);
        ~Player();

        void update();
        void render();
};

