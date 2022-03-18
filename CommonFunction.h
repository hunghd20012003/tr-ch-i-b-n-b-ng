#pragma once
#ifndef _COMMON_FUNCTION_H_
#define _COMMON_FUNCTION_H_
#include<Windows.h>
#include<string>
#include<SDL.h>
static SDL_Window* g_window= NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event* g_event = NULL;
//Screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BBP = 32;
const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 255;


#endif
