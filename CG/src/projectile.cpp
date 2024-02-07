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
    SDL_RenderDrawLine(renderer, 0, y, 1000, y); // assuming window width is 640
}

void projectileMotion(float u, float angle, float g, struct Point *p, SDL_Renderer *renderer)
{
    int i = 0;
    float t = 0.0;
    int horizontal_range = (u * u * sin(2 * angle * M_PI / 180.0)) / g;
    float ux = u * cos(angle * M_PI / 180.0); // convert angle to radians
    float uy = u * sin(angle * M_PI / 180.0); // convert angle to radians
    printf("ux = %f, uy = %f\n", ux, uy);
    int x_0 = p->x;
    int y_0 = p->y;
    printf("x = %d, y = %d\n", p->x, p->y);

    while (i < 500) // added a maximum time to prevent infinite loop
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_Delay(100);
        drawBall(renderer, *p, 10, {255, 0, 0, 255});
        drawGround(renderer, 800, {255, 255, 255, 255});
        SDL_RenderPresent(renderer);

        t += 0.1;
        if (p->x < (x_0 + horizontal_range - 5))
        {
            p->x = x_0 + ux * t;
            p->y = y_0 - (uy * t - 0.5 * g * t * t);
            printf("x = %d, y = %d\n", p->x, p->y);
        }
        else if (p->x >= (x_0 + horizontal_range - 5) && p->x <= (x_0 + horizontal_range + 5))
        {

            printf("horizontal range pugyooooo\n");
            x_0 = p->x;
            y_0 = p->y;
            t = 0.0;
            u = 0.8 * u;
            ux = u * cos(angle * M_PI / 180.0); // convert angle to radians
            uy = u * sin(angle * M_PI / 180.0); // convert angle to radians
            horizontal_range = (u * u * sin(2 * angle * M_PI / 180.0)) / g;
            printf("ux = %f, uy = %f\n", ux, uy);
            printf("x = %d, y = %d\n", p->x, p->y);
        }
        else if (p->x > (x_0 + horizontal_range + 5))
        {
            p->x = x_0 + ux * t;
            p->y = y_0 - (uy * t - 0.5 * g * t * t);
            printf("x = %d, y = %d\n", p->x, p->y);
        }

        i++;
    }
}

// main function
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL2 Projectile Motion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Initial coordinates of the ball
    struct Point originalBall = {10, 800};
    drawBall(renderer, originalBall, 10, {255, 0, 0, 255});

    // Projectile parameters
    float u = 50;
    float angle = 60.0;
    float g = 10;

    // Applying projectile motion to the ball
    projectileMotion(u, angle, g, &originalBall, renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}