#pragma once
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "CommonFunction.h"
class BaseObject
{
protected:
	SDL_Texture* p_object_;// con trỏ dùng để vẽ vật lên màn hình
	SDL_Rect* rect_;// con trỏ chỉ đến tọa độ, chiều rộng ,chiều cao của object
public:
	BaseObject();
	~BaseObject();
	void setRect(int& a, int& b)// khởi tạo giá trị cho rect
	{
		rect_->x = a;
		rect_->y = b;
	}
	SDL_Rect* getRect()// lấy rect ra
	{
		return rect_;
	}
	SDL_Texture* getTexture()
	{
		return p_object_;
	}
	virtual bool loadImg(std::string path, SDL_Renderer* screen);// load ảnh lên màn hình
	void render(SDL_Renderer* des, const SDL_Rect* clip = NULL);// 
	void free();// xóa màn hình khi xong việc
};
#endif