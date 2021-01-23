#include <iostream>
using namespace std;
#define llint long long int

/*
 
 if the output is -1 --> it simply means equal partation is not possible
 if the output is 1 --> it simply means equal partation is  possible



*/

int subset_sum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1]; //making a matrix of (n+1) cross (sum+1)

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {

            if (i == 0)
                t[i][j] = -1; //filling Oth row with -1 (false)
            if (j == 0)
                t[i][j] = 1; //filling 0th column with 1(true)
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

int equal_sum_partition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return -1;
    }
    else
    {
        return subset_sum(arr, sum / 2, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 4;
    int arr[n] = {1, 5, 11, 6};

    cout << equal_sum_partition(arr, n);

    return 0;
}