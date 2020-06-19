#pragma once
#include "GetValue.h"

class TicTacToeGame
{
public:
	TicTacToeGame();
	void Start();
private:
	void Input();
	void Logic();
	void PrintMatrix();
	void SetXO(int index1, int index2);
	bool Check—age();
	bool IsXWin();
	bool isOWin();
	bool CheckHorizontal(int index1, int index2);
	bool CheckVertical(int index1, int index2);
	bool CheckDiagonal();

	string arr[3][3] = {
						{"0","1","2"},
						{"3","4","5"},
						{"6","7","8"} };

	int input;
	int turn;

	enum class eGoes {X = 0, O};
	
	eGoes goes;

	bool xWin = false;
	bool oWin = false;
};

