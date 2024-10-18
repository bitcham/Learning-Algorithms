#include <string>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

string Add(string str1, string str2)
{
	if (!str1.size() && !str2.size()) return "0";

	int N = max(str1.size(), str2.size());
	str1.insert(0, string(N - str1.size(), '0'));
	str2.insert(0, string(N - str2.size(), '0'));

	string result(N, '0');

	int carry = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		int n1 = str1[i] - '0';
		int n2 = str2[i] - '0';
		int sum = n1 + n2 + carry;
		carry = sum / 10;
		result[i] = sum % 10 + '0';
	}

	if (carry > 0)
		result.insert(0, string(1, carry + '0'));

	return result;
}

string Subtract(string str1, string str2)
{
	if (str1 == str2) return "0";

	int N = max(str1.size(), str2.size());
	str1.insert(0, string(N - str1.size(), '0'));
	str2.insert(0, string(N - str2.size(), '0'));

	string result(N, '0');

	int carry = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		int n1 = str1[i] - '0';
		int n2 = str2[i] - '0';
		int sum = n1 - n2 + carry + 10;
		carry = sum / 10 - 1;
		result[i] = sum % 10 + '0';
	}

	int i = 0;
	while (result[i] == '0') i += 1;
	result = result.substr(i, N - i);

	return result;
}

string KaratsubaHelper(string str1, string str2, int level) 
{
	cout << "Level " << level << " : " << str1 << " x " << str2 << endl;

	int N = max(str1.size(), str2.size());
	str1.insert(0, string(N - str1.size(), '0'));
	str2.insert(0, string(N - str2.size(), '0'));

	if (N == 1)
	{
		string result = to_string(stoi(str1) * stoi(str2));
		return result;
	}

	int mid = N / 2;

	string a = str1.substr(0, mid);
	string b = str1.substr(mid, N - mid);

	string c = str2.substr(0, mid);
	string d = str2.substr(mid, N - mid);

	string ac = KaratsubaHelper(a, c, level + 1);
	string bd = KaratsubaHelper(b, d, level + 1);
	string z = KaratsubaHelper(Add(a, b), Add(c, d), level + 1);
	string temp = Subtract(z, Add(ac, bd));

	

	ac.append(string((N - mid) * 2, '0'));
	temp.append(string(N - mid, '0'));

	string result = Add(Add(ac, temp), bd);


	//int ai = stoi(a);
	//int bi = stoi(b);
	//int ci = stoi(c);
	//int di = stoi(d);
	//int tempi = ai * di + bi * ci;
	//cout << "Ref " << str1 << " x " << str2 << " = "
	//	<< ai * ci << " + " << tempi << " + " << bi * di << " = " << ai * ci + tempi + bi * di << endl;
	//cout << "Result " << str1 << " x " << str2 << " = "
	//	<< ac << " + " << temp << " + " << bd << " = " << result << endl;
	// assert(stoi(result) == stoi(str1) * stoi(str2));

	return result;
}

string Karatsuba(string str1, string str2)
{
	if (!str1.size() || !str2.size()) return "0";

	string result = KaratsubaHelper(str1, str2, 0); 

	int i = 0;
	while (result[i] == '0') i += 1;
	result = result.substr(i, result.size() - i);

	return result;
}

int main()
{
	vector<vector<string>> tests = {
		{"1234", "5678", std::to_string(1234 * 5678)}
		, {"12", "34", std::to_string(12 * 34)}
		, {"123", "2", std::to_string(123 * 2)}
		, {"123", "45", std::to_string(123 * 45)}
		, {"110", "110", std::to_string(110 * 110)}
		, {"5555", "55", std::to_string(5555 * 55)}
		, {"5555", "5555", std::to_string(5555 * 5555)}
		, {"98234712354214154", "171454654654655", "16842798681791158832220782986870"}
		// , {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "16842798681791114273590624445460185389471221520083884298838480662480"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];
		const string str2 = t[1];
		const string expected = t[2];

		cout << str1 << " * " << str2 << " = " << expected << endl;

		const string result = Karatsuba(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK";
		else {
			cout << "Not OK";
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
