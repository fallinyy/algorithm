#include <iostream>
#include <string>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int myAtoi(string str)
{
	long res = 0;
	if (str.empty()) {
		return res;
	}

	bool is_neg = false;
	bool is_start = false;
	for (auto &c:str) {
		if (c == ' ' && !is_start) {
			continue;
		}
		if (!is_start) {
			if (c == '-') {
				is_neg = true;
			} else if (c == '+') {
				;	
			} else if (c >= '0' && c <= '9') {
				res = (c - '0');
			} else {
				break;
			}
		} else {
			if (c >= '0' && c <= '9') {
				res = res * 10 + (c - '0') * (is_neg ? -1 : 1);
			} else {
				break;
			}
		}
		if (res > INT_MAX) {
			res = INT_MAX;
			break;
		}
		if (res < INT_MIN) {
			res = INT_MIN;
			break;
		}
		is_start = true;
	}

	return res;
}

string reverseWord(string s)
{
	if (s.empty()) return s;

	string res;
	int pos = s.size()-1;
	int start=pos+1, end=pos;

	while (pos >= 0) {
		char c = s[pos];
		if (c == ' ') {
			if (start >= end) {
				end--;
			} else {
				string tmp = s.substr(start+1, end-start);
				res = res + " " + tmp;
				end = pos - 1;
				start = pos;
			}
		} else {
			if (start < end) {
				start--;
			} else {
				end = pos;
				start = end - 1;
			}
		}
		pos--;
	}
	if (start < end) {
		string tmp = s.substr(start+1, end-start);
		res = res + " " + tmp;
	}
	
	return res == "" ? res : res.substr(1, res.size()-1);
}

int main()
{
	cout << reverseWord("  hello world !") << endl;
	cout << reverseWord("  hello world ! ") << endl;
	cout << reverseWord("hello world ! ") << endl;
	cout << reverseWord("hello world !") << endl;
	cout << reverseWord("   ") << endl;
	/*
	cout << myAtoi("123") << endl;
	cout << myAtoi("-123") << endl;
	cout << myAtoi("    -123") << endl;
	cout << myAtoi("word and -123") << endl;
	cout << myAtoi("-123 and word") << endl;
	cout << myAtoi("91283472332") << endl;
	cout << myAtoi("-91283472332") << endl;
	*/
	return 0;
}
