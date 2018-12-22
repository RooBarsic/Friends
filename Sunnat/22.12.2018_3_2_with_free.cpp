/*
Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков
пирамиду.
Формат входных данных:
На вход подается количество кубиков N.
Формат выходных данных:
Вывести число различных пирамид из N кубиков.
Широкая пирамида. Каждый вышележащий слой пирамиды должен быть строго меньше
нижележащего.
*/

#include <bits/stdc++.h>
using std::vector;
long long calc(int n, int k, vector< vector< long long > >& dp) {
    if ((n < 0)||(k < 0)) return 0;
    if(k == 1) {
        if(n == 1) return 1;
        return 0;
    }
    if(n <= 2) return 1;

    if(dp[n][k] >= 0) return dp[n][k];

    dp[n][k] =  calc(n, k - 1, dp) + calc(n - k, k - 1, dp);

    return dp[n][k];
}

void solve(){
    int m, i, j;
    std::cin >> m;

    vector< vector< long long > > dp (m + 1);

    for (i = 0; i < m + 1; i++) {
        dp[i] = vector<long long>(m + 1, 0);

        for (j = 0; j < m + 1; j++) {
            dp[i][j] = -1;
        }
    }
    std::cout << calc(m, m, dp) << std::endl;
    std::vector<vector< long long > >().swap(dp);
}

int main() {
    int t = 1;
    while(t > 0){
        solve();
        t--;
    }
    return 0;
}
