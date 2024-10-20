#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric> // std::iota

using namespace std;

void Print(vector<int>& arr, int lo, int hi)
{


	for (int i = 0; i < lo; i++)
		cout << "   ";
	for (int i = lo; i <= hi; i++)
		cout << setfill(' ') << setw(3) << arr[i];
	cout << endl;
}

bool CheckSorted(vector<int>& a)
{
	for (int i = 0; i < a.size() - 1; i++)
	{
		if (a[i] > a[i + 1])
			return false;
	}

	return true;
}

class BottomupMerge
{
public:
	void Sort(vector<int>& a)
	{
		aux.resize(a.size());

		int N = a.size();
		for (int sz = 1; sz < N; sz = sz + sz) {
			for (int lo = 0; lo < N - sz; lo += sz + sz) {
				Merge(a, lo, lo + sz - 1, std::min(lo + sz + sz - 1, N - 1));
			}
		}

		
	}

private:
	void Merge(vector<int>& a, int lo, int mid, int hi)
	{
		cout << "Before: ";
		Print(a, lo, hi);

		int i = lo;
		int j = mid + 1;

		for (int k = lo; k < hi; k++) {
			aux[k] = a[k];
		}
		
		for (int k = lo; k < hi; k++) {
			if (i > mid) a[k] = aux[j++];
			else if (j > hi) a[k] = aux[i++];
			else if (aux[j] < aux[i]) a[k] = aux[j++];
			else a[k] = aux[i++];
		}

		cout << "After : ";
		Print(a, lo, hi);

	}

	vector<int> aux; 
};

int main()
{
	vector<int> my_vector(16);
	std::iota(my_vector.begin(), my_vector.end(), 0);
	std::reverse(my_vector.begin(), my_vector.end());

	cout << "        ";
	Print(my_vector, 0, my_vector.size() - 1);

	BottomupMerge merge;
	merge.Sort(my_vector);

	cout << "        ";
	Print(my_vector, 0, my_vector.size() - 1);
}
