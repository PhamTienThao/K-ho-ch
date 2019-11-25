// MADITUAN.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;

//Các biến toàn cục được sử dụng
struct vitri
{
	int x, y, num;
};
int Banco[20][20];
int x, y, xx, yy, sobuocdichuyen, kieudichuyen, N =8;
int X[8] = { 1,2,2,1,-1,-2,-2,-1 };
int Y[8] = { 2,1,-1,-2,-2,-1,1,2 };
vitri a[100];
int top;
int num = 0;

//8. In kết quả con mã đi trên bàn cờ 
void Inbanco()
{

	cout << endl << endl << endl;

	for (int i = 2; i <10; i++)
	{
		for (int j = 2; j < 10; j++)
		{
			cout << "\t" << Banco[i][j];
		}
		cout << endl << endl;
	}
}
//9. Kiểm tra xem có đi được hay ko
void Khoitaobanco()
{
	int i; int j;
	 //In 2 cột trái phải
	for (i = 0; i < 12; i++)
		for (j = 0; j < 2; j++)
		{
			Banco[i][j] = -1;
		}
	for (i = 0; i < 12; i++)
		for (j = 10; j < 12; j++)
		{
			Banco[i][j] = -1;
		}
	// In 2 dòng trên dưới
	for (i = 0; i < 2; i++)
		for (j = 2; j < 10; j++)
		{
			Banco[i][j] = -1;
		}
	for (i = 10; i < 12; i++)
		for (j = 2; j < 10; j++)
		{
			Banco[i][j] = -1;
		}

}
//10. 8 trường hợp đi của quân mã


int main()
{
	double time;
	cout << "Kich thuoc ban co NxN: 8x8" <<endl;
	int STMAX = N*N;
	Khoitaobanco();
	top = -1;
	int xt; int yt;
	do
	{
		if (x >= 10 || y >= 10)
		{
			cout << ">>>> Luu y: Nhap hang va cot luon nho hon " << N << "! <<<<" << endl;
			cout << "Moi ban nhap lai: " << endl;
			cout << "Nhap vi tri hang muon bat dau: ";
			cin >> xt;
			x = xt + 2;
			cout << "Nhap vi tri cot muon bat dau: ";
			cin >> yt;
			y = yt + 2;
		}
		else
		{
			cout << "Nhap vi tri hang muon bat dau: ";
			cin >> xt;
			x = xt + 2;
			cout << "Nhap vi tri cot muon bat dau: ";
			cin >> yt;
			y = yt + 2;
		}
	} while (x >= 10 || y >= 10);
	Banco[x][y] = 1;		//Điểm đầu tiên gán bằng 1
	sobuocdichuyen = 1;		//Số bước di chuyển
	unsigned long t = clock();
	while (sobuocdichuyen < N*N)
	{
		for (int num = 0; num <=8; num++)
		{

			xx = x + X[num];
			yy = y + Y[num];
			if ((num < 8) && (Banco[xx][yy] == 0))
			{
				sobuocdichuyen++;
				top++;
				x = xx;
				y = yy;
				a[top].num = num;
				a[top].x = x;
				a[top].y = y;
				break;
			}
			if (num == 8)
			{
				if (top != 0)
				{
					Banco[x][y] = 0;
					sobuocdichuyen--;
					top--;
					x = a[top].x;
					y = a[top].y;
					num = a[top + 1].num;
				}
				else
				{
					cout << "Khong ton tai nuoc di phu hop!" << endl;
					exit(-1);
				}
			}
		}
		Banco[x][y] = sobuocdichuyen;
	}
		Inbanco();
		time = ((double)(clock() - t)) / CLOCKS_PER_SEC;
		cout << endl << endl << "\t\t\t Thoi gian chay = " << time << " giay. " << endl;
		_getch();
	return 0;
}




