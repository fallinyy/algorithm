#include <iostream>

using namespace std;

bool isSameSym(int a, int b)
{
	return !(((a ^ b) >> 31) & 1);
}

int divide(int dividend, int divisor)
{
	int res = 0;
	bool is_same_symbol = isSameSym(dividend, divisor);
	if (is_same_symbol) {
		int _neg = dividend < 0 ? -1 : 1;
		int tmp = dividend;
		while ((_neg * tmp) > 0) {
			tmp = tmp - divisor;
			res += 1;
		}
		if (tmp != 0) {
			res = res - (_neg + 1) / 2;
		}
	} else {
		int _neg = dividend < 0 ? -1 : 1;
		int tmp = dividend;
		while ((_neg * tmp) > 0) {
			tmp = tmp + divisor;
			res += -1;
		}
		if (tmp != 0) {
			res = res - (_neg + 1) / 2;
		}
	}
	return res;
}

int main()
{
	/*
	cout << isSameSym(-1, -2) << endl;
	cout << isSameSym(-1, 2) << endl;
	cout << isSameSym(1, -2) << endl;
	cout << isSameSym(1, 2) << endl;
	*/
	cout << divide(5, 8) << endl;
	cout << divide(-5, 8) << endl;
	cout << divide(5, -5) << endl;
	cout << divide(-5, -5) << endl;
	cout << divide(10, 5) << endl;

	return 0;
}
