#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> dp(num + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= num; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            int digit = temp % 10;
            if (digit != 0)
                dp[i] = min(dp[i], 1 + dp[i - digit]);
            temp /= 10;
        }
    }

    cout << dp[num] << endl;
}
