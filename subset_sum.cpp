#include <iostream>
using namespace std;
#define llint long long int


/*
 if the output is 0---> then subset_sum is not possible..
 if the output is 1---> then subset_sum is possible..
*/
int t[5 + 1][11 + 1];

int subset_sum(int arr[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {

            if (i == 0)
                t[i][j] = 0; //filling Oth row with zero (false)
            if (j == 0)
                t[i][j] = 1; //filling 0th column with one(true)
        }
    }


    //Choice Diagram
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return (t[n][sum]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5;
    int arr[n] = {2, 3, 7, 8, 10};
    int sum = 20;

    cout << subset_sum(arr, n, sum);

    return 0;
}
