#pragma once
#include <Vector2.h>

class Enemy {
protected:
	Vector2 pos_;
	float speed_;
	float radius_;

public:
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	float GetRadius() { return radius_; };

	static bool isAlive_;

	Enemy(float posX, float posY, float speed);
	~Enemy();

	void Update();
	void Draw();
};

