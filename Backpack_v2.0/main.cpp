//
//  main.cpp
//  Backpack_v2.0
//
//  Created by Егор Броницкий on 20.04.2022.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

using namespace std;
namespace fs = filesystem;
  
int knapSackRec(int W, vector<int> wt, vector<int> val, int i, int** dp) {
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];
    if (wt[i] > W) {
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    } else {
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp),knapSackRec(W, wt, val, i - 1, dp));
        return dp[i][W];
    }
}

int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    int** dp;
    dp = new int*[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main() {
    string path = "/Users/egorbronickij/Desktop/data 2";
          auto it = fs::directory_iterator(path);
          vector<fs::path> array_path;
          copy_if(fs::begin(it), fs::end(it), std::back_inserter(array_path),
              [](const auto& entry) {
                  return fs::is_regular_file(entry);
          });
    for (auto& p : array_path) {
        ifstream fin;
        fin.open(p.string());
        cout << p.string() << endl;
        int n, W;
        fin >> n >> W;
        vector<int> values;
        vector<int> weights;
        for (int i = 0; i < n; i++) {
            int value, weight;
            fin >> value >> weight;
            values.push_back(value);
            weights.push_back(weight);
        }
        int max_value = knapSack(W, weights, values, n);
        cout << max_value << endl;
    }
    return 0;
}
