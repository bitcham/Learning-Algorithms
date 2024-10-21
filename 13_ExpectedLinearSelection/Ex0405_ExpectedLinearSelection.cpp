#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Print(vector<int>& arr, int lo, int hi, string sep = "")
{
	cout << "Value: ";
	for (int i = 0; i < arr.size(); i++) {

		if (lo <= i && i <= hi)
			cout << setfill(' ') << setw(3) << arr[i] << sep;
		else
			cout << "   ";
	}
	cout << endl;
}

int Partition(vector<int>& arr, int lo, int hi)
{
	int x = arr[hi];
	int i = lo - 1;
	for (int j = lo; j < hi; j++)
	{
		if (arr[j] <= x)
		{
			i += 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[hi]);

	return i + 1;
}

int RandomizedSelect(vector<int>& arr, int lo, int hi, int k)
{
	if (lo == hi) return arr[lo];

	int index = Partition(arr, lo, hi);

	if (index - lo == k - 1) return arr[index];
	else if (k - 1 < index - lo) return RandomizedSelect(arr, lo, index - 1, k);
	else
		return RandomizedSelect(arr, index + 1, hi, k - index + lo - 1);
}

int main() {
	//vector<int> my_vector = { 6, 19, 4, 12, 14, 9, 15, 7, 8, 11, 3, 13, 2, 5, 10 };
	//vector<int> my_vector = { 4, 19, 4, 12, 2, 9, 15, 2, 8, 11, 3, 1, 2, 1, 10 };
	vector<int> my_vector = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	Print(my_vector, 0, my_vector.size() - 1);

	cout << RandomizedSelect(my_vector, 0, my_vector.size() - 1, std::ceil(my_vector.size() / 2.0)) << endl;


	return 0;
}