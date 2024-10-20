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

int Count1(const vector<int>& arr, int x)
{
	//O(n)
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == x) cnt++;
	}
	return cnt;
}

int BinarySearch(const vector<int>& arr, int lo, int hi, int x) {
	while (lo <= hi) {
		int middle = lo + (hi - lo) / 2;
		if (x < arr[middle]) hi = middle - 1;
		else if (x > arr[middle]) lo = middle + 1;
		else return middle;
	}
	return - 1;
}

int Count2(const vector<int>& arr, int x)
{
	//O(log(n) + count)
	
	int i = BinarySearch(arr, 0, arr.size() - 1, x);

	if (i == -1) return 0;
	
	int cnt = 1;
	int left = i - 1;
	while (left >= 0 && arr[left] == x) {
		cnt++;
		left--;
	}

	int right = i + 1;
	while (right < arr.size() && arr[right] == x) {
		cnt++;
		right++;
	}
	

	return cnt;
}

int FindFirst(const vector<int>& arr, int lo, int hi, int x) {
	if (lo <= hi) {
		int n = arr.size();
		int mid = lo + (hi - lo) / 2;
		if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x) return mid;
		else if (x > arr[mid])
			return FindFirst(arr, (mid + 1), hi, x);
		else return FindFirst(arr, lo, (mid - 1), x);
	}
	return -1;
}

int FindLast(const vector<int>& arr, int lo, int hi, int x) {
	if (lo <= hi) {
		int n = arr.size();
		int mid = (lo + hi) / 2;
		if (((mid == n - 1) || x < arr[mid + 1]) && arr[mid] == x) return mid;
		else if (x < arr[mid]) return FindLast(arr, lo, (mid - 1), x);
		else return FindLast(arr, (mid + 1), hi, x);
	}
	return -1;
}


int Count3(const vector<int>& arr, int x)
{
	//O(log(n))
	int first = FindFirst(arr, 0, arr.size() - 1, x);
	if (first == -1)
		return 0;
	
	int last = FindLast(arr, first, arr.size() - 1, x);
	
	return last - first + 1;
}

int main()
{
	random_device rd;
	mt19937 gen(rd());

	const int n = 20;
	vector<int> my_vector(n);

	int x = 6; 

	for (int r = 0; r < 100; r++)
	{
		uniform_int_distribution<int> value_distribution(1, 10);
		generate(my_vector.begin(), my_vector.end(), [&]() { return value_distribution(gen); });
		sort(my_vector.begin(), my_vector.end());

		Print(my_vector);

		const int expected_count = std::count(my_vector.begin(), my_vector.end(), x);

		cout << "Expected count = " << expected_count << endl;

		// 1. O(n) brute force
		if (Count1(my_vector, x) != expected_count)
		{
			cout << "Wrong count1: " << Count1(my_vector, x) << endl;
			exit(-1);
		}

		// 2. O(log(n) + count)
		if (Count2(my_vector, x) != expected_count)
		{
			cout << "Wrong count2: " << Count2(my_vector, x) << endl;
			exit(-1);
		}

		// 3. O(log(n))
		if (Count3(my_vector, x) != expected_count)
		{
			cout << "Wrong count3: " << Count3(my_vector, x) << endl;
			exit(-1);
		}
	}

	cout << "Good!" << endl;

	return 0;
}
