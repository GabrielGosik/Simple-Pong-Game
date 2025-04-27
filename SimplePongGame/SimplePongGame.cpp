

#include <iostream>
#include <raylib.h>
#include <cstdlib>
#include <ctime>


using namespace std;

void ballReset() {
	// Reset ball position and velocity
}
void playerPoint(int whichPlayer, int &playerPoints) {
	// Player 1 wins a point
}

int main()
{
	srand(time(NULL));
	int screenWidth = 800;
	int screenHeight = 600;

	int playerRadius = 1;
	int player1Points = 0;
	int player2Points = 0;
	int ballSide = rand() % 1;
	int ballAngle = ((rand() % 9) + 1) - 5;
	


	//cout << "Don't worry! The game is launching rather slower than expected, but it will be fixed" << endl;
	bool isInMenu = true, singleplayer = false, multiplayer = false, paused = false, isCommandRun = false; //isCommandRun is just a simple flag to avoid message spam in terminal window

	InitWindow(screenWidth, screenHeight, "Simple Pong Game");


	Vector2 Player1Position = { GetScreenWidth() * 0.01, (GetScreenHeight() / 2)-10 };
	Vector2 Player2Position = { GetScreenWidth() * 0.99, (GetScreenHeight() / 2) - 10 };
	Vector2 BallPosition = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
	Vector2 BallSpeed{ 0,0 };
	if (ballSide == 0) {
		Vector2 BallSpeed { 5.0f, 5.0f };
		cout << "0" << endl;
	}
	else {
		Vector2 BallSpeed { -5.0f, 5.0f };
		cout << "1" << endl;
	}


	SetTargetFPS(60);
	//cout << "Window should be open now" << endl;
	while (!WindowShouldClose())
	{
		if (isInMenu) {

			// Draw menu
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Welcome to the Simple Pong Game!", 250, 200, 20, LIGHTGRAY);
			DrawText("Press ENTER to start singleplayer", 250, 300, 20, LIGHTGRAY);
			DrawText("Press SHIFT to start local multiplayer", 250, 350, 20, LIGHTGRAY);
			EndDrawing();
			if (IsKeyPressed(KEY_ENTER)) {
				isInMenu = false;
				singleplayer = true;
			}
			else if (IsKeyPressed(KEY_LEFT_SHIFT) || IsKeyPressed(KEY_RIGHT_SHIFT)) {
				isInMenu = false;
				multiplayer = true;
			}
		}
		else {
			// Game logic and rendering goes here
			if (singleplayer == true) {
				if (isCommandRun == false) {
					//cout << "Singleplayer mode" << endl;
					isCommandRun = true; //Tripping the flag
					}
				//Player logic
				if (!paused) {
					if (IsKeyPressedRepeat(KEY_W)) {
						Player1Position.y -= 15;

					}
					if (IsKeyPressedRepeat(KEY_S)) {
						Player1Position.y += 15;
					}
					if (Player1Position.y >= 540) {
						Player1Position.y -= 16;
					}
					if ((Player1Position.y - 50) <= -75) {
						Player1Position.y += 16;
					}
				//Ball logic


					if (BallPosition.x >= 800) {
						ballReset();
						playerPoint(1, player1Points);
					}
					else if (BallPosition.x <= 0) {
						ballReset();
						playerPoint(2, player2Points);
					}
					BallPosition.x += BallSpeed.x;
					BallPosition.y += BallSpeed.y;

					if ((BallPosition.x >= (GetScreenWidth() - 10)) || (BallPosition.x <= 10)) BallSpeed.x *= -1.0f;
					if ((BallPosition.y >= (GetScreenWidth() - 10)) || (BallPosition.y <= 10)) BallSpeed.y *= -1.0f;
				}
				BeginDrawing();
				DrawRectangle(Player1Position.x, Player1Position.y, 30, 100, BLUE);
				DrawCircle(BallPosition.x, BallPosition.y, 10, BLACK);

				// Add more singleplayer game logic here
			}
			else if (multiplayer == true) {
				if (isCommandRun == false) {
					//cout << "Multiplayer mode" << endl;
					isCommandRun = true; //Tripping the flag
				}
				// Add multiplayer game logic here
			}
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Press ESC to exit", 300, 320, 20, LIGHTGRAY);
			if (IsKeyPressed(KEY_ESCAPE)) {
				break; // Exit the game loop
			}
			EndDrawing();
		}
	}
	//cout << "Window should be closed now" << endl;
	CloseWindow(); // Close window and OpenGL context
	// De-Initialization
	//exit(0); // Exit the program
}

