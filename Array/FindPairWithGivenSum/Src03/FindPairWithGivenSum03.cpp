#include <iostream>
#include <vector>
#include <unordered_map>

// Hashing
// Function to find a pair in an array with given sum using hashing
void findPair(const std::vector<int>& arr, int sum)
{
	int n = arr.size();
    // create an empty map
    std::unordered_map<int, int> hashMap; // [value : index]

    // do for each element
    for (int i = 0; i < n; ++i)
    {
        // check if pair (arr[i], sum-arr[i]) exists

        // if difference is seen before, print the pair
        if (hashMap.find(sum - arr[i]) != hashMap.end())
        {
            std::cout << "Pair found at index " << hashMap[sum - arr[i]] << " and " << i;
            return;
        }

        // store index of current element in the map
		hashMap[arr[i]] = i;
    }

    // we reach here if pair is not found
    std::cout << "Pair not found";
}

int main()
{
	std::vector<int> arr = { 8, 7, 2, 5, 3, 1};
    int sum = 10;
    findPair(arr, sum);

    return 0;
}