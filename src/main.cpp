#include <iostream>
#include "../include/SDL2/SDL.h"
#include "./header_files/main.hpp"
#include "./header_files/map.hpp"


Main::Main() {
    this->run_loop = true;
};

Main::~Main() {};

void Main::init(const char* title, int x_pos, int y_pos, int screen_width, int screen_height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->ptr_window = SDL_CreateWindow(title, x_pos, y_pos, screen_width, screen_height, SDL_WINDOW_SHOWN);
    this->ptr_renderer = SDL_CreateRenderer(this->ptr_window, -1, SDL_RENDERER_ACCELERATED);
    this->frame_count = 0;
    this->screen_width = screen_width;
    this->screen_height = screen_height;


    this->camera = new Camera();
    this->map = new Map(this->ptr_renderer, 15, 15, this->camera);
    this->player = new Player(this->ptr_renderer, this->camera);
}

void Main::handle_event() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            this->run_loop = false;
        }
    }

    const Uint8 * state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W]) {
        this->camera->y_direction = -3;
    }

    if (state[SDL_SCANCODE_S]) {
        this->camera->y_direction = 3;
    }

    if (state[SDL_SCANCODE_A]) {
        this->camera->x_direction = -3;
    }

    if (state[SDL_SCANCODE_D]) {
        this->camera->x_direction = 3;
    }


    if (state[SDL_SCANCODE_UP]) {
        this->player->y_dir = -1;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        this->player->y_dir = 1;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        this->player->x_dir = -1;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        this->player->x_dir = 1;
    }
}

void Main::update() {

    int map_size_x = this->map->get_size_x();
    int map_size_y = this->map->get_size_y();

    // std::cout << map_size_x << " " << this->camera->x + this->screen_width << std::endl;
    // std::cout << this->camera->x << std::endl;


    // тут у нас просчитываются координаты камеры
    int new_camera_x = this->camera->x + this->camera->x_direction;
    if (new_camera_x + this->screen_width < map_size_x && new_camera_x > 0) {
        this->camera->x = new_camera_x;
    }

    int new_camera_y = this->camera->y + this->camera->y_direction;
    if (new_camera_y + this->screen_height < map_size_y && new_camera_y > 0) {
        this->camera->y = new_camera_y;
    }

    this->camera->y_direction = 0;
    this->camera->x_direction = 0;

    // сначала надо изменить состояние камеры а затем уже состояние всех других объектов
    this->map->update();
    this->player->update();
}

void Main::render() {
    SDL_SetRenderDrawColor(this->ptr_renderer, 0, 0, 0, 0);
    SDL_RenderClear(this->ptr_renderer);

    this->map->render();
    this->player->render();

    SDL_RenderPresent(this->ptr_renderer);
    // SDL_Delay(100);

}

void Main::game_loop() {
    while(this->run_loop) {
        this->frame_count++;
        this->handle_event();
        if (this->frame_count == 200) {
            this->update();
            this->frame_count = 0;
        }
        this->render();
    }
}

void Main::clean() {
    delete this->camera;
    delete this->map;
    delete this->player;

    SDL_DestroyRenderer(this->ptr_renderer);
    SDL_DestroyWindow(this->ptr_window);
    SDL_Quit();
}


