#include <iostream>
#include "../include/SDL2/SDL.h"
#include "../include/SDL2_image/SDL_image.h"
#include "./header_files/player.hpp"
#include "./header_files/texture_manager.hpp"

Player::Player(SDL_Renderer* ptr_renderer, Camera* camera) {
    this->ptr_renderer = ptr_renderer;
    this->camera = camera;

    this->player_texture = Texture_Manager::load_texture("./src/assets/player.png", this->ptr_renderer);
    
    this->x = 100;
    this->y = 100;
    this->src_rect.h = 32;
    this->src_rect.w = 32;
    this->src_rect.x = 0;
    this->src_rect.y = 0;

    this->dest_rect.h = 32;
    this->dest_rect.w = 32;
    this->dest_rect.x = this->x;
    this->dest_rect.y = this->y;

    this->x_dir = 0;
    this->y_dir = 0;
}

Player::~Player() {}

void Player::update() {
    this->x = this->x + this->x_dir;
    this->y = this->y + this->y_dir;
    this->x_dir = 0;
    this->y_dir = 0;

    this->dest_rect.x = this->x - this->camera->x;
    this->dest_rect.y = this->y - this->camera->y;
}

void Player::render() {
    SDL_RenderCopy(this->ptr_renderer, this->player_texture, nullptr, &this->dest_rect);
}

