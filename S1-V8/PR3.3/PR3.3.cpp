// PR3/3.cpp
// ������� �������
// ����������� ������ �3.3
// ������������, ������ �������� �������.
// ������ 8

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // ������� ��������
	double R; // ������� ��������
	double y; // ��������� ���������� ������
	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;
	
	// ������������ � ����� ����
	if (x <= -8)
		y = -R;
	else
		if (-8 < x && x <= -R)
			y = -8 - (R / (R + 8)) * (x + 8);
		else
			if (-R < x && x <= R)
				y = (R, 2) - (x, 2);
			else
				if (R < x && x <= 5)
					y = 2 / 5 * (x - R);
				else
					y = 2;
	cout << endl;
	cout << "y = " << y << endl;
	cin.get();
	return 0;
}