//C++�����һЩ��ʽ����
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double d = 1;
	for (int i = 1; i < 20; i++)
	{
		d *= (double)i;
	}
	cout.fixed();
	cout.precision(0);
	cout << d;
}