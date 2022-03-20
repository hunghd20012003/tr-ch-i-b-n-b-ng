#pragma once
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_
#include "CommonFunction.h"
#include "BaseObject.h"
class MainObject
{
public:
	MainObject();
	~MainObject();
	enum WalkType
	{
		walk_right_ = 0,
	walk_left_ = 1,
	};
	 bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandleInputAction(SDL_Event event, SDL_Renderer* screen);
	void Set_clips();
private:
	float x_val_;
	float y_val_;
	float x_pos_;
	float y_pos_;
	int width_frame_;
	int height_frame_;
	SDL_Rect frame_clip_[8];//trang thái của đối tượng
	Input input_type_;
	int frame_;
	int status_;//trang thái di truyển sang trái hay phải
};
#endif
