#include <iostream>
#include <ctime>
#include <windows.h> // ����Sleep
using namespace std;

int n;  // ͼG�Ľ����
int x[100];  // ��ǰ�Ľ�ռ�
int bestx[100];  // ��ǰ�����Ž�
float bestcost;  // ��ǰ����ֵ
float ccost;  // ��ǰ����
float a[100][100];  // ͼG���ڽӾ���
float maxcost[100];  // ����ÿһ�����i���������ߵ�costΪmaxcost[i]
float MAXCOST;  // ���ڼ�¼ʣ����� maxcost֮�ͣ�һ��ʼ��ʼ��Ϊmaxcost[i]֮��
const float MAX = 2000000.0;  // ����󣬱�ʾû��·������
// �������岿��

void backtrace(int i);
void init();

int main(){
    init();
    clock_t t_begin = clock();
    backtrace(2);
    clock_t t_end = clock();
    cout << "���·����Ϊ��" << bestcost << endl;
    cout << "���·��Ϊ��";
    for(int i = 1; i <= n; i++){
        cout << bestx[i] << " ";
    }
    cout << endl << "���ݺ�ʱΪ��" << (t_end - t_begin) << "ms";
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
            // ����ʡ���� bestcost == MAX����Ϊbestcost��ʼ�����޸�
            for (int j = 1; j <= n; j++) bestx[j] = x[j];
            bestcost = ccost + a[x[n - 1]][x[n]] + a[x[n]][1];
        }
    } // ����i==n�Ĳ��ֿ��Խ����Ż�
    else {
        for(int j = i; j <= n; j++) {
            if (a[x[i - 1]][x[j]] < MAX && ccost + a[x[i - 1]][x[j]] < bestcost) {
                // �˴��������ж�Ҳ���Խ����Ż�
                swap(x[i], x[j]);
                ccost += a[x[i - 1]][x[i]];
                backtrace(i + 1);
                Sleep(2);  // ÿ�λ���һ�ξ�Ҫ����2ms��Ϊ�˶ԱȲ�ͬ�㷨֮���Ч��
                ccost -= a[x[i - 1]][x[i]];
                swap(x[i], x[j]);
            }
        }
    }
}

