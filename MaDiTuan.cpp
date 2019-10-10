// MaDiTuan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;

# define banco(i,j) Banco[j*(n+4)+i]
void XoaBanCo();
void InBanCo();
void TimDuongTiepTheo(int, int, int);

// n la kich thuoc ban co; x,y la toa do ban dau cua con ma;
int n, x, y;
int *Banco;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };


//bien KT de kiem tra xem bai toan co duong di khong
bool KT = false;
//yeu cau bai toan in ra mot cach di

/* ***************************MAIN**************************************/
int main()
{
	cout << "\n Nhap ban co n*n va vi tri ban dau cua con ma:\n";
	cin >> n;
	cin >> x;
	cin >> y;
	//luu y khi ta nhap van nhap nhu toa do ban co (x,y)tu 0->7
	x += 2;//toa do moi khi them cac o moi vao ban co
	y += 2;
	Banco = new int[(n + 4)*(n + 4)];
	XoaBanCo();
	banco(x, y) = 1;
	long t1 = clock();
	TimDuongTiepTheo(2, x, y);
	long t2 = clock();
	long t3 = t2 - t1;
	if (KT == false)
		cout << "\n Bai toan khong co duong di";
	cout << "\n Thoi gian thuc hien: " << t3;
	_getch();
	return 0;
}



/******************thiet lap trang thai ban dau cua ban co*****************/
void XoaBanCo()
{
	for (int i = 0; i < n + 4; i++)
		for (int j = 0; j < n + 4; j++)
			if (i > 1 && i < n + 2 && j>1 && j < n + 2)
				banco(i, j) = 0;
			else banco(i, j) = -1;
}
/**************in re khi hoan thanh duonc di*****************************/
void InBanCo()
{
	for (int i = 2; i<n + 2; i++)
	{
		printf("\n");
		for (int j = 2; j<n + 2; j++)// vi khi them moi ta duoc ban co(n+4)ne toa do ban co cu luc nay la (x,y)chay tu 2->n+2
			printf("%d\t", banco(i, j));
	}
}
/********************tim duong di cua con ma*****************************/
void TimDuongTiepTheo(int i, int x0, int y0)
{
	if (KT)return;//su dung de dung chuong trinh con khi thu duoc mot nghiem cua bai toan
	for (int k = 0; k<8; k++)
	{
		int x1 = x0 + dx[k];
		int y1 = y0 + dy[k];
		if (banco(x1, y1) == 0)
		{
			banco(x1, y1) = i;
			if (i<n*n)
				TimDuongTiepTheo(i + 1, x1, y1);
			else
			{
				KT = true;
				cout << " \n\n Duong di:\n";
				InBanCo();
				//khi tim duoc mot cach ta thoat khoi chuong trinh dung lenh break;
			}
			banco(x1, y1) = 0;
		}
	}
}