#include"AbstractScene.h"	
#include"GameMainScene.h"

AbstractScene* GameMainScene::Update()
{
	player->Update();
	//自信のポインタ
	return this;
}

void GameMainScene::Draw() const
{
	player->Draw();
}