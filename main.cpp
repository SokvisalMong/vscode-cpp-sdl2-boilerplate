#include <SDL2/SDL.h>
#include <stdio.h>

#define WIDTH 1280
#define HEIGHT 720

int main(int args, char* argc[]){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        printf("SDL_Init failed. ERROR: %s\n", SDL_GetError());
    }

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    
    bool running = true;
    while(running){
        SDL_Event evnt;
        while(SDL_PollEvent(&evnt)){
            switch(evnt.type){
                case SDL_QUIT:
                    running = false; break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}