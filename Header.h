//#pragma once
//
//using namespace std;
//
//void timer()
//{
//	for (int i = 60; i >= 0; i--)
//	{
//		cout << "time : " << i;
//		Sleep(1000);
//		system("cls");
//	}
//}
//
//void populateboard(int board[][8])
//{
//	srand(time(0));
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (board[i][j] == 0)
//			{
//				board[i][j] = (rand() % 6) + 1;
//			}
//		}
//	}
//}
//
//void printarray(int board[][8])
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			cout << board[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void Horizontalcheck(int board[][8])
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
//			{
//				board[i][j] = 0;
//				board[i][j + 1] = 0;
//				board[i][j + 2] = 0;
//				if (i != 0)
//				{
//					for (int k = i; k > 0; k--)
//					{
//						swap(board[k][j], board[k - 1][j]);
//						swap(board[k][j + 1], board[k - 1][j + 1]);
//						swap(board[k][j + 2], board[k - 1][j + 2]);
//					}
//				}
//			}
//		}
//	}
//}
//
//void Verticalcheck(int board[][8])
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
//			{
//				board[i][j] = 0;
//				board[i + 1][j] = 0;
//				board[i + 2][j] = 0;
//				if (i != 0)
//				{
//					for (int k = i; k > 0; k--)
//					{
//						swap(board[k][j], board[k - 1][j]);
//						swap(board[k + 1][j], board[k][j]);
//						swap(board[k + 2][j], board[k + 1][j]);
//					}
//				}
//			}
//		}
//	}
//}