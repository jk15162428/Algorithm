#include <iostream>
#include <ctime>
#include <windows.h> // 引入Sleep
using namespace std;

int n;  // 图G的结点数
int x[100];  // 当前的解空间
int bestx[100];  // 当前的最优解
float bestcost;  // 当前最优值
float ccost;  // 当前费用
float a[100][100];  // 图G的邻接矩阵
float maxcost[100];  // 对于每一个结点i，其最大出边的cost为maxcost[i]
float MAXCOST;  // 用于记录剩余结点的 maxcost之和，一开始初始化为maxcost[i]之和
const float MAX = 2000000.0;  // 无穷大，表示没有路径相连
// 变量定义部分

void backtrace(int i);
void init();

int main(){
    init();
    clock_t t_begin = clock();
    backtrace(2);
    clock_t t_end = clock();
    cout << "最短路径长为：" << bestcost << endl;
    cout << "最短路径为：";
    for(int i = 1; i <= n; i++){
        cout << bestx[i] << " ";
    }
    cout << endl << "回溯耗时为：" << (t_end - t_begin) << "ms";
}

void init(){
    n = 10;
    for(int i = 1; i <= n; i++) x[i] = i, bestx[i] = i, maxcost[i] = 0;
    ccost = MAXCOST = 0;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n; j++)
            a[i][j] = MAX;
    }
    a[1][9] = a[9][1] = a[8][7] = a[7][8] = a[2][4] = a[4][2] = 5;
    a[4][10] = a[10][4] = a[3][6] = a[6][3] = a[1][8] = a[8][1] = 4;
    a[2][7] = a[7][2] = a[1][3] = a[3][1] = a[5][8] = a[8][5] = a[9][10] = a[10][9] = 6;
    a[4][5] = a[5][4] = a[8][9] = a[9][8] = 2;
    a[1][7] = a[7][1] = a[3][10] = a[10][3] = a[7][10] = a[10][7] = 3;
    a[3][8] = a[8][3] = a[5][6] = a[6][5] = 9;
    a[1][4] = a[4][1] = a[2][10] = a[10][2] = a[6][9] = a[9][6] = 8;
    a[6][7] = a[7][6] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] != MAX) maxcost[i] = max(maxcost[i], a[i][j]);
        }
        MAXCOST += maxcost[i];
    }
    bestcost = MAXCOST;
}

void backtrace(int i) {
    if (i == n) {
        if (a[x[n-1]][x[n]] < MAX && a[x[n]][1] < MAX &&
            ccost + a[x[n-1]][x[n]] + a[x[n]][1] < bestcost) {
            // 这里省略了 bestcost == MAX，因为bestcost初始化已修改
            for (int j = 1; j <= n; j++) bestx[j] = x[j];
            bestcost = ccost + a[x[n - 1]][x[n]] + a[x[n]][1];
        }
    } // 对于i==n的部分可以进行优化
    else {
        for(int j = i; j <= n; j++) {
            if (a[x[i - 1]][x[j]] < MAX && ccost + a[x[i - 1]][x[j]] < bestcost) {
                // 此处的条件判断也可以进行优化
                swap(x[i], x[j]);
                ccost += a[x[i - 1]][x[i]];
                backtrace(i + 1);
                Sleep(2);  // 每次回溯一次就要休眠2ms，为了对比不同算法之间的效率
                ccost -= a[x[i - 1]][x[i]];
                swap(x[i], x[j]);
            }
        }
    }
}

