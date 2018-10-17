#include<iostream>
#include"List.h"

bool tangdan(int a, int b) {
	return a < b;
}

bool giamdan(int a, int b) {
	return a > b;
}

using namespace std;
int main() {
	int n, a = 0, b = 0, c = 0;
	cout << "Nhap so luong phong: ";
	cin >> n;
	List ks(n);
	PhongKS s1;
	ks.Nhap();
	do
	{
		cout << "--------------!---------------" << endl;
		cout << "1. In ra cac phong" << endl;
		cout << "2. Sap xep cac phong" << endl;
		cout << "3. Tim phong" << endl;
		cout << "4. Them phong" << endl;
		cout << "5. Xoa phong" << endl;
		cout << "6. Chinh sua du lieu phong" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "--------------!---------------" << endl;
		cout << "Chon yeu cau thuc hien" << endl;
		cin >> a;
		if (a == 0) break;
		switch (a)
		{
		case 1:
			ks.Xuat();
			break;

		case 2:
			do
			{
				cout << "Chon kieu sap xep:" << endl << "1. Tang dan" << endl << "2. Giam dan" << endl;
				cin >> b;
				if (b == 1) { 
					ks.ShellSort(tangdan); 
					break;
				}
				else
				{
					if (b == 2) ks.ShellSort(giamdan);
					break;
				}

			} while (b != 1 || b != 2);
			break;
			
		case 3:
			cout << "Tim kiem phong theo so nguoi toi da cua phong:" << endl;
			cin >> c;
			ks.BinarySearch(c);
			break;
	
		case 4:
			cout << "Nhap vi tri muon them: " << endl;
			cin >> c;
			ks.Them(c);
			break;

		case 5:
			cout << "Nhap vi tri muon xoa: " << endl;
			cin >> c;
			ks.Xoa(c);
			break;

		case 6:
			cout << "Ban muon chinh sua du lieu phong nao:" << endl;
			cin >> c;
			ks.ChinhSua(c);
			break;
		case 0:
			break;
			
		default:
			break;
		}
	} while (a != 0);

	


	system("pause");
	return 0;
}