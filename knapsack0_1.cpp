#include <iostream>
using namespace std;
#define llint long long int

int Knapsack(int wt[], int val[], int W, int n)
{
    //Base Case
    if (W == 0 || n == 0)
    {
        return 0;
    }

    //Choice Diagram
    if (wt[n - 1] <= W)
    {
        return max((val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1)),   //if (n-1)element is pick up
                   Knapsack(wt, val, W, n - 1)); //if (n-1)element is not pick up
    }
    else if (wt[n - 1] > W)
    {
        return (Knapsack(wt, val, W, n - 1)); // if (n-1)element is not pick up
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        int n, W;
        cin >> n >> W;

        int val[n];
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }

        int wt[n];
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }

        int ans = Knapsack(wt, val, W, n);
        cout << ans<<endl;

        return 0;
    }

}