#include <iostream>
using namespace std;
int DP[110][110][110]; // i, W, B
int W[110], B[110], V[110], BUYED[110];

int main(){
    int C, D;
    cout << "�����뱳�����ݻ���������ݻ��������С��110�����м��ÿո������";
    cin >> C >> D;
    int n;
    cout << "��������Ʒ�ĸ�����";
    cin >> n;
    cout << "���������������У���һ��Ϊÿ����Ʒ���������ڶ���Ϊÿ����Ʒ�������\n������Ϊÿ����Ʒ�ļ�ֵ������֮���ÿո������" <<endl;
    for(int i = 0; i < n; i++) cin >> W[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++) cin >> V[i];
    if(D >= B[0] && C >= W[0]) DP[0][W[0]][B[0]] = V[0];
    // ����DP[0][C][D]Ĭ��Ϊ0��ȫ�ֱ�������ֻ��Ҫ��ʼ����һ����Ʒȡ�˺��״̬����
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
    // ��̬�滮��01��������
    int i = n-1, j = C, k = D;
    while(i){
        if(DP[i][j][k] == DP[i-1][j][k]) {BUYED[i] = 0; i--;}
            // �����ȣ�˵����ǰ��Ʒû�й���
        else if(j - W[i] >= 0 && k - B[i] >= 0){
            BUYED[i] = 1;
            j -= W[i], k -= B[i];
            i--;
        }
    }
    if(i == 0 && j - W[i] >= 0 && k - B[i] >= 0) BUYED[0] = 1;
    // ���������Ž�
    cout << "����������ֵΪ��" << DP[n-1][C][D] << endl;
    if(DP[n-1][C][D]){	
        cout << "װ�����Ʒ���Ϊ��";
        for(int i = 0; i < n; i++){
            if(BUYED[i]) cout << i+1 << " ";
        }
    }
    else cout << "û�а취װ����Ʒ��";
    return 0;
}

