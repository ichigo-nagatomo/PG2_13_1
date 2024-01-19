#include "Player.h"
#include <Novice.h>

Player::Player(float posX, float posY, float speed) {
	pos_ = {posX, posY};
	speed_ = speed;
	radius_ = 24;
}

Player::~Player() {
	
}

void Player::Move(char *keys, char *preKeys) {

	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}

	if (keys[DIK_S]) {
		pos_.y += speed_;
	}

	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		if (!bullet->GetIsShoot()) {
			bullet->SetIsShoot(true);
			bullet->SetPosX(pos_.x);
			bullet->SetPosY(pos_.y);
		}
	}

	bullet->Update();
}

void Player::Update() {

}

void Player::Draw() {
	bullet->Draw();

	Novice::DrawEllipse(
		static_cast<int>(pos_.x) , static_cast<int>(pos_.y) ,
		static_cast<int>(radius_) , static_cast<int>(radius_) ,
		0.0f ,
		0xFFFFFFFF ,
		kFillModeSolid
	);
}