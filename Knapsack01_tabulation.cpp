#include <iostream>
using namespace std;
#define llint long long int

int t[5][8];

int Knapsack_tabulation(int val[], int wt[], int W, int n)
{
    //initilzating the value of 0 in column 0
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }

    //initilzating the value of 0 in row 0
    for (int i = 0; i < n + 1; i++)
    {
        t[0][i] = 0;
    }

    //Choice Diagram  
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return (t[n][W]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    int n = 4;
    int W = 7;
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};

    cout << Knapsack_tabulation(val, wt, W, n);

    return 0;
}