#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
using namespace std;

void SelectionSortPass(vector<int>& arr, int lo, int hi, int stride = 1) {
	int min_index = lo;
	for (int j = lo + stride; j <= hi; j += stride) {
		if (arr[j] < arr[min_index])
			min_index = j;
	}
	swap(arr[lo], arr[min_index]);
}

void PrintGroups(vector<int>& arr, int lo, int g) {
	for (int j = lo; j < lo + g; j++) {
		cout << "Group " << j - lo + 1 << " : ";
		for (int l = 0; l < 5; l++)
			cout << arr[j + l * g] << " ";
		cout << endl;
	}
}

int Partition(vector<int>& arr, int lo, int hi) {
	int x = arr[hi];
	int i = lo - 1;
	for (int j = lo; j < hi; j++) {
		if (arr[j] <= x) {
			i += 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[hi]);
	return i + 1;
}
struct Pair
{
	int index;
	int value;
};

Pair Select(vector<int>& arr, int lo, int hi, int k) {
	while ((hi - lo + 1) % 5 != 0)
	{
		SelectionSortPass(arr, lo, hi);
		if (k == 1) return { lo , arr[lo] };
		lo += 1;
		k -= 1;
	}
	int g = (hi - lo + 1) / 5;

	PrintGroups(arr, lo, g);

	int stride = 5;
	for (int i = lo; i < hi; i++) {
		SelectionSortPass(arr, i, hi, g);
	}

	PrintGroups(arr, lo, g);

	Pair x = Select(arr, lo + 2 * g, lo + 3 * g - 1, ceil(g / 2.0));

	swap(arr[x.index], arr[hi]);

	int index = Partition(arr, lo, hi);

	if (index - lo == k - 1) return Pair{ index, arr[index] };
	else if (k - 1 < index - lo) return Select(arr, lo, index - 1, k);
	else return Select(arr, index + 1, hi, k - index + lo - 1);
}
int main() {
	vector<int> my_vector(25);
	iota(my_vector.begin(), my_vector.end(), 0);
	reverse(my_vector.begin(), my_vector.end());

	cout << "Median = " << Select(my_vector, 0, my_vector.size() - 1, ceil(my_vector.size() / 2.0)).value << endl;

	return 0;
}