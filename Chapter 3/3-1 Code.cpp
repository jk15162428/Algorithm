#include <iostream>
#include <vector>
using namespace std;
int DP[100010];
int pre[100010];
int L[100010];

int main(){
	int n, cur = 1, pos = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> L[i];
		DP[i] = 1; 
		// 每一个数本身都是一个上升子序列 
		pre[i] = -1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){	
			if(j <= i && L[j] <= L[i]){
				if(DP[j]+1 >= DP[i]) pre[i] = j;
		// 这里取等于的原因是为了保证子序列的子序列最优 
				DP[i] = max(DP[j]+1, DP[i]);
				cur = max(cur, DP[i]);  
		// cur的作用是记录最长子序列长度 
				if(cur == DP[i]) pos = i;  
		// pos的作用是记录一个最长子序列的下标，之后选择最优 
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(DP[i] == cur && L[i] < L[pos]){
			pos = i;  
		// 遍历一遍，找到最优的子序列（末尾最小） 
		}
	}
	vector<int> TEMP;
	while(pos != -1){
		TEMP.push_back(L[pos]);
		pos = pre[pos];	
	}  // 回溯构造最优解 
	cout << "长度为：" << cur << endl; 
	for(int i = TEMP.size() - 1; i >= 0; --i) 
		cout << TEMP[i] << " ";
	return 0;	
}
