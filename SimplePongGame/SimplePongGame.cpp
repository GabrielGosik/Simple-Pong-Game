

#include <iostream>
#include <raylib.h>

using namespace std;

int main()
{
	int screenWidth = 800;
	int screenHeight = 600;

	int playerRadius = 1;
	Vector2 Player1Position = { GetScreenWidth() *0.9, GetScreenHeight() / 2 };
	

	cout << "Don't worry! The game is launching rather slower than expected, but it will be fixed" << endl;
	bool isInMenu = true, singleplayer = false, multiplayer = false, paused = false, isCommandRun = false; //isCommandRun is just a simple flag to avoid message spam in terminal window

	InitWindow(screenWidth, screenHeight, "Simple Pong Game");

	SetTargetFPS(60);
	cout << "Window should be open now" << endl;
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
					cout << "Singleplayer mode" << endl;
					isCommandRun = true; //Tripping the flag
					}
				//Player logic begin
				if (!paused) {
					if (IsKeyPressedRepeat(KEY_W)) {
						Player1Position.y -= 15;

					}
					if (IsKeyPressedRepeat(KEY_S)) {
						Player1Position.y += 15;
					}
					if (Player1Position.y >= 540) {
						Player1Position.y -= 20;
					}
					if ((Player1Position.y - 50) <= -75) {
						Player1Position.y += 20;
					}
				}
				BeginDrawing();
				DrawRectangle(Player1Position.x, Player1Position.y, 30, 100, BLUE);

				// Add more singleplayer game logic here
			}
			else if (multiplayer == true) {
				if (isCommandRun == false) {
					cout << "Multiplayer mode" << endl;
					isCommandRun = true; //Tripping the flag
				}
				// Add multiplayer game logic here
			}
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Game is running!", 350, 280, 20, LIGHTGRAY);
			DrawText("Press ESC to exit", 300, 320, 20, LIGHTGRAY);
			if (IsKeyPressed(KEY_ESCAPE)) {
				break; // Exit the game loop
			}
			EndDrawing();
		}
	}
	cout << "Window should be closed now" << endl;
	CloseWindow(); // Close window and OpenGL context
	// De-Initialization
	exit(0); // Exit the program
}

