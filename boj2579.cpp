#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    int stair[300];
    int dp[300];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stair[i];
    }//계단에 할당된 수 초기화

    dp[0] = stair[0];//한칸을 올라간 경우 초기값
    dp[1] = max(stair[0] + stair[1], stair[1]);//2칸을 올라간 경우의 초기값
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);//3칸을 올라간 경우의 초기값

    for (int i = 3; i < n; i++) {
    
        dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
    }

    cout << dp[n - 1] << '\n';

    return 0;
}