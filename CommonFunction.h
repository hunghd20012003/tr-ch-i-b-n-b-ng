#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include <Windows.h>
#include <string>//khai báo thư viên string
#include <SDL.h>//khai báo thư viện sdl
#include<SDL_image.h>//khai báo thư viện ảnh sdl
static SDL_Window* g_window=NULL;//con trỏ quản lí cửa sổ
static SDL_Renderer* g_screen = NULL;//con trỏ quản lí màn hình
static SDL_Event* g_event = NULL;// con trỏ này sẽ quản lí các cú click chuột, bàn phims để điều khiển nhân vật
const int SCREEN_WIDTH = 1280;//khai báo chiều dài cửa sổ
const int SCREEN_HEIGHT= 640;//khai báo chiều rộng cửa sổ
const int SCREEN_BBP = 32;//số độ bixel của màn hình
const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_COLOR_DRAW = 255;
#endif 
