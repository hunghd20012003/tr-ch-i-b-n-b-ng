#include "BaseObject.h"
BaseObject::BaseObject()// khơi tạo không tham số cho các biển protected trong hàm Baseobject.h
{
	p_object_ = NULL;
	rect_->x = 0;
	rect_->y = 0;
	rect_->h = 0;
	rect_->w = 0;

}
BaseObject::~BaseObject()//khởi tạo không tham số cho hàm hủy
{

}
 bool BaseObject::loadImg(std::string path, SDL_Renderer* screen)//viết đè hàm loadImg
{
	SDL_Texture* new_texture = NULL;//khơi tạo con trỏ dùng để vẽ lên màn hình 
	SDL_Surface* load_surface = IMG_Load(path.c_str());//load ảnh lên màn hình ,do hàm IMG_Load dùng biến dạng tra nên ta phải chuyển path từ dạng string sang char thông qua c_str()
	if (load_surface != NULL){
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format,COLOR_KEY_R,COLOR_KEY_G,COLOR_KEY_B));//dùng để ẩn màu nền
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);//tạo con chỏ mới từ load_surface
		if (new_texture != NULL)
		{
			//do sau này giải phóng dung lượng của load_surface mà ta muốn lưu lại chiueef rộng và chiueef cao của nền nên ta lưu chúng vào rect_
			rect_->h = load_surface->h;
			rect_->w = load_surface->w;
		}
		SDL_FreeSurface(load_surface);//giải phóng dung lượng cho load_surface

	}
	p_object_ = new_texture;//chuyển new_Texture sang p_object_
	if (p_object_ != NULL)
	{
		return 1;
	}
	return 0;
}
 void BaseObject::render(SDL_Renderer* des,const SDL_Rect* clip)
 {
	 SDL_Rect renderqual = { rect_->x,rect_->y,rect_->w,rect_->h };//khai báo tọa độ kích thước tấm ảnh
	 SDL_RenderCopy(des, p_object_, clip, &renderqual);//chuyển p_object_ với các kích thước của renderqual vào trong des

 }
 void BaseObject::free()
 {
	 if (p_object_ != NULL)
	 {
		 SDL_DestroyTexture(p_object_);//hàm xóa ảnh
		 p_object_ = NULL;
		 rect_->h = 0;
		 rect_->w = 0;
	 }
 }