#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
	int image; //��U�g��Ȃ�
public:
	StraightBullets(T_Location location);
public:
	virtual void Update() override;
	virtual void Draw() override;
};

