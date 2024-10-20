#include <string>
#include <vector>
#include <iostream>

using namespace std;
string Add(string str1, string str2)
{

    if (!str1.size() && !str2.size())
        return "0"; 

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

        result[i] = char(sum % 10 + '0');        
    }

    if (carry > 0)
        result.insert(0, string(1, carry + '0'));

    return result;
}

int main()
{
	vector<vector<string>> tests = {
		{"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		, {"54544", "44545", to_string(54544 + 44545)}
		, {"5555", "55", to_string(5555 + 55)}
		, {"5555", "5555", to_string(5555 + 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];     // "12"
		const string str2 = t[1];     // "34"
		const string expected = t[2]; // "46"

		cout << str1 << " + " << str2 << " = " << expected << endl;

		const string result = Add(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK" << endl;
		else {
			cout << "Not OK" << endl;
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
