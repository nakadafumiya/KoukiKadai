#include"AbstractScene.h"	
#include"GameMainScene.h"
#include"HPPotion.h"

AbstractScene* GameMainScene::Update()
{
	player->Update();
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] == nullptr)
		{
			break;
		}
		enemy[i]->Update();
	}
	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Update();
	}

	BulletsBase** bullets = player->GetBullets();
	
	for (int bulletsCount = 0; bulletsCount < 30; bulletsCount++)
	{
		if (bullets[bulletsCount] == nullptr)
		{
			break;
		}
		for (int EnemyCount = 0; EnemyCount < 10; EnemyCount++)
		{
			if (enemy[EnemyCount] == nullptr)
			{
				break;
			}
			if (bullets[bulletsCount]->HitSphere(enemy[EnemyCount]))
			{
				//�e�̃_���[�W�����˂݁[�ɗ^����
				enemy[EnemyCount]->Hit(bullets[bulletsCount]->GetDamage());

				//�Ղꂢ��[�̒e�Ƃ��˂݁[����������
				player->Hit(bulletsCount);//�e������
				bullets = player->GetBullets();
				bulletsCount--;
				
				//���˂݁[��HP��0�ȉ��ł���΂��˂݁[������
				if (enemy[EnemyCount]->HpCheck())
				{
					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new HpPotion(enemy[EnemyCount]->GetLocation());
							break;
						}
					}

					//���˂݁[���������Ƃ��A�Ղꂢ��[�̃X�R�A��
					//���˂݁[�̃|�C���g�����Z����
					player->addScore(enemy[EnemyCount]->GetPoint());

					delete enemy[EnemyCount];
					enemy[EnemyCount] = nullptr;

					for(int i = (EnemyCount + 1); i < 10; i++)
					{
						if (enemy[i] == nullptr)
						{
							break;
						}
						enemy[i - 1] = enemy[i];
						enemy[i] = nullptr;
					}
				}
			}
		}
		for (int bulletCount = 0; bulletCount < 30; bulletCount++)

			//�A�C�e���̓����蔻��
			for (int itemCount = 0; itemCount < 10; itemCount++)
			{
				if (items[itemCount] == nullptr)
				{
					break;
				}
				if (player->HitSphere(items[itemCount]))
				{
					player->Hit(items[itemCount]);

					delete items[itemCount];
					items[itemCount] = nullptr;
					for (int i = itemCount + 1; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							break;
						}
						items[i - 1] = items[i];
						items[i] = nullptr;
					}
				}
			}
	}

	return this;

}
	

void GameMainScene::Draw() const
{
	player->Draw();
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] == nullptr)
		{
			break;
		}
		enemy[i]->Draw();
	}

	player->Draw();
	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Draw();
	}
}

