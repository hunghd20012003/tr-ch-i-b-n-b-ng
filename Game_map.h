#pragma once
#ifndef GAME_MAP_H
#define GAME_MAP_H
#define MAP_TILES 20//định nghĩ số lượng dạng trên bản đồ tối đa là 20
#include "CommonFunction.h"
#include "BaseObject.h"
class TileMap : public BaseObject// lớp bản đồ
{
public:
	TileMap();
	~TileMap();

};
class GameMap
{
public:
	GameMap();
	~GameMap();
	void LoadMap(char* name);//tên bản đồ được load lên
	void LoadTiles(SDL_Renderer* screen);// load các tile lên màn hình vào từng ô
	void DrawMap(SDL_Renderer* screen);// hàm để xây dựng map 
private:
	Map game_map_;// lưu bản đồ game
	TileMap tilemap[MAP_TILES];// lưu các loại hình ảnh để đưa lên bản đồ
};
#endif
