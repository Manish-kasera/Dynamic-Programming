#include <iostream>
#include <vector>
using namespace std;
#define llint long long int

vector<int> subset_sum(int arr[], int n, int range)
{
    int t[n + 1][range + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {

            if (i == 0)
                t[i][j] = 0; //filling Oth row with 0 (false)
            if (j == 0)
                t[i][j] = 1; //filling 0th column with 1(true)
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]));
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    vector<int> v;

    for (int j = 0; j <= range / 2; j++)
    {
        if (t[n][j] == 1)
        {
            v.push_back(j);
        }
    }
    return v;
}

int min_subset_sum_diff(int arr[], int n)
{
    int range = 0; 
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }

    vector<int> v;

    int mini=INT16_MAX;
    v = subset_sum(arr, n, range);
    for (int i = 0; i < v.size(); i++)
    {
        mini = min(mini,range-2*v[i]);
    }
    return mini;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {1,6,5,11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<min_subset_sum_diff(arr, n);

    return 0;
}