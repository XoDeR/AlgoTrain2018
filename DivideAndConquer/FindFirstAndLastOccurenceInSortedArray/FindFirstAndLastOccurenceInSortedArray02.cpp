#include <stdio.h>

// Function to find last occurrence of a given number
// in sorted array of integers
int findLastOccurrence(int A[], int N, int x)
{
    // search space is A[low..high]
    int low = 0, high = N - 1;

    // initialize the result by -1
    int result = -1;

    // iterate till search space contains at-least one element
    while (low <= high)
    {
        // find the mid value in the search space and
        // compares it with target value
        int mid = (low + high)/2;

        // if target is found, update the result and
        // go on searching towards right (higher indices)
        if (x == A[mid])
        {
            result = mid;
            low = mid + 1;
        }

        // if target is less than the mid element, discard right half
        else if (x < A[mid])
            high = mid - 1;

        // if target is more than the mid element, discard left half
        else
            low = mid + 1;
    }

    // return the leftmost index or -1 if the element is not found
    return result;
}

// main function
int main(void)
{
    int A[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int n = sizeof(A)/sizeof(A[0]);

    int target = 5;

    int index = findLastOccurrence(A, n, target);

    if (index != -1)
        printf("First occurrence of element %d is found at index %d", target, index);
    else
        printf("Element not found in the array");

    return 0;
}