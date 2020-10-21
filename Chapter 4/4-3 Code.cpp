#include <iostream>
using namespace std;
int main(){	
	int n, C;
	cin >> n >> C;
	int w[n+5], v[n+5];
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	int maxvalue = 0;
	int cnt;
	for(cnt = 1; cnt <= n; cnt++){
		if(w[cnt] <= C){
			C -= w[cnt];
			maxvalue += v[cnt];
		}
		else break;
	}
	cout << "选取的物品编号为：";
	if(cnt != 1) for(int i = 1; i < cnt; i++) cout << i << " ";
	else cout << "不选取物品。"; 
	cout << endl;
	cout << "背包最大价值为：" << maxvalue; 
	return 0;
}
