#include"CommonFunction.h"
#include"BaseObject.h"
BaseObject g_background;
bool initData()//
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0)
	{
		return false;
	}
	else
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		g_window = SDL_CreateWindow("bubble Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (g_window == NULL)
		{
			success = false;
		}
		else
		{
			g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
			if (g_screen == NULL)
			{
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(g_screen, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B, RENDER_COLOR_DRAW);
				int imgFlags = IMG_INIT_PNG;
				if (!(SDL_Init(imgFlags) && imgFlags))
				{
					success = false;
				}
				
			}
		}
	}
	return success;
}
bool loadBackground()
{
	bool ret = g_background.loadImg("z3295614631731_2aa8cbfed34d2cc3ab079e39ace2c698.jpg", g_screen);
	if (ret == false)
	{
		return false;
	}
	return true;
}
void close()
{
	g_background.free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();
}
int main(int argc, char* argv[])
{
	if (initData() == false)
	{
		return -1;
	}
	printf("abc");


	if (loadBackground() == false)
	{
		return -1;
	}
	bool isQuit = false;
	while (isQuit == false)
	{
		while (SDL_PollEvent(g_event) != 0)
		{
			if (g_event->type = SDL_QUIT)
			{
				isQuit = true;
			}
			SDL_SetRenderDrawColor(g_screen, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW);
			SDL_RenderClear(g_screen);
			g_background.render(g_screen, NULL);
			SDL_RenderPresent(g_screen);
		}
	}
	close();
	return 0;
}