#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
	int image; //ˆê’UŽg‚í‚È‚¢
public:
	StraightBullets(T_Location location);
public:
	virtual void Update() override;
	virtual void Draw() override;
};

