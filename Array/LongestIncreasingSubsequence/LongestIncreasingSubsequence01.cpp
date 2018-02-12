#include <bits/stdc++.h>
using namespace std;

// Function to find length of Longest Increasing Subsequence in given array
int findLISLength(int arr[], int n)
{
	// create an empty ordered set S. ith element in S is defined as the 
	// smallest integer that ends an increasing sequence of length i
	set<int> S;

	// process every element one by one
	for (int i = 0; i < n; i++)
	{
		// insert current element into the set
		auto ret = S.insert(arr[i]);

		// get iterator to inserted element's
		set<int>::iterator it;
		if (ret.second)
			it = ret.first;

		// if element is not inserted at the end, then delete next
		// greater element from set
		if (++it != S.end())
			S.erase(it);

		// uncomment below code to print contents of the set after
		// every insertion
		/*
		cout << "\nInserting " << arr[i] << ": ";
		for (auto i: S)
			cout << i << " "; */
	}

	// length of LIS is number of elements in the set	
	return S.size();
}

// main function
int main()
{
	int arr[] = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of LIS is " << findLISLength(arr, n) << endl;

	return 0;
}