#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <iostream>

using namespace std;

void Print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

void SelectionSortPass(vector<int>& arr, int lo, int hi)
{
	
	for (int j = lo + 1; j <= hi; j++) {
		int min_index = lo;
		if (arr[j] < arr[min_index]) {
			min_index = j;
			swap(arr[lo], arr[min_index]);
		}
	}
	
}

void PartialSelectionSort(vector<int>& arr, int k)
{
	Print(arr);

	for (int i = 0; i < k; i++)
	{
		SelectionSortPass(arr, i, arr.size() - 1);

		Print(arr);
	}
}

int main()
{
	vector<int> my_vector = { 3, 10, 4, 7, 20, 15 };

	int k = 3;

	PartialSelectionSort(my_vector, k);

	cout << my_vector[k - 1] << endl;
}
