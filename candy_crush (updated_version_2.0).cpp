#include<iostream>
#include"graphics.h"
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;

void PrintShape(int shape, int x1, int y1, int x2, int y2)
{
	if (shape == 0)
	{
		cursor(x1 - 7, y1 - 7, x2 + 7, y2 + 7, 0, 0, 0);
	}
	else if (shape == 1)
	{
		myEllipse(x1, y1, x2, y2, 255, 255, 255);
	}
	else if (shape == 2)
	{
		myRectangle(x1, y1, x2, y2, 255, 0, 0);
	}
	else if (shape == 3)
	{
		myDiamond(x1, y1, x2, y2, 0, 0, 255);
	}
	else if (shape == 4)
	{
		myTriangle(x1, y1, x2, y2, 255, 255, 0);
	}
	else if (shape == 5)
	{
		myUDTriangle(x1, y1, x2, y2, 255, 0, 255);
	}
	else if (shape == 10)
	{
		myEllipse1(x1, y1, x2, y2, 255, 255, 255);
	}
	else if (shape == 20)
	{
		myRectangle1(x1, y1, x2, y2, 255, 0, 0);
	}
	else if (shape == 30)
	{
		myDiamond1(x1, y1, x2, y2, 0, 0, 255);
	}
	else if (shape == 40)
	{
		myTriangle1(x1, y1, x2, y2, 255, 255, 0);
	}
	else if (shape == 50)
	{
		myUDTriangle1(x1, y1, x2, y2, 255, 0, 255);
	}
	else if (shape == -1)
	{
		myEllipse2(x1, y1, x2, y2, 255, 255, 255);
	}
	else if (shape == -2)
	{
		myRectangle2(x1, y1, x2, y2, 255, 0, 0);
	}
	else if (shape == -3)
	{
		myDiamond2(x1, y1, x2, y2, 0, 0, 255);
	}
	else if (shape == -4)
	{
		myTriangle2(x1, y1, x2, y2, 255, 255, 0);
	}
	else if (shape == -5)
	{
		myUDTriangle2(x1, y1, x2, y2, 255, 0, 255);
	}
	else if (shape == 100)
	{
		cursor(x1 - 7, y1 - 7, x2 + 7, y2 + 7, 255, 255, 255);
	}
}

void PrintBoard(int board[][8], int score, int x, int y)
{
	system("cls");
	int timer = clock() / 1000;
	gotoxy(0, 0);
	cout << "\n   Timer: " << timer << "s \n\n";
	gotoxy(0, 0);
	cout << "\n\n   Score : " << score << endl << endl << endl;
	for (int i = 0, y1 = 150, y2 = 200; i < 8; i++, y1 = y1 + 70, y2 = y2 + 70)
	{
		for (int j = 0, x1 = 300, x2 = 350; j < 8; j++, x1 = x1 + 70, x2 = x2 + 70)
		{
			if (i == x && j == y)
			{
				PrintShape(board[i][j], x1, y1, x2, y2);
				PrintShape(100, x1, y1, x2, y2);
			}
			else
				PrintShape(board[i][j], x1, y1, x2, y2);
		}
		cout << endl << endl;
	}
	cout << endl;
}

void populateboard(int board[][8])
{
	srand(time(0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = (rand() % 5) + 1;
			}
		}
	}
}



void SwapToTop(int b[][8], int& score)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == 0)
			{
				for (int k = i; k > 0; k--)
				{
					swap(b[k][j], b[k - 1][j]);
					PrintBoard(b, score, -1, -1);
					Sleep(20);
				}
			}
		}
	}
}

void destroyDestroyer(int box[][8], int& score, int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (x == i || y == j)
			{
				box[i][j] = 0;
			}
		}
	}
	SwapToTop(box, score);
	populateboard(box);
	score = score + 140;
}

bool DestroyerCheck(int box[][8], int& score)
{
	bool found = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (box[i][j] == -1 || box[i][j] == -2 || box[i][j] == -3 || box[i][j] == -4 || box[i][j] == -5)
			{
				if (-box[i][j] == box[i][j + 1] && -box[i][j] == box[i][j - 1])
				{
					destroyDestroyer(box, score, i, j);
					found = 1;
				}
				else if (-box[i][j] == box[i + 1][j] && -box[i][j] == box[i - 1][j])
				{
					destroyDestroyer(box, score, i, j);
					found = 1;
				}
				else if (-box[i][j] == box[i + 1][j] && -box[i][j] == box[i + 2][j])
				{
					destroyDestroyer(box, score, i, j);
					found = 1;
				}
				else if (-box[i][j] == box[i][j + 1] && -box[i][j] == box[i][j + 2])
				{
					destroyDestroyer(box, score, i, j);
					found = 1;
				}
				else if (-box[i][j] == box[i - 1][j] && -box[i][j] == box[i - 2][j])
				{
					destroyDestroyer(box, score, i, j);
					found = 1;
				}
				else if (-box[i][j] == box[i][j - 1] && -box[i][j] == box[i][j - 2])
				{
					destroyDestroyer(box, score, i, j);
					found = 1;
				}
			}
		}
	}
	return found;
}

void flameDestroyer(int box[][8], int score, int x, int y)
{
	if (x > 0 && x < 7 && y>0 && y < 7)
	{
		box[x][y] = 0;
		box[x - 1][y - 1] = 0;
		box[x - 1][y] = 0;
		box[x - 1][y + 1] = 0;
		box[x + 1][y - 1] = 0;
		box[x + 1][y] = 0;
		box[x + 1][y + 1] = 0;
		box[x][y - 1] = 0;
		box[x][y + 1] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 90;
	}
	else if (x == 0 && y != 0 && y != 7)
	{
		box[x][y] = 0;
		box[x][y - 1] = 0;
		box[x][y + 1] = 0;
		box[x + 1][y - 1] = 0;
		box[x + 1][y] = 0;
		box[x + 1][y + 1] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 60;
	}
	else if (x == 7 && y != 0 && y != 7)
	{
		box[x][y] = 0;
		box[x][y - 1] = 0;
		box[x][y + 1] = 0;
		box[x - 1][y] = 0;
		box[x - 1][y - 1] = 0;
		box[x - 1][y + 1] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 60;
	}
	else if (y == 0 && x != 0 && x != 7)
	{
		box[x][y] = 0;
		box[x - 1][y] = 0;
		box[x + 1][y] = 0;
		box[x][y + 1] = 0;
		box[x - 1][y + 1] = 0;
		box[x + 1][y + 1] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 60;
	}
	else if (y == 7 && x != 0 && x != 7)
	{
		box[x][y] = 0;
		box[x - 1][y] = 0;
		box[x + 1][y] = 0;
		box[x][y - 1] = 0;
		box[x - 1][y - 1] = 0;
		box[x + 1][y - 1] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 60;
	}
	else if (x == 0 && y == 0)
	{
		box[x][y] = 0;
		box[x][y + 1] = 0;
		box[x + 1][y + 1] = 0;
		box[x + 1][y] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 40;
	}
	else if (x == 0 && y == 7)
	{
		box[x][y] = 0;
		box[x][y - 1] = 0;
		box[x + 1][y - 1] = 0;
		box[x + 1][y] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 40;
	}
	else if (x == 7 && y == 7)
	{
		box[x][y] = 0;
		box[x - 1][y] = 0;
		box[x - 1][y - 1] = 0;
		box[x][y - 1] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 40;
	}
	else if (x == 7 && y == 0)
	{
		box[x][y] = 0;
		box[x - 1][y] = 0;
		box[x - 1][y] = 0;
		box[x][y + 1] = 0;
		SwapToTop(box, score);
		populateboard(box);
		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		score = score + 40;
	}
}

bool FlameCheck(int box[][8], int& score)
{
	bool found = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (box[i][j] == 10 || box[i][j] == 20 || box[i][j] == 30 || box[i][j] == 40 || box[i][j] == 50)
			{
				if (box[i][j] == box[i][j + 1] * 10 && box[i][j] == box[i][j - 1] * 10)
				{
					flameDestroyer(box, score, i, j);
					found = 1;
				}
				else if (box[i][j] == box[i + 1][j] * 10 && box[i][j] == box[i - 1][j] * 10)
				{
					flameDestroyer(box, score, i, j);
					found = 1;
				}
				else if (box[i][j] == box[i + 1][j] * 10 && box[i][j] == box[i + 2][j] * 10)
				{
					flameDestroyer(box, score, i, j);
					found = 1;
				}
				else if (box[i][j] == box[i][j + 1] * 10 && box[i][j] == box[i][j + 2] * 10)
				{
					flameDestroyer(box, score, i, j);
					found = 1;
				}
				else if (box[i][j] == box[i - 1][j] * 10 && box[i][j] == box[i - 2][j] * 10)
				{
					flameDestroyer(box, score, i, j);
					found = 1;
				}
				else if (box[i][j] == box[i][j - 1] * 10 && box[i][j] == box[i][j - 2] * 10)
				{
					flameDestroyer(box, score, i, j);
					found = 1;
				}
			}
		}
	}
	return found;
}

int shapeSelector1(int shape)
{
	if (shape == 1)
	{
		return 10;
	}
	else if (shape == 2)
	{
		return 20;
	}
	else if (shape == 3)
	{
		return 30;
	}
	else if (shape == 4)
	{
		return 40;
	}
	else if (shape == 5)
	{
		return 50;
	}
}

int shapeSelector2(int shape)
{
	if (shape == 1)
	{
		return -1;
	}
	else if (shape == 2)
	{
		return -2;
	}
	else if (shape == 3)
	{
		return -3;
	}
	else if (shape == 4)
	{
		return -4;
	}
	else if (shape == 5)
	{
		return -5;
	}
}

bool SpecialCheck2(int board[][8], int& score)
{
	bool flag = 0;

	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			if (board[row][col] == board[row][col + 1] && board[row][col] == board[row][col + 2] && board[row][col] == board[row + 1][col] && board[row][col] == board[row + 2][col])
			{
				board[row][col] = shapeSelector2(board[row][col]);
				board[row][col + 1] = 0;
				board[row][col + 2] = 0;
				board[row + 1][col] = 0;
				board[row + 2][col] = 0;
				score = score + 50;
				SwapToTop(board, score);
				populateboard(board);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(board, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(board, score);
				}
				flamecheck = 1;
				PrintBoard(board, score, -1, -1);
				flag = 1;
			}
		}
	}
	for (int row = 0; row < 6; row++)
	{
		for (int col = 7; col > 1; col--)
		{
			if (board[row][col] == board[row][col - 1] && board[row][col] == board[row][col - 2] && board[row][col] == board[row + 1][col] && board[row][col] == board[row + 2][col])
			{
				board[row][col] = shapeSelector2(board[row][col]);
				board[row][col - 1] = 0;
				board[row][col - 2] = 0;
				board[row + 1][col] = 0;
				board[row + 2][col] = 0;
				score = score + 50;
				SwapToTop(board, score);
				populateboard(board);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(board, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(board, score);
				}
				flamecheck = 1;
				PrintBoard(board, score, -1, -1);
				flag = 1;
			}
		}
	}
	for (int row = 7; row > 1; row--)
	{
		for (int col = 7; col > 1; col--)
		{
			if (board[row][col] == board[row][col - 1] && board[row][col] == board[row][col - 2] && board[row][col] == board[row - 1][col] && board[row][col] == board[row - 2][col])
			{
				board[row][col] = shapeSelector2(board[row][col]);
				board[row][col - 1] = 0;
				board[row][col - 2] = 0;
				board[row - 1][col] = 0;
				board[row - 2][col] = 0;
				score = score + 50;
				SwapToTop(board, score);
				populateboard(board);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(board, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(board, score);
				}
				flamecheck = 1;
				PrintBoard(board, score, -1, -1);
				flag = 1;
			}
		}
	}
	for (int row = 7; row > 1; row--)
	{
		for (int col = 0; col < 6; col++)
		{
			if (board[row][col] == board[row][col + 1] && board[row][col] == board[row][col + 2] && board[row][col] == board[row - 1][col] && board[row][col] == board[row - 2][col])
			{
				board[row][col] = shapeSelector2(board[row][col]);
				board[row][col + 1] = 0;
				board[row][col + 2] = 0;
				board[row - 1][col] = 0;
				board[row - 2][col] = 0;
				score = score + 50;
				SwapToTop(board, score);
				populateboard(board);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(board, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(board, score);
				}
				flamecheck = 1;
				PrintBoard(board, score, -1, -1);
				flag = 1;
			}
		}
	}
	return flag;
}

bool SpecialCheck1(int arr[][8], int& score)
{
	bool flag = 0;

	for (int row = 0; row < 8; row++)
	{
		for (int col = 2; col < 6; col++)
		{
			if (arr[row][col] == arr[row][col - 2] && arr[row][col] == arr[row][col - 1] && arr[row][col] == arr[row][col + 1] && arr[row][col] == arr[row][col + 2])
			{
				arr[row][col] = shapeSelector1(arr[row][col]);
				arr[row][col - 1] = 0;
				arr[row][col + 1] = 0;
				arr[row][col + 2] = 0;
				arr[row][col - 2] = 0;
				score = score + 50;
				SwapToTop(arr, score);
				populateboard(arr);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(arr, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(arr, score);
				}
				flamecheck = 1;
				bool specialcheck2 = 1;
				while (specialcheck2 != 0)
				{
					specialcheck2 = SpecialCheck2(arr, score);
				}
				specialcheck2 = 1;
				PrintBoard(arr, score, -1, -1);
				//cout << "\n -------You made a row of 5 same shapes-------- \n";
				flag = 1;
			}
		}
	}
	for (int col = 0; col < 8; col++)
	{
		for (int row = 2; row < 6; row++)
		{
			if (arr[row][col] == arr[row - 2][col] && arr[row][col] == arr[row - 1][col] && arr[row][col] == arr[row + 1][col] && arr[row][col] == arr[row + 2][col])
			{
				arr[row][col] = shapeSelector1(arr[row][col]);
				arr[row - 1][col] = 0;
				arr[row + 1][col] = 0;
				arr[row + 2][col] = 0;
				arr[row - 2][col] = 0;
				score = score + 50;
				SwapToTop(arr, score);
				populateboard(arr);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(arr, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(arr, score);
				}
				flamecheck = 1;
				bool specialcheck2 = 1;
				while (specialcheck2 != 0)
				{
					specialcheck2 = SpecialCheck2(arr, score);
				}
				specialcheck2 = 1;
				PrintBoard(arr, score, -1, -1);
				//cout << "\n -------You made a column of 5 same shapes-------- \n";
				flag = 1;
			}
		}
	}
	for (int row = 0; row < 8; row++)
	{
		for (int col = 1; col < 6; col++)
		{
			if (arr[row][col] == arr[row][col - 1] && arr[row][col] == arr[row][col + 1] && arr[row][col] == arr[row][col + 2])
			{
				arr[row][col] = shapeSelector1(arr[row][col]);
				arr[row][col - 1] = 0;
				arr[row][col + 1] = 0;
				arr[row][col + 2] = 0;
				score = score + 40;
				SwapToTop(arr, score);
				populateboard(arr);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(arr, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(arr, score);
				}
				flamecheck = 1;
				bool specialcheck2 = 1;
				while (specialcheck2 != 0)
				{
					specialcheck2 = SpecialCheck2(arr, score);
				}
				specialcheck2 = 1;
				PrintBoard(arr, score, -1, -1);
				//cout << "\n -------You made a row of 4 same shapes-------- \n";
				flag = 1;
			}
		}
	}
	for (int col = 0; col < 8; col++)
	{
		for (int row = 1; row < 6; row++)
		{
			if (arr[row][col] == arr[row - 1][col] && arr[row][col] == arr[row + 1][col] && arr[row][col] == arr[row + 2][col])
			{
				arr[row][col] = shapeSelector1(arr[row][col]);
				arr[row - 1][col] = 0;
				arr[row + 1][col] = 0;
				arr[row + 2][col] = 0;
				score = score + 40;
				SwapToTop(arr, score);
				populateboard(arr);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(arr, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(arr, score);
				}
				flamecheck = 1;
				bool specialcheck2 = 1;
				while (specialcheck2 != 0)
				{
					specialcheck2 = SpecialCheck2(arr, score);
				}
				specialcheck2 = 1;
				PrintBoard(arr, score, -1, -1);
				//cout << "\n -------You made a column of 4 same shapes-------- \n";
				flag = 1;
			}
		}
	}
	return flag;
}

bool SpecialCheck(int arr[][8], int& score)
{
	bool flag = 0;

	for (int row = 0; row < 8; row++)
	{
		for (int col = 1; col < 7; col++)
		{
			if (arr[row][col] == arr[row][col - 1] && arr[row][col] == arr[row][col + 1])
			{
				arr[row][col] = 0;
				arr[row][col - 1] = 0;
				arr[row][col + 1] = 0;
				score = score + 30;
				SwapToTop(arr, score);
				populateboard(arr);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(arr, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(arr, score);
				}
				flamecheck = 1;
				bool specialcheck2 = 1;
				while (specialcheck2 != 0)
				{
					specialcheck2 = SpecialCheck2(arr, score);
				}
				specialcheck2 = 1;
				bool specialcheck1 = 1;
				while (specialcheck1 != 0)
				{
					specialcheck1 = SpecialCheck1(arr, score);
				}
				specialcheck1 = 1;
				flag = 1;
			}
		}
	}
	for (int col = 0; col < 8; col++)
	{
		for (int row = 1; row < 7; row++)
		{
			if (arr[row][col] == arr[row - 1][col] && arr[row][col] == arr[row + 1][col])
			{
				arr[row][col] = 0;
				arr[row - 1][col] = 0;
				arr[row + 1][col] = 0;
				score = score + 30;
				SwapToTop(arr, score);
				populateboard(arr);
				bool destroyercheck = 1;
				while (destroyercheck != 0)
				{
					destroyercheck = DestroyerCheck(arr, score);
				}
				destroyercheck = 1;
				bool flamecheck = 1;
				while (flamecheck != 0)
				{
					flamecheck = FlameCheck(arr, score);
				}
				flamecheck = 1;
				bool specialcheck2 = 1;
				while (specialcheck2 != 0)
				{
					specialcheck2 = SpecialCheck2(arr, score);
				}
				specialcheck2 = 1;
				bool specialcheck1 = 1;
				while (specialcheck1 != 0)
				{
					specialcheck1 = SpecialCheck1(arr, score);
				}
				specialcheck1 = 1;
				flag = 1;
			}
		}
	}
	return flag;
}

bool CheckSets(int arr[][8], int& score, int x, int y, int x1, int y1)
{
	if (arr[x][y] == arr[x - 1][y] && arr[x + 1][y] == arr[x][y])
		return 1;
	else if (arr[x][y] == arr[x][y - 1] && arr[x][y] == arr[x][y + 1])
		return 1;
	else if (arr[x][y] == arr[x - 1][y] && arr[x - 2][y] == arr[x][y])
		return 1;
	else if (arr[x][y] == arr[x][y - 1] && arr[x][y] == arr[x][y - 2])
		return 1;
	else if (arr[x][y] == arr[x + 2][y] && arr[x + 1][y] == arr[x][y])
		return 1;
	else if (arr[x][y] == arr[x][y + 2] && arr[x][y] == arr[x][y + 1])
		return 1;
	else if (arr[x1][y1] == arr[x1 - 1][y1] && arr[x1 + 1][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] == arr[x1][y1 - 1] && arr[x1][y1] == arr[x1][y1 + 1])
		return 1;
	else if (arr[x1][y1] == arr[x1 - 1][y1] && arr[x1 - 2][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] == arr[x1][y1 - 1] && arr[x1][y1] == arr[x1][y1 - 2])
		return 1;
	else if (arr[x1][y1] == arr[x1 + 2][y1] && arr[x1 + 1][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] == arr[x1][y1 + 2] && arr[x1][y1] == arr[x1][y1 + 1])
		return 1;

	/*else if (-arr[x][y] == arr[x - 1][y] && -arr[x + 1][y] == arr[x][y])
		return 1;
	else if (-arr[x][y] == arr[x][y - 1] && -arr[x][y] == arr[x][y + 1])
		return 1;
	else if (-arr[x][y] == arr[x - 1][y] && -arr[x - 2][y] == arr[x][y])
		return 1;
	else if (-arr[x][y] == arr[x][y - 1] && -arr[x][y] == arr[x][y - 2])
		return 1;
	else if (-arr[x][y] == arr[x + 2][y] && -arr[x + 1][y] == arr[x][y])
		return 1;
	else if (-arr[x][y] == arr[x][y + 2] && -arr[x][y] == arr[x][y + 1])
		return 1;
	else if (-arr[x1][y1] == arr[x1 - 1][y1] && -arr[x1 + 1][y1] == arr[x1][y1])
		return 1;
	else if (-arr[x1][y1] == arr[x1][y1 - 1] && -arr[x1][y1] == arr[x1][y1 + 1])
		return 1;
	else if (-arr[x1][y1] == arr[x1 - 1][y1] && -arr[x1 - 2][y1] == arr[x1][y1])
		return 1;
	else if (-arr[x1][y1] == arr[x1][y1 - 1] && -arr[x1][y1] == arr[x1][y1 - 2])
		return 1;
	else if (-arr[x1][y1] == arr[x1 + 2][y1] && arr[x1 + 1][y1] == -arr[x1][y1])
		return 1;
	else if (-arr[x1][y1] == arr[x1][y1 + 2] && -arr[x1][y1] == arr[x1][y1 + 1])
		return 1;*/

	FlameCheck(arr, score);
	DestroyerCheck(arr, score);


	/*else if (arr[x][y] * 10 == arr[x - 1][y] || arr[x + 1][y] == arr[x][y] * 10 && arr[x][y] == arr[x - 1][y] || arr[x + 1][y] == arr[x][y])
		return 1;
	else if (arr[x][y] * 10 == arr[x][y - 1] || arr[x][y] * 10 == arr[x][y + 1] && arr[x][y] == arr[x][y - 1] || arr[x][y] == arr[x][y + 1])
		return 1;
	else if (arr[x][y] * 10 == arr[x - 1][y] || arr[x - 2][y] == arr[x][y] * 10 && arr[x][y] == arr[x - 1][y] || arr[x - 2][y] == arr[x][y])
		return 1;
	else if (arr[x][y] * 10 == arr[x][y - 1] || arr[x][y] * 10 == arr[x][y - 2] && arr[x][y] == arr[x][y - 1] || arr[x][y] == arr[x][y - 2])
		return 1;
	else if (arr[x][y] * 10 == arr[x + 2][y] || arr[x + 1][y] == arr[x][y] * 10 && arr[x][y] == arr[x + 2][y] || arr[x + 1][y] == arr[x][y])
		return 1;
	else if (arr[x][y] * 10 == arr[x][y + 2] || arr[x][y] * 10 == arr[x][y + 1] && arr[x][y] == arr[x][y + 2] || arr[x][y] == arr[x][y + 1])
		return 1;
	else if (arr[x1][y1] * 10 == arr[x1 - 1][y1] || arr[x1 + 1][y1] == arr[x1][y1] * 10 && arr[x1][y1] == arr[x1 - 1][y1] || arr[x1 + 1][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] * 10 == arr[x1][y1 - 1] || arr[x1][y1] * 10 == arr[x1][y1 + 1] && arr[x1][y1] == arr[x1][y1 - 1] || arr[x1][y1] == arr[x1][y1 + 1])
		return 1;
	else if (arr[x1][y1] * 10 == arr[x1 - 1][y1] || arr[x1 - 2][y1] == arr[x1][y1] * 10 && arr[x1][y1] == arr[x1 - 1][y1] || arr[x1 - 2][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] * 10 == arr[x1][y1 - 1] && arr[x1][y1] == arr[x1][y1 - 2] || arr[x1][y1] * 10 == arr[x1][y1 - 2] && arr[x1][y1] == arr[x1][y1 - 1])
		return 1;
	else if (arr[x1][y1] * 10 == arr[x1 + 2][y1]  || arr[x1 + 1][y1] == arr[x1][y1] * 10 && arr[x1][y1] == arr[x1 + 2][y1] || arr[x1 + 1][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] * 10 == arr[x1][y1 + 2] || arr[x1][y1] * 10 == arr[x1][y1 + 1] && arr[x1][y1] == arr[x1][y1 + 2] || arr[x1][y1] == arr[x1][y1 + 1])
		return 1;

	else if (arr[x][y] == arr[x - 1][y] / 10 || arr[x + 1][y] / 10 == arr[x][y] && arr[x][y] == arr[x - 1][y] || arr[x + 1][y] == arr[x][y])
		return 1;
	else if (arr[x][y] == arr[x][y - 1] / 10 || arr[x][y] == arr[x][y + 1] / 10 && arr[x][y] == arr[x][y - 1] || arr[x][y] == arr[x][y + 1])
		return 1;
	else if (arr[x][y] == arr[x - 1][y] / 10 || arr[x - 2][y] / 10 == arr[x][y] && arr[x][y] == arr[x - 1][y] || arr[x - 2][y] == arr[x][y])
		return 1;
	else if (arr[x][y] == arr[x][y - 1] / 10 || arr[x][y] == arr[x][y - 2] / 10 && arr[x][y] == arr[x][y - 1] || arr[x][y] == arr[x][y - 2])
		return 1;
	else if (arr[x][y] == arr[x + 2][y] / 10 || arr[x + 1][y] / 10 == arr[x][y] && arr[x][y] == arr[x + 2][y] || arr[x + 1][y] == arr[x][y])
		return 1;
	else if (arr[x][y] == arr[x][y + 2] / 10 || arr[x][y] == arr[x][y + 1] / 10 && arr[x][y] == arr[x][y + 2] || arr[x][y] == arr[x][y + 1])
		return 1;
	else if (arr[x1][y1] == arr[x1 - 1][y1] / 10 || arr[x1 + 1][y1] / 10 == arr[x1][y1] && arr[x1][y1] == arr[x1 - 1][y1] || arr[x1 + 1][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] == arr[x1][y1 - 1] / 10 || arr[x1][y1] == arr[x1][y1 + 1] / 10 && arr[x1][y1] == arr[x1][y1 - 1] || arr[x1][y1] == arr[x1][y1 + 1])
		return 1;
	else if (arr[x1][y1] == arr[x1 - 1][y1] / 10 || arr[x1 - 2][y1] / 10 == arr[x1][y1] && arr[x1][y1] == arr[x1 - 1][y1] || arr[x1 - 2][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] == arr[x1][y1 - 1] / 10 || arr[x1][y1] == arr[x1][y1 - 2] / 10 && arr[x1][y1] == arr[x1][y1 - 1] || arr[x1][y1] == arr[x1][y1 - 2])
		return 1;
	else if (arr[x1][y1] == arr[x1 + 2][y1] / 10 || arr[x1 + 1][y1] / 10 == arr[x1][y1] && arr[x1][y1] == arr[x1 + 2][y1] || arr[x1 + 1][y1] == arr[x1][y1])
		return 1;
	else if (arr[x1][y1] == arr[x1][y1 + 2] / 10 || arr[x1][y1] == arr[x1][y1 + 1] / 10 && arr[x1][y1] == arr[x1][y1 + 2] || arr[x1][y1] == arr[x1][y1 + 1])
		return 1;*/


	return 0;
}

bool SetBoard(int arr[][8])
{
	bool flag = 0;

	for (int row = 0; row < 8; row++)
	{
		for (int col = 1; col < 7; col++)
		{
			if (arr[row][col] == arr[row][col - 1] && arr[row][col] == arr[row][col + 1])
			{
				arr[row][col] = (rand() % 5 + 1);
				arr[row][col - 1] = (rand() % 5 + 1);
				arr[row][col + 1] = (rand() % 5 + 1);
				flag = 1;
			}
		}
	}
	for (int col = 0; col < 8; col++)
	{
		for (int row = 1; row < 7; row++)
		{
			if (arr[row][col] == arr[row - 1][col] && arr[row][col] == arr[row + 1][col])
			{
				arr[row][col] = (rand() % 5 + 1);
				arr[row - 1][col] = (rand() % 5 + 1);
				arr[row + 1][col] = (rand() % 5 + 1);
				flag = 1;
			}
		}
	}
	return flag;
}

int main()
{
	int box[8][8] = { 0 };
	int score = 0, whichkey = 0, x = 0, y = 0, x1 = 0, y1 = 0;
	bool set = 1, flag = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			box[i][j] = (rand() % 5 + 1);
		}
	}
	PrintBoard(box, score, -1, -1);

	while (set != 0)
	{
		set = SetBoard(box);
	}
	set = 1;
	score = 0;
	int timer = clock() / 1000;
	while(flag == 0)
	{
		PrintBoard(box, score, x, y);

		bool input = 1;
		while (input != 0 && flag == 0)
		{
			int timer = clock() / 1000;
			gotoxy(0, 0);
			cout << "\n   Timer: " << 120 - timer << "s \n\n";
			if (timer > 119)
				flag = 1;
			gotoxy(0, 0);
			int in = 0;
			isCursorKeyPressed(in);
			if (in == 1)
			{
				y--;
				if (y < 0 && x == 0)
				{
					y = 7, x = 7;
				}
				else if (y < 0)
				{
					x--, y = 7;
				}
				PrintBoard(box, score, x, y);
			}
			else if (in == 2)
			{
				x--;
				if (y == 0 && x < 0)
				{
					y = 7, x = 7;
				}
				else if (x < 0)
				{
					x = 7, y--;
				}
				PrintBoard(box, score, x, y);
			}
			else if (in == 3)
			{
				y++;
				if (y > 7 && x == 7)
				{
					y = 0, x = 0;
				}
				else if (y > 7)
				{
					x++, y = 0;
				}
				PrintBoard(box, score, x, y);
			}
			else if (in == 4)
			{
				x++;
				if (y == 7 && x > 7)
				{
					y = 0, x = 0;
				}
				else if (x > 7)
				{
					x = 0, y++;
				}
				PrintBoard(box, score, x, y);
			}
			else if (in == 5)
			{
				input = 0;
				PrintBoard(box, score, x, y);
			}
		}

		input = 1, x1 = x, y1 = y;
		while (input != 0 && flag == 0)
		{
			int timer = clock() / 1000;
			gotoxy(0, 0);
			cout << "\n   Timer: " << 120 - timer << "s \n\n";
			if (timer > 119)
				flag = 1;
			gotoxy(0, 0);
			int in = 0;
			isCursorKeyPressed(in);
			if (in == 1)
			{
				y1--;
				if (y1 < 0 || x1 == x - 1 || x1 == x + 1)
				{
					y1++;
				}
				if (y1 < y - 1)
				{
					y1 = y - 1;
				}
				PrintBoard(box, score, x1, y1);
			}
			else if (in == 2)
			{
				x1--;
				if (x1 < 0 || y1 == y - 1 || y1 == y + 1)
				{
					x1++;
				}
				if (x1 < x - 1)
				{
					x1 = x - 1;
				}
				PrintBoard(box, score, x1, y1);
			}
			else if (in == 3)
			{
				y1++;
				if (y1 > 7 || x1 == x - 1 || x1 == x + 1)
				{
					y1--;
				}
				if (y1 > y + 1)
				{
					y1 = y + 1;
				}
				PrintBoard(box, score, x1, y1);
			}
			else if (in == 4)
			{
				x1++;
				if (x1 > 7 || y1 == y - 1 || y1 == y + 1)
				{
					x1--;
				}
				if (x1 > x + 1)
				{
					x1 = x + 1;
				}
				PrintBoard(box, score, x1, y1);
			}
			else if (in == 5)
			{
				input = 0;
				PrintBoard(box, score, x1, y1);
			}
		}
		if (x1 == x - 1 && y1 == y || x1 == x + 1 && y1 == y || x1 == x && y1 == y - 1 || x1 == x && y1 == y + 1)
		{
			swap(box[x][y], box[x1][y1]);
			if (CheckSets(box, score, x, y, x1, y1) == 0)
			{
				swap(box[x][y], box[x1][y1]);
			}
		}

		PrintBoard(box, score, -1, -1);

		bool destroyercheck = 1;
		while (destroyercheck != 0)
		{
			destroyercheck = DestroyerCheck(box, score);
		}
		destroyercheck = 1;
		bool flamecheck = 1;
		while (flamecheck != 0)
		{
			flamecheck = FlameCheck(box, score);
		}
		flamecheck = 1;
		bool specialcheck2 = 1;
		while (specialcheck2 != 0)
		{
			specialcheck2 = SpecialCheck2(box, score);
		}
		specialcheck2 = 1;
		bool specialcheck1 = 1;
		while (specialcheck1 != 0)
		{
			specialcheck1 = SpecialCheck1(box, score);
		}
		specialcheck1 = 1;
		bool specialcheck = 1;
		while (specialcheck != 0)
		{
			specialcheck = SpecialCheck(box, score);
		}
		specialcheck = 1;

		PrintBoard(box, score, -1, -1);
	}

	gotoxy(0, 0);
	cout << "\n\n\n\n  YOUR TIME IS UP !!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	system("pause");
	_getch();
	return 0;
}