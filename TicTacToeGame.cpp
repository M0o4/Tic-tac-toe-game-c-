#include "TicTacToeGame.h"

void TicTacToeGame::Start()
{
	setlocale(LC_ALL, "ru");
	while (!xWin && !oWin)
	{
		system("cls");
		PrintMatrix();
		Input();
		Logic();
	}
}

void TicTacToeGame::Input()
{
	do
	{
		switch (goes)
		{
		case TicTacToeGame::eGoes::X:
			cout << endl << "Ходит X" << endl;
			break;
		case TicTacToeGame::eGoes::O:
			cout << endl << "Ходит O" << endl;
			break;
		default:
			break;
		}

		cout << "Выберите куда вы хотите сделать ход: ";
		input = GetValue();

	} while (input < 0 || input > 8 || CheckСage());
	
	turn++;
}

void TicTacToeGame::Logic()
{
	switch (input)
	{
	case 0:
		SetXO(0, 0);
		break;
	case 1:
		SetXO(0, 1);
		break;
	case 2:
		SetXO(0, 2);
		break;
	case 3:
		SetXO(1, 0);
		break;
	case 4:
		SetXO(1, 1);
		break;
	case 5:
		SetXO(1, 2);
		break;
	case 6:
		SetXO(2, 0);
		break;
	case 7:
		SetXO(2, 1);
		break;
	case 8:
		SetXO(2, 2);
		break;
	default:
		break;
	}

	switch (goes)
	{
	case TicTacToeGame::eGoes::X:
		goes = TicTacToeGame::eGoes::O;
		break;
	case TicTacToeGame::eGoes::O:
		goes = TicTacToeGame::eGoes::X;
		break;
	default:
		break;
	}
}

void TicTacToeGame::PrintMatrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}

		cout << endl;
	}
}

void TicTacToeGame::SetXO(int index1, int index2)
{
	if (arr[index1][index2] != "X" || arr[index1][index2] != "O") {
		switch (goes)
		{
		case TicTacToeGame::eGoes::X:
			arr[index1][index2] = "X";
			break;
		case TicTacToeGame::eGoes::O:
			arr[index1][index2] = "O";
			break;
		default:
			break;
		}

		if (turn >= 4) {
			switch (goes)
			{
			case TicTacToeGame::eGoes::X:
				if (IsXWin()) {
					xWin = true;
					system("cls");
					PrintMatrix();
					cout << "X победил!" << endl;
				}
				break;
			case TicTacToeGame::eGoes::O:
				if (isOWin()) {
					oWin = true;
					system("cls");
					PrintMatrix();
					cout << "O победил!" << endl;
				}
				break;
			default:
				break;
			}
		}
	}
}

bool TicTacToeGame::CheckСage()
{
	switch (input)
	{
	case 0:
		return arr[0][0] == "X" || arr[0][0] == "O";
	case 1:
		return arr[0][1] == "X" || arr[0][1] == "O";
	case 2:
		return arr[0][2] == "X" || arr[0][2] == "O";
	case 3:
		return arr[1][0] == "X" || arr[1][0] == "O";
	case 4:
		return arr[1][1] == "X" || arr[1][1] == "O";
	case 5:
		return arr[1][2] == "X" || arr[1][2] == "O";
	case 6:
		return arr[2][0] == "X" || arr[2][0] == "O";
	case 7:
		return arr[2][1] == "X" || arr[2][1] == "O";
	case 8:
		return arr[2][2] == "X" || arr[2][2] == "O";
	default:
		return false;
	}
}

bool TicTacToeGame::IsXWin()
{
	if (arr[0][0] == "X") {
		if (CheckHorizontal(0, 0)) {
			return true;
		}

		if (CheckVertical(0, 0)) {
			return true;
		}
	}

	if (arr[0][1] == "X") {
		if (CheckVertical(0, 1)) {
			return true;
		}
	}

	if (arr[0][2] == "X") {
		if (CheckVertical(0, 2)) {
			return true;
		}
	}

	if (arr[1][0] == "X") {
		if (CheckHorizontal(1, 0)) {
			return true;
		}
	}

	if (arr[1][1] == "X") {
		if (CheckDiagonal()) {
			return true;
		}
	}

	if (arr[2][0] == "X") {
		if (CheckHorizontal(2, 0)) {
			return true;
		}
	}

	return false;
}

bool TicTacToeGame::isOWin()
{
	if (arr[0][0] == "O") {
		if (CheckHorizontal(0, 0)) {
			return true;
		}

		if (CheckVertical(0, 0)) {
			return true;
		}
	}

	if (arr[0][1] == "O") {
		if (CheckVertical(0, 1)) {
			return true;
		}
	}

	if (arr[0][2] == "O") {
		if (CheckVertical(0, 2)) {
			return true;
		}
	}

	if (arr[1][0] == "O") {
		if (CheckHorizontal(1, 0)) {
			return true;
		}
	}

	if (arr[1][1] == "O") {
		if (CheckDiagonal()) {
			return true;
		}
	}

	if (arr[2][0] == "O") {
		if (CheckHorizontal(2, 0)) {
			return true;
		}
	}

	return false;
}

bool TicTacToeGame::CheckHorizontal(int index1, int index2)
{
	return arr[index1][index2] == arr[index1][index2 + 1] && arr[index1][index2 + 1] == arr[index1][index2 + 2];
}

bool TicTacToeGame::CheckVertical(int index1, int index2)
{
	return arr[index1][index2] == arr[index1+1][index2] && arr[index1+1][index2] == arr[index1+2][index2];
}

bool TicTacToeGame::CheckDiagonal()
{
	return (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]);
}

TicTacToeGame::TicTacToeGame() {
	input = 0;
	turn = 0;
	goes = TicTacToeGame::eGoes::X;
}