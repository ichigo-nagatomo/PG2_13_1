#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(float posX, float posY, float speed) {
	pos_ = {posX, posY};
	speed_ = speed;
	radius_ = 20.0f;
	isAlive_ = true;
}

Enemy::~Enemy() {

}

void Enemy::Update() {
	if (isAlive_) {
		pos_.x += speed_;
		if (pos_.x >= 1280.0f - radius_) {
			speed_ *= -1;
		} else if (pos_.x <= 0.0f + radius_) {
			speed_ *= -1;
		}
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x) , static_cast<int>(pos_.y) ,
			static_cast<int>(radius_) , static_cast<int>(radius_) ,
			0.0f ,
			0xFFFFFFFF ,
			kFillModeSolid
		);
	}
}