#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define llint long long int

int t[10][10]; //Creating matrix i.e t[n][W] as n and W are changing

int Knapsack(int wt[], int val[], int W, int n)
{
    //Base Case
    if (W == 0 || n == 0)
    {
        return 0;
    }

    // If the value is already store( other than -1 )in t[n][W]
    // then we directly return t[n][W]
    if (t[n][W] != -1)
    {
        return t[n][W];
    }

    //Choice Diagram
    if (wt[n - 1] <= W)
    {
        return t[n][W] = max((val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1)), //if (n-1)element is pick up
                             Knapsack(wt, val, W, n - 1));                           //if (n-1)element is not pick up
    }
    else if (wt[n - 1] > W)
    {
        return t[n][W] = (Knapsack(wt, val, W, n - 1)); // if (n-1)element is not pick up
    }
}

int main()
{
    //for faster Inpput Output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(t, -1, sizeof(t)); // initilise all value in t[n][W] matrix to -1

    int t; //number of test Case
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
        cout << ans << endl;
    }

    return 0;
}