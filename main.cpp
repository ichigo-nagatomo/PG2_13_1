#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <math.h>

bool Enemy::isAlive_;

float Length(float x, float y) {
	return sqrtf(x * x + y * y);
}

const char kWindowTitle[] = "LC1B_18_ナガトモイチゴ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//宣言・初期化
	Player *player = new Player(300.0f, 500.0f, 10.0f);
	Enemy *enemy1 = new Enemy(400.0f, 200.0f, 5.0f);
	Enemy *enemy2 = new Enemy(600.0f, 300.0f, 6.0f);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::isAlive_ = true;
		}

		player->Move(keys, preKeys);
		enemy1->Update();
		enemy2->Update();

		if (Length((player->bullet->GetPosX() - enemy1->GetPosX()), (player->bullet->GetPosY() - enemy1->GetPosY())) 
			<= player->bullet->GetRadius() + enemy1->GetRadius()) {
			Enemy::isAlive_ = false;
		}

		if (Length((player->bullet->GetPosX() - enemy2->GetPosX()), (player->bullet->GetPosY() - enemy2->GetPosY())) 
			<= player->bullet->GetRadius() + enemy2->GetRadius()) {
			Enemy::isAlive_ = false;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		player->Draw();
		enemy1->Draw();
		enemy2->Draw();

		Novice::ScreenPrintf(20 , 20 , "%.2f" , player->bullet->GetPosY());
		Novice::ScreenPrintf(20 , 40 , "%.2f" , enemy1->GetPosX());

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
