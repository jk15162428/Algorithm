#include <iostream>
#include <vector>
#include <algorithm> // 引入upper_bound 
using namespace std;
int TAIL[100010], pre[100010], L[100010], pos[100010];

int main(){
	int n, cur = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> L[i];
		TAIL[i] = 0;
		// 初始化为几并不影响 
		pre[i] = -1;
		pos[i] = -1;
	}
	TAIL[++cur] = L[0];
	pos[1] = 0;
	for(int i = 1; i < n; i++){
		if(L[i] >= TAIL[cur]) {
			TAIL[++cur] = L[i];
			pos[cur] = i;
			pre[i] = pos[cur - 1];
		}
		else {
			int p = upper_bound(TAIL, TAIL + cur, L[i]) - TAIL;	
		// 使用upper_bound，搜索大于l[i]的第一个元素 
			TAIL[p] = L[i];
			pos[p] = i;
			pre[p] = i;
		}
	} 
	vector<int> TEMP;
	int temp = pre[cur];
	while(temp != -1){
		TEMP.push_back(L[temp]);
		temp = pre[temp];
	}  // 回溯构造最优解 
	cout << "长度为：" << cur << endl; 
	for(int i = TEMP.size() - 1; i >= 0; --i) 
		cout << TEMP[i] << " ";
	return 0;	
}
