#include"AbstractScene.h"	
#include"GameMainScene.h"

AbstractScene* GameMainScene::Update()
{
	player->Update();
	//���M�̃|�C���^
	return this;
}

void GameMainScene::Draw() const
{
	player->Draw();
}