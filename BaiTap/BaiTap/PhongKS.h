#pragma once
#include<iostream>
#include"Date.h"
#include<string>
#include<sstream>

using namespace std;

class PhongKS
{
public:
	string mPhong;
	int sNguoi;
	bool tTrang;
	Date nNhan;
	Date nTra;
	double gia;

public:
	PhongKS();
	void update(string, int, bool, Date, Date, double);
	friend ostream & operator<<(ostream&, PhongKS&);
	friend istream & operator>>(istream&, PhongKS&);

	virtual ~PhongKS();
};

