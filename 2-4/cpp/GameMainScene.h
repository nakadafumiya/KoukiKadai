#pragma once
#include"AbstractScene.h"	
#include"Player.h"

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class GameMainScene : public AbstractScene {
private:
	Player*player;
public:
	
    GameMainScene() 
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius = 10.f;

		player = new Player(location, radius);
	};

	//�f�X�g���N�^
	virtual ~GameMainScene()
	{
		delete player;  //new���������delete�����
	};
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	//�`��Ɋւ��鎖����������
	virtual void Draw() const override;
};

