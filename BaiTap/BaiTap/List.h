#pragma once
#include"PhongKS.h"
#include<sstream>

class List :
	public PhongKS

{
public:
	int n;
	PhongKS *ks;


public:

	void BinarySearch(int x);
	void Sort();
	void ShellSort(bool(*a)(int, int));
	void Nhap();
	void Xuat();
	void Xoa( int);
	void Them(int);
	void ChinhSua(int);

	List(int);
	List();
	~List();
};

