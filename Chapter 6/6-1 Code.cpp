#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, C;
int bestprofit;
int w[1010], v[1010];
int maxprofit = 0;
struct node{
    int cur;  // ��������ʾѡ���˵ڼ�����Ʒ
    int curprofit;  // ��ǰ����
    int curC;  // ��ǰʣ���ݻ�
    int maxProfit;  // ʣ����Ʒ�ļ�ֵ
    vector<int> choose;  // ��¼���Ľ�����
};
stack<node> STACK;
vector<int> ans;

void branchAndBound(){
    int i = 0;
    node temp;
    temp.cur = temp.curprofit = 0;
    temp.curC = C;
    temp.maxProfit = maxprofit;
    STACK.push(temp);
    while(!STACK.empty()){
        temp = STACK.top();
        STACK.pop();  // ��ջ��ȡ��һ�����
        if (temp.cur == n){  // �Ѿ����������һ��Ԫ��
            if (temp.curprofit > bestprofit) {
                bestprofit = temp.curprofit;  // ��������Ž⣬���¡�
                ans = temp.choose;
            }
            continue;
        }
        if (temp.curprofit + temp.maxProfit < bestprofit) continue;  // �Ͻ纯��
        temp.cur++;  // ��ʼ������һ����Ʒ����һ���㣩
        if(temp.curC >= w[temp.cur]) {
            temp.curprofit += v[temp.cur];
            temp.curC -= w[temp.cur];
            temp.maxProfit -= v[temp.cur];
            temp.choose.push_back(temp.cur);
            STACK.push(temp);
            temp.curprofit -= v[temp.cur];
            temp.curC += w[temp.cur];
            temp.maxProfit += v[temp.cur];
            temp.choose.erase(temp.choose.begin()+temp.choose.size()-1);
        }
        // �ȱ���һ���������������Ž⣬֮���ٱ�����ѡȡ�İ���������Լ�֦
        STACK.push(temp);
    }
}

int main(){
    cin >> n >> C;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        maxprofit += v[i];
    }
    branchAndBound();
    cout << "����������ֵΪ��" << bestprofit << endl;
    if(ans.empty()) cout << "�����޷������κ�һ����Ʒ��";
    else {
        cout << "ѡȡ����Ʒ���Ϊ��";
        for (auto g : ans) cout << g << " ";
    }
    return 0;
}
