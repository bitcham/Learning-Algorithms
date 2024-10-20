#include <vector>
#include <iostream>
using namespace std;

void Print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> arr = { 5, 2, 7, 3, 8, 5, 6, 4 };
	//vector<int> arr = { 2, 8, 7, 1, 3, 5, 6, 4 };
	//vector<int> arr = { 9, 8, 7, 6, 4, 3, 2, 1, 5 };
	//vector<int> arr = { 5, 2, 7, 3, 4, 4, 6, 4 };

	int lo = 0; 
	int hi = arr.size() - 1;  
	int x = arr[hi]; 

	int i = lo - 1; 

	Print(arr);

	for (int j = lo; j < hi; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[j], arr[i]);
		}
		
	}

	swap(arr[i + 1], arr[hi]);
	Print(arr);

	cout << i + 1 << endl;
}
