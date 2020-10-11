#include <iostream>
using namespace std;
int DP[110][110][110]; // i, W, B
int W[110], B[110], V[110], BUYED[110];

int main(){
    int C, D;
    cout << "请输入背包的容积和体积（容积和体积需小于110），中间用空格隔开：";
    cin >> C >> D;
    int n;
    cout << "请输入物品的个数：";
    cin >> n;
    cout << "接下来请输入三行，第一行为每个物品的重量，第二行为每个物品的体积，\n第三行为每个物品的价值，数字之间用空格隔开。" <<endl;
    for(int i = 0; i < n; i++) cin >> W[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++) cin >> V[i];
    if(D >= B[0] && C >= W[0]) DP[0][W[0]][B[0]] = V[0];
    // 由于DP[0][C][D]默认为0（全局变量），只需要初始化第一个物品取了后的状态即可
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= C; j++){
            for(int k = 1; k <= D; k++){
                if(k >= B[i] && j >= W[i]){
                    DP[i][j][k] = max(DP[i-1][j][k], DP[i-1][j-W[i]][k-B[i]]+V[i]);
                }
                else DP[i][j][k] = DP[i-1][j][k];
            }
        }
    }
    // 动态规划解01背包问题
    int i = n-1, j = C, k = D;
    while(i){
        if(DP[i][j][k] == DP[i-1][j][k]) {BUYED[i] = 0; i--;}
            // 如果相等，说明当前物品没有购买
        else if(j - W[i] >= 0 && k - B[i] >= 0){
            BUYED[i] = 1;
            j -= W[i], k -= B[i];
            i--;
        }
    }
    if(i == 0 && j - W[i] >= 0 && k - B[i] >= 0) BUYED[0] = 1;
    // 回溯找最优解
    cout << "背包的最大价值为：" << DP[n-1][C][D] << endl;
    if(DP[n-1][C][D]){	
        cout << "装入的物品编号为：";
        for(int i = 0; i < n; i++){
            if(BUYED[i]) cout << i+1 << " ";
        }
    }
    else cout << "没有办法装入物品。";
    return 0;
}

