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

	InitWindow(screenWidth, screenHeight, "Simple Pong Game");

	SetTargetFPS(60);
	cout << "Window should be open now" << endl;
	while (!WindowShouldClose())
	{
		// Update
		//if (IsKeyDown(KEY_RIGHT)) { /* Move right */ }
		//if (IsKeyDown(KEY_LEFT)) { /* Move left */ }
		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("Simple Pong Game", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}
	cout << "Window should be closed now" << endl;
	CloseWindow(); // Close window and OpenGL context
	// De-Initialization

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
