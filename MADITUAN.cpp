// MADITUAN.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;
//Định nghĩa cấu trúc cho 1 STACK
struct STACK {
	int a[100];		//Mảng các phần tử của ngăn xếp
	int top;		//Chỉ số phần tử đỉnh đầu của ngăn xếp
}; 

//Các biến toàn cục được sử dụng
int Banco[20][20];			
int x, y, xx, yy, sobuocdichuyen, kieudichuyen, N;

//Các hàm được sử dụng
//1. Tạo ngăn xếp rỗng
void KhoitaoStack(STACK &Stack) // Khởi tạo stack rỗng
{
	Stack.top = 0;	// Stack rỗng khi top = 0
}
//2. Kiểm tra ngăn xếp rỗng hay không?
int  ktstackrong(STACK &Stack)
{
	return (Stack.top == 0);	// Stack rỗng còn lại thì stack không rỗng
}
//3. Kiểm tra ngăn xếp đầy hay không?
int  ktstackday(STACK &Stack, int STMAX)
{
	if (Stack.top >= STMAX - 1) return 1;	// Stack đầy
	else return 0;							// Stack chưa đầy
}
//4. Thêm 1 phần tử vào ngăn xếp
void themptvaostack(STACK &Stack, int x, int STMAX)
{
	if (ktstackday(Stack, STMAX)) cout << "Ngan xep day";
	else
	{
		Stack.a[Stack.top + 1] = x;
		Stack.top++;
	}
}
//5. Lấy thông tin phần tử ở đỉnh ngăn xếp
int  laythongtinptdau(STACK Stack)
{
	return Stack.a[Stack.top];
}
//6. Trích hủy phần tử ở đỉnh ngăn xếp
int  xoaphantudau(STACK &Stack)
{
	int t = Stack.a[Stack.top];
	Stack.top--;
	return t;
}
//7. Khởi tạo bàn cờ
void Khoitaobanco(int N)
{
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			Banco[i][j] = 0;
}
//8. In kết quả con mã đi trên bàn cờ 
void Inbanco(int N)
{

	cout << endl << endl << endl;

	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j<N; j++) {
			cout << "\t" << Banco[i][j];
		}
		cout << endl << endl;
	}
}
//9. Kiểm tra xem có đi được hay ko
int kiemtrabuocdi(int N)
{
	return ((xx >= 0) && (xx < N) &&
		(yy >= 0) && (yy < N) &&
		(Banco[xx][yy] == 0));
}
//10. 8 trường hợp đi của quân mã
void truonghopdichuyen(int th)
{
	switch (th) 
	{
	case 1:
		xx = x + 1;
		yy = y + 2;
		break;
	case 2:
		xx = x + 2;
		yy = y + 1;
		break;
	case 3:
		xx = x + 2;
		yy = y - 1;
		break;
	case 4:
		xx = x + 1;
		yy = y - 2;
		break;
	case 5:
		xx = x - 1;
		yy = y - 2;
		break;
	case 6:
		xx = x - 2;
		yy = y - 1;
		break;
	case 7:
		xx = x - 2;
		yy = y + 1;
		break;
	case 8:
		xx = x - 1;
		yy = y + 2;
		break;
	default:
		cout << "Buoc di khong hop le!"<<endl;
		exit(-1);
	}
}
//11.Truy xuất lại nước đi
void quaylui(STACK &Stack)
{
	int thdichuyen;
	if (!ktstackrong(Stack))				//Kiểm tra stack rỗng hay không
		kieudichuyen = xoaphantudau(Stack);	// Nếu ko thì lấy nước đi ra khỏi stack
	else
	{
		cout << "Khong ton tai nuoc di phu hop!" << endl;
		exit(-1);							//Ngược lại thì dừng chương trình	
	}
	Banco[x][y] = 0;						//gán lại vị trí bắt đầu
	thdichuyen = (kieudichuyen + 4) % 8;	// gán lại bước đi mới
	if (thdichuyen == 0)					// kiểm tra bước đi mới
		thdichuyen = 8;
	truonghopdichuyen(thdichuyen);			// Thử bước đi
	x = xx;									// gán lại vị trí mới
	y = yy;
	sobuocdichuyen--;						// lùi lại số nước đi
}
//12. Tìm nước đi của quân mã
void timduongdi(STACK &Stack, int &kieudichuyen, int N)
{
	do {
		while ( kieudichuyen == 8)			//Nếu đã đi hết các kiểu nước đi
		{
			quaylui(Stack);					//Quay lui
		}
		kieudichuyen++;
		truonghopdichuyen(kieudichuyen);	//kiểm tra trường hợp khác để đi tiếp	
	} while (!kiemtrabuocdi(N));
}

int main()
{
	double time;
	cout << "Nhap kich thuoc ban co NxN: ";
	cin >> N;
	int STMAX = N*N;
	STACK Horse;
	Khoitaobanco(N);
	KhoitaoStack(Horse);
	do
	{
		if (x >= N || y >= N)
		{
			cout << ">>>> Luu y: Nhap hang va cot luon nho hon " << N << "! <<<<" << endl;
			cout << "Moi ban nhap lai: " << endl;
			cout << "Nhap vi tri hang muon bat dau: ";
			cin >> x;
			cout << "Nhap vi tri cot muon bat dau: ";
			cin >> y;
		}
		else
		{
			cout << "Nhap vi tri hang muon bat dau: ";
			cin >> x;
			cout << "Nhap vi tri cot muon bat dau: ";
			cin >> y;
		}		
	} while (x >= N || y >= N);
		Banco[x][y] = 1;		//Điểm đầu tiên gán bằng 1
		sobuocdichuyen = 2;		//Số bước di chuyển
		unsigned long t = clock();
		do {
			timduongdi(Horse, kieudichuyen, N);
			themptvaostack(Horse, kieudichuyen, STMAX);
			x = xx;
			y = yy;
			kieudichuyen = 0;
			Banco[x][y] = sobuocdichuyen++;
			/*if (sobuocdichuyen == 38)
			{
				Inbanco(N);
				_getch();
			}*/
			if (sobuocdichuyen > N*N) {
				Inbanco(N);
				time = ((double)(clock() - t)) / CLOCKS_PER_SEC;
				cout << endl << endl << "\t\t\t Thoi gian chay = " << time << " giay. " << endl;
				_getch();
			}
		} while (sobuocdichuyen <= N * N);
    return 0;
}


