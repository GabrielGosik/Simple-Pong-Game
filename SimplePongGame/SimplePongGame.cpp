// SimplePongGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>

using namespace std;

int main()
{
	int screenWidth = 800;
	int screenHeight = 600;

	cout << "Don't worry! The game is launching rather slower than expected, but it will be fixed" << endl;
	bool isInMenu = true, singleplayer = false, multiplayer = false, isCommandRun = false; //isCommandRun is just a simple flag to avoid message spam in terminal window

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
				BeginDrawing();
				DrawRectangle(20, 250, 30, 100, BLUE);
				// Add singleplayer game logic here
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
