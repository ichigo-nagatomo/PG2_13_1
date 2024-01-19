#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(float posX, float posY, float speed) {
	pos_ = {posX, posY};
	speed_ = speed;
	radius_ = 10.0f;
	isShoot_ = false;
}

Bullet::~Bullet() {
	
}

void Bullet::Update() {
	if (isShoot_) {
		pos_.y -= speed_;
		if (pos_.y <= -10.0f) {
			isShoot_ = false;
		}
	} else {
		pos_ = {-100, -100};
	}
}

void Bullet::Draw() {
	if (isShoot_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x) , static_cast<int>(pos_.y) ,
			static_cast<int>(radius_) , static_cast<int>(radius_) ,
			0.0f ,
			0xFFFFFFFF ,
			kFillModeSolid
		);
	}
}

void Bullet::SetPosX(float x) {
	pos_.x = x;
}

void Bullet::SetPosY(float y) {
	pos_.y = y;
}

void Bullet::SetIsShoot(bool isShoot) {
	isShoot_ = isShoot;
}
