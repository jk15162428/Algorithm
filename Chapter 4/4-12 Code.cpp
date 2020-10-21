#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1010;
int father[N], n;
struct EDGE{
    int x, y, w;
    EDGE(int a, int b, int c){x = a, y = b, w = c;}
    EDGE() {}
    bool operator < (const EDGE T) const{
        return w > T.w;
    }
} Edge[N];
// 结构体表示边
priority_queue<EDGE> QUEUE;
vector<EDGE> min_tree;

int fnd(int x){
    return (x == father[x]) ? x : father[x] = fnd(father[x]);
}
void merge(int u, int v){
    father[fnd(u)] = fnd(v);
}
// 使用路径压缩实现并查集

void Kruskal(){
    EDGE temp;
    int cnt = 1;
    while(cnt < n){
        temp = QUEUE.top();
        QUEUE.pop();
        if(fnd(temp.x) != fnd(temp.y)){
            merge(temp.x, temp.y);
            min_tree.emplace_back(temp);
            cnt++;
        }
    }
}

int main(){
    int m, x, y, w;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> w;
        Edge[i] = EDGE(x, y, w);
        QUEUE.push(Edge[i]);
        father[i] = i;
    }
	Kruskal();
    cout << endl << endl;
	for(auto a : min_tree) cout << a.x << " "<< a.y <<" " << a.w << endl;
    return 0;
}
