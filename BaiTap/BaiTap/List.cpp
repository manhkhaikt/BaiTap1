#include "List.h"

inline int string_to_int(string s)
{
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

List::List(int n)
{
	this->n = n;
	this->ks = new PhongKS[this->n];
}

List::List()
{
}


void List::BinarySearch( int x)
{
	Sort();
	
	int a = 0;
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == this->ks[mid].sNguoi){
			a = 1;
			cout << "Phong can tim: " << endl;
			cout << this->ks[mid];
			
		}
		if (x < this->ks[mid].sNguoi)
		{
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	if (a == 0) {
		cout << "Khong tim thay phong chi dinh" << endl;
	}
}

void List::Sort()
{
	int c, i, j;
	PhongKS *b = new PhongKS[this->n];

	for (c = this->n / 2; c > 0; c /= 2) {
		for (i = c; i < n; i++) {
			for (j = i; j >= c; j -= c) {
				if (this->ks[j].sNguoi < this->ks[j - c].sNguoi) {
					*(b + i) = this->ks[j];
					this->ks[j] = this->ks[j - c];
					this->ks[j - c] = *(b + i);
				}
			}
		}
	}
}



void List::ShellSort(bool(*a)(int, int))
{
	int c, i, j;
	PhongKS *b = new PhongKS[this->n];

	for (c = this->n / 2; c > 0; c /= 2) {
		for (i = c; i < n; i++) {
			for (j = i; j >= c; j -= c) {
				if (a(this->ks[j].sNguoi, this->ks[j - c].sNguoi)) {
					*(b+i) = this->ks[j];
					this->ks[j] = this->ks[j - c];
					this->ks[j - c] = *(b+i);
				}
			}
		}
	}
}

void List::Nhap()
{
	cout << "--------------!--------------" << endl;
	for (int i = 0; i < this->n; i++)
	{
		cout<<"Phong thu " << i + 1 << endl;
		cin >> this->ks[i];
	}
}

void List::Xuat()
{
	cout << "--------------!--------------" << endl;
	for (int i = 0; i < this->n; i++)
	{
		cout << "Phong thu" << i + 1 << endl;
		cout << this->ks[i];
	}
}

void List::Xoa(int t)
{
	PhongKS *a = new PhongKS[this->n];
	for (int i = 0; i < this->n; i++) {
		*(a + i) = this->ks[i];
	}

	delete[] this->ks;
	this->n -= 1;
	this->ks = new PhongKS[this->n];

	for (int i = 0; i < t - 1; i++) {
		*(this->ks + i) = *(a + i);
	}
	for (int i = t - 1; i < this->n; i++) {
		*(this->ks + i) = *(a + i + 1);
	}

}

void List::Them(int t)
{
	PhongKS *a = new PhongKS[this->n];
	for (int i = 0; i < this->n; i++) {
		*(a + i) = this->ks[i];
	}
	delete[] this->ks;
	this->n += 1;
	this->ks = new PhongKS[this->n];
	for (int i = 0; i < t - 1; i++) {
		*(this->ks + i) = *(a + i);
	}
	cin >> this->ks[t - 1];
	for (int i = t; i < this->n; i++) {
		*(this->ks + i) = *(a + i - 1);
	}
	

}

void List::ChinhSua(int t)
{
	string a;
	int b;
	bool c;
	Date d;
	Date e;
	double f;
	int z = 0;

	cin.ignore(1);
	do {
		cout << "Ma Phong moi: ";
		getline(cin, a);

		z = string_to_int(a);
	} while (z < 10001 || z > 59999);

	do {
		cout << "So nguoi thoi da:";
		cin >> b;
	} while (b < 1 || b>4);

	cout << "Tinh trang phong: ";
	cin >> c;
	if (c == false) {
		cout << "Ngay nhan phong: " << endl;
		cin >> d;

		cout << "Ngay tra phong: " << endl;
		cin >> e;

	}
	do
	{
		cin >> f;
	} while (f < 0);
	this->ks[t - 1].update(a, b, c, d, e, f);

}





List::~List()
{
	delete[] this->ks;
}
