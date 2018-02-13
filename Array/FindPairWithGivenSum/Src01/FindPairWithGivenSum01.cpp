#include <iostream>
#include <vector>

// Naive n**2
// Naive method to find a pair in an array with given sum
void findPair(const std::vector<int>& arr, int sum)
{
	int n = arr.size();
    // consider each element except last element
    for (int i = 0; i < n - 1; ++i)
    {
        // start from i'th element till last element
        for (int j = i + 1; j < n; ++j)
        {
            // if desired sum is found, print it and return
            if (arr[i] + arr[j] == sum)
            {
                std::cout << "Pair found at index " << i << " and " << j;
                return;
            }
        }
    }
 
    // No pair with the given sum exists in the array
    std::cout << "Pair not found";
}
 
int main()
{
    std::vector<int> arr = { 8, 7, 2, 5, 3, 1 };
    int sum = 10;
 
    findPair(arr, sum);
 
    return 0;
}