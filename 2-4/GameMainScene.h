#pragma once
#include"AbstractScene.h"	

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class GameMainScene : public AbstractScene {
public:
	//�f�X�g���N�^
	virtual ~GameMainScene() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��鎖����������
	virtual void Draw() const override;
};

