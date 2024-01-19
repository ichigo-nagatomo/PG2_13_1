#pragma once
#include "Vector2.h"

class Bullet {
protected:
	Vector2 pos_;
	float speed_;
	float radius_;
	bool isShoot_;
	
public:
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	float GetRadius() { return radius_; };
	bool GetIsShoot() { return isShoot_; };
	void SetPosX(float posX);
	void SetPosY(float posY);
	void SetIsShoot(bool isShoot);

	Bullet(float posX, float posY, float speed);
	~Bullet();
	void Update();
	void Draw();

};

