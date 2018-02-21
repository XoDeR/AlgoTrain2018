#include <bits/stdc++.h>
using namespace std;

// M x M matrix
#define M 5
#define N 5

// Find maximum sum sub-matrix present in a given matrix
int findMaxSumSubmatrix(int matrix[M][N])
{
    // S[i][j] stores sum of sub-matrix formed by row 0 to i-1 
	// and column 0 to j-1
    int S[M+1][N+1];
    
    // pre-process the matrix to fill S[][]
    for (int i = 0; i <= M; i++)
	{
        for (int j = 0; j <= N; j++)
		{
		    if (i == 0 || j == 0)
                S[i][j] = 0;
            else
                S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] +
						matrix[i-1][j-1];
        }
    }

    int maxSum = INT_MIN;
    int rowStart, rowEnd, colStart, colEnd;

	// consider every sub-matrix formed by row i to j 
	// and column m to n
    for (int i = 0; i < M; i++)
    {
        for (int j = i; j < M; j++)
        {
            for (int m = 0; m < N; m++)
			{
                for (int n = m; n < N; n++)
				{
					// calculate submatrix sum using S[][] in constant time
                    int submatrix_sum = S[j+1][n+1] - S[j+1][m] - S[i][n+1] + 
                    				S[i][m];

					// if submatrix sum is more than maximum found so far
                    if (submatrix_sum > maxSum)
					{
                        maxSum = submatrix_sum;
                        rowStart = i;
                        rowEnd = j;
                        colStart = m;
                        colEnd = n;
                    }
                }
            }
        }
    }

	cout << "Sub-matrix is formed by row " << rowStart << " to " << rowEnd << 
			" and column from " << colStart << " to " <<  colEnd << endl;

    return maxSum;
}

int main()
{
	// input matrix
    int matrix[M][N] =
	{
		{ -5, -6,  3,  1,  0 },
		{  9,  7,  8,  3,  7 },
		{ -6, -2, -1,  2, -4 },
		{ -7,  5,  5,  2, -6 },
		{  3,  2,  9, -5,  1 }
	};

	// find maximum sum sub-matrix
	cout << "The maximum sum of sub-matrix is " << findMaxSumSubmatrix(matrix);

    return 0;
}
