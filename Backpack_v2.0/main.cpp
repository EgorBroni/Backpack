//
//  main.cpp
//  Backpack_v2.0
//
//  Created by Егор Броницкий on 20.04.2022.
//

#include <iostream>
#include <vector>


using namespace std;


int main() {
    int W, n;
    cin >> n >> W;
    
    int inf = 100000000;
    
    vector <int> w(n + 1);
    
    for (int i = 1; i <= n; i++){
        cin >> w[i];
}
    
    vector < vector <int> > dp(n + 1, vector <int>(W + 1, -inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= W; j++){
            if (w[i] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + w[i]); //+ c[i]
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 0;
    for (int w = 0; w <= W; w++){
        ans = max(ans,dp[n][w]);
    }
    cout << ans << endl;
    return 0;
}
