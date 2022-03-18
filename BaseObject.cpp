#include "BaseObject.h"
BaseObject::BaseObject()
{
	p_object_ = NULL;
	rect_->x = 0;
	rect_->y = 0;
	rect_->w = 0;
	rect_->h = 0;

}
BaseObject::~BaseObject()
{

}
bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
	SDL_Texture* new_texture = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());
	if (load_surface != NULL)
	{
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_texture != NULL)
		{
			rect_->w = load_surface->w;
			rect_->h = load_surface->h;
		}
		SDL_FreeSurface(load_surface);//xóa ?i vì toàn b? ?ã ???c t?i trên new_texture
	}
	p_object_ = new_texture;
	if (p_object_ != NULL)
	{
		return 1;
	}
	return 0;
}
void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
	SDL_Rect renderqual = { rect_->x,rect_->y,rect_->h,rect_->w };//khai báo t?a ?? kích th??c t?m ?nh
	SDL_RenderCopy(des, p_object_, clip, &renderqual);//chuy?n cái p_object v?i kích th??c nh? renderqual vào trong des
}
void BaseObject::Free()
{
	if (p_object_ != NULL)
	{
		SDL_DestroyTexture(p_object_);
		p_object_ = NULL;
		rect_->h = 0;
		rect_->w = 0;
	}
}
