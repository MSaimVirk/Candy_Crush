//#include<Windows.h>
//#include <iostream>
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
//				board[i][j] = (rand() % 5) + 1;
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
//bool CheckHorizontal(int board[][8])
//{
//	int count;
//	bool flag = 0;
//	bool found = 0;
//	for (int i = 0; i < 8 && flag == 0; i++)
//	{
//		count = 0;
//		for (int j = 0; j < 8 && flag == 0; j++)
//		{
//			if (j < 6)
//			{
//				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != 0)
//				{
//					bool f = 1;
//					found = 1;
//					flag = 1;
//					count = 3;
//					for (int l = j + 3; l < 8 && f == 1; l++)
//					{
//						if (board[i][j] == board[i][l])
//						{
//							board[i][l] = 0;
//							count++;
//						}
//						else
//							f = 0;
//					}
//					board[i][j] = 0;
//					board[i][j + 1] = 0;
//					board[i][j + 2] = 0;
//				}
//			}
//		}
//	}
//	return found;
//}
//
//bool CheckVertical(int board[][8])
//{
//	int count;
//	bool flag = 0;
//	bool found = 0;
//	for (int i = 0; i < 8 && flag == 0; i++)
//	{
//		count = 0;
//		for (int j = 0; j < 8 && flag == 0; j++)
//		{
//			if (j < 6)
//			{
//				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] != 0)
//				{
//					bool f = 1;
//					found = 1;
//					flag = 1;
//					count = 3;
//					for (int l = i + 3; l < 8 && f == 1; l++)
//					{
//						if (board[i][j] == board[l][j])
//						{
//							board[l][j] = 0;
//							count++;
//						}
//						else
//							f = 0;
//					}
//					board[i][j] = 0;
//					board[i + 1][j] = 0;
//					board[i + 2][j] = 0;
//				}
//			}
//		}
//	}
//	return found;
//}
//
//void SwapToTop(int b[][8])
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (b[i][j] == 0)
//			{
//				for (int k = i; k > 0; k--)
//				{
//					swap(b[k][j], b[k - 1][j]);
//				}
//			}
//		}
//	}
//}
//
//void checks(int board[][8])
//{
//	bool Horizontalfound = 1, Verticalfound = 1;
//	while (Horizontalfound == 1 || Verticalfound == 1)
//	{
//		Horizontalfound = CheckHorizontal(board);
//		SwapToTop(board);
//		Verticalfound = CheckVertical(board);
//		SwapToTop(board);
//	}
//
//}