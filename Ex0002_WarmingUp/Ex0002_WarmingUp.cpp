#include <iostream>
#include <string>
using namespace std;

int main()
{
	{
		int decimal = 105;
		string binary;
		string temp;
		while (decimal > 0) {
			int r = decimal % 2;
			binary = string(1, r + '0') + binary;
			decimal /= 2;
		}
		

		cout << binary << endl; // 1101001
	}

	{
		string input = "Hello, World!";
		int left = 0;
		int right = input.size() - 1;
		while (left < right) {
			swap(input[left], input[right]);
			left++;
			right--;
		}
		cout << input << endl; // !dlroW ,olleH
	}

	{
		string n = "789789";
		
		while (n.size() > 1) {
			int a = 0;
			for (int i = 0; i < n.size(); i++) {
				a += n[i] - '0';
			}
			n = to_string(a);
		}

		cout << n << endl;
	}

	return 0;
}
