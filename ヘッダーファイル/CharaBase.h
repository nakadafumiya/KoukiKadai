#pragma once
#include "SphereCollider.h"
#include "BulletsBase.h"

class CharaBase
{
protected:
    T_Location speed; //�ړ����x
    int* image=nullptr; //�`�悷��摜
    BulletsBase** bullets;//���˂���e

public:
    virtual ~CharaBase();

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit() = 0;

    T_Location GetSpeed();
    void SetSpeed(T_Location speed);
    BulletsBase** GetBullets();
};

