#include <iostream>
using namespace std;

int Fibo(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	int num;
	cout << "수 입력 : ";
	cin >> num;

	cout << num << "번째 피보나치 수 :  ";
	cout << Fibo(num) << endl;
}