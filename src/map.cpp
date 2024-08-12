#include <iostream>
#include "../include/SDL2/SDL.h"
#include "./header_files/map.hpp"
#include "./header_files/texture_manager.hpp"
#include "./header_files/camera.hpp"


Map::Map(SDL_Renderer* ptr_renderer, int row, int col, Camera* camera) {
    this->ptr_renderer = ptr_renderer;
    this->row = row;
    this->col = col;
    this->camera = camera;

    this->matrix = new int*[this->row];

    for (int i = 0; i < this->row; i++) {
        this->matrix[i] = new int[this->col];
    }

    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            this->matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < this->row; i++) {
        this->matrix[0][i] = 2;
        this->matrix[this->row - 1][i] = 2;
        this->matrix[i][0] = 2;
        this->matrix[i][this->col - 1] = 2;

    }

    this->matrix[5][5] = 1;

    this->tiles = Texture_Manager::load_texture("./src/assets/tiles.png", this->ptr_renderer);
}

Map::~Map() {}


void Map::update() {}

void Map::render() {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {

            this->src_rect.x = this->matrix[i][j] * 64;
            this->src_rect.y = 0;
            this->src_rect.h = 64;
            this->src_rect.w = 64;

            this->dest_rect.x = (j * 64) - this->camera->x;
            this->dest_rect.y = (i * 64) - this->camera->y;
            this->dest_rect.h = 64;
            this->dest_rect.w = 64;

            SDL_RenderCopy(this->ptr_renderer, this->tiles, &src_rect, &dest_rect);
        }
    }
}

int Map::get_size_x() {
    return this->row * 64;
}


int Map::get_size_y() {
    return this->col * 64;
}

