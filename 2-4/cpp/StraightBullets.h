#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
	int image; //一旦使わない
public:
	StraightBullets(T_Location location);
public:
	virtual void Update() override;
	virtual void Draw() override;
};

