#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[20];

    cout << "Enter dimensions: ";
    for(int i = 0; i <= n; i++)
        cin >> p[i];

    int dp[20][20];

    // Cost of multiplying one matrix is 0
    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // Calculate minimum multiplication cost
    for(int length = 2; length <= n; length++)
    {
        for(int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = 999999;

            for(int k = i; k < j; k++)
            {
                int cost = dp[i][k] +
                           dp[k+1][j] +
                           p[i-1] * p[k] * p[j];

                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    cout << "\nMinimum number of multiplications = "
         << dp[1][n];

    return 0;
}
