#include <iostream>
using namespace std;

int main()
{
    int coins[10], n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Enter coin values: ";
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int dp[100];

    // Initialize
    for(int i = 0; i <= amount; i++)
        dp[i] = 999;

    dp[0] = 0;

    // Dynamic Programming
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if(dp[amount] == 999)
        cout << "Change is not possible";
    else
        cout << "Minimum number of coins = " << dp[amount];

    return 0;
}
