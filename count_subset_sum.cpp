#include <iostream>
using namespace std;
#define llint long long int

int t[6 + 1][10 + 1];

int count_subset_sum(int arr[], int n, int sum)
{

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

   
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = ((t[i - 1][j - arr[i - 1]])   +  (t[i - 1][j]));
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
    int t;

    int n = 6;
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10; //{2,3,5} {10} {8,2}  -->3 subset

    cout << count_subset_sum(arr, n, sum);

    return 0;
}