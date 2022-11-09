#include"SphereCollider.h"
#include<math.h>

SphereCollider::SphereCollider(T_Location location, float radius)
{
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
}

bool SphereCollider::HitSphere(SphereCollider*s)
{
	//�~�Ɖ~�̓����蔻��
	//�����̃x�N�g���[����̃x�N�g����
	T_Location location = s->GetLocation();  //���݂��̈ʒu�������Z���ďo�Ă��鐔���������̔{
	float x = this->location.x -location.x;  //�������Ƒ���̔��a��菬������Γ������Ă��đ傫����Γ������Ă��Ȃ�
	float y = this->location.y -location.y;

	//��Βl�ɕϊ�
	x = fabsf(x);
	y = fabsf(y);
	
	//�x�N�g���̑傫�����擾
	float xy =(x*x)+(y*y);
	double vectorSize = sqrt(xy);

	//�����̔��a�{����̔��a ���擾
	float radius = this->radius + s->GetRadius();

	//�x�N�g���̑傫��<=�̎�
	bool ret = (vectorSize <= radius);
	return ret;
}
float SphereCollider::GetRadius()
{
	return radius;
}

T_Location SphereCollider::GetLocation()
{
	return location;
}

void SphereCollider::SetLocation(T_Location value)
{
	location.x = value.x;
	location.y = value.y;
}