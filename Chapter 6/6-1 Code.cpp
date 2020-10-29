#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, C;
int bestprofit;
int w[1010], v[1010];
int maxprofit = 0;
struct node{
    int cur;  // 层数，表示选到了第几个物品
    int curprofit;  // 当前收益
    int curC;  // 当前剩余容积
    int maxProfit;  // 剩余物品的价值
    vector<int> choose;  // 记录最后的解向量
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
        STACK.pop();  // 从栈中取出一个结点
        if (temp.cur == n){  // 已经搜索到最后一个元素
            if (temp.curprofit > bestprofit) {
                bestprofit = temp.curprofit;  // 如果是最优解，更新。
                ans = temp.choose;
            }
            continue;
        }
        if (temp.curprofit + temp.maxProfit < bestprofit) continue;  // 上界函数
        temp.cur++;  // 开始检索下一个物品（下一层结点）
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
        // 先遍历一侧子树，更新最优解，之后再遍历不选取的半边子树可以剪枝
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
    cout << "背包的最大价值为：" << bestprofit << endl;
    if(ans.empty()) cout << "背包无法承载任何一件物品。";
    else {
        cout << "选取的物品编号为：";
        for (auto g : ans) cout << g << " ";
    }
    return 0;
}
