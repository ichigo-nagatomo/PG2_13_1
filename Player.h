#pragma once
#include "Bullet.h"
#include <Vector2.h>

class Player {
private:
	Vector2 pos_;
	float radius_;
	float speed_;

public:
	Bullet *bullet = new Bullet(-100.0f, -100.0f, 15.0f);

	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	float GetSpeed() { return speed_; };
	float GetRadius() { return radius_; };

	Player(float posX, float posY, float speed);
	~Player();

	void Update();
	void Draw();

	void Move(char *keys, char *preKeys);
};

