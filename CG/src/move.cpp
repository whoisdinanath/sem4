#include <SDL2/SDL.h>
#include <math.h>

// Structure to represent a 2D point
bool running = true;
struct Point
{
    int x, y;
};

void drawBall(SDL_Renderer *renderer, struct Point center, int radius, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, center.x + dx, center.y + dy);
            }
        }
    }
}

void drawGround(SDL_Renderer *renderer, int y, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, 0, y, 640, y); // assuming window width is 640
}

void projectileMotion(float u, float angle, float g, struct Point *p, SDL_Renderer *renderer)
{
    // escape key
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
        }
    }
    float t = 0.0;
    float ux = u * cos(angle * M_PI / 180.0); // convert angle to radians
    float uy = u * sin(angle * M_PI / 180.0); // convert angle to radians

    while (t < 100 && running && p->y <= 400) // added a maximum time to prevent infinite loop
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        if (p->y < 400)
        {
            p->x = ux * t;
            p->y = uy * t + 0.5 * g * t * t;
        }
        t += 0.1;
        SDL_Delay(100);
        drawBall(renderer, *p, 10, {255, 0, 0, 255});
        drawGround(renderer, 400, {255, 255, 255, 255});
        SDL_RenderPresent(renderer);
    }
}

// main function
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL2 Projectile Motion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Initial coordinates of the ball
    struct Point originalBall = {0, 0};
    drawBall(renderer, originalBall, 10, {255, 0, 0, 255});

    // Projectile parameters
    float u = 20;
    float angle = 45.0;
    float g = 5;

    // Applying projectile motion to the ball
    projectileMotion(u, angle, g, &originalBall, renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}