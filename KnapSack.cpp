#include <iostream>
using namespace std;

int main() {

    int W = 50;   // Knapsack capacity

    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int n = 3;

    int dp[n+1][W+1];

    // Build table in bottom-up manner
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {

            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]],
                               dp[i-1][w]);

            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum profit = " << dp[n][W];

    return 0;
}
