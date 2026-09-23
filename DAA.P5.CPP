#include <iostream>
using namespace std;

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[20], value[20];

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[20][100];

    // Initialize
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i-1] <= w)
            {
                dp[i][w] = max(
                    value[i-1] + dp[i-1][w-weight[i-1]],
                    dp[i-1][w]
                );
            }

            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << "\nMaximum value = " << dp[n][capacity];

    return 0;
}
