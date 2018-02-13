#include <iostream>
#include <algorithm> // std::sort
#include <vector>

// Sorting
// Function to find a pair in an array with given sum using sorting
void findPair(std::vector<int>& arr, int sum)
{
	int n = arr.size();
    // sort the array in ascending order
    std::sort(arr.begin(), arr.end());

    // maintain two indices pointing to end-points of the array
    int low = 0;
    int high = n - 1;

    // reduce search space arr[low..high] at each iteration of the loop

    // loop till low is less than high
    while (low < high)
    {
        // sum found
        if (arr[low] + arr[high] == sum)
        {
            std::cout << "Pair found";
            return;
        }
		else if (arr[low] + arr[high] < sum)
		{
			// increment low index if total is less than the desired sum
			++low;
		}
		else // arr[low] + arr[high] > sum
		{
			// decrement high index is total is more than the sum
			--high;
		}
    }

    // No pair with given sum exists in the array
    std::cout << "Pair not found";
}

int main()
{
	std::vector<int> arr = { 8, 7, 2, 5, 3, 1};
    int sum = 10;
    findPair(arr, sum);

    return 0;
}