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
		// ÿһ����������һ������������ 
		pre[i] = -1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){	
			if(j <= i && L[j] <= L[i]){
				if(DP[j]+1 >= DP[i]) pre[i] = j;
		// ����ȡ���ڵ�ԭ����Ϊ�˱�֤�����е����������� 
				DP[i] = max(DP[j]+1, DP[i]);
				cur = max(cur, DP[i]);  
		// cur�������Ǽ�¼������г��� 
				if(cur == DP[i]) pos = i;  
		// pos�������Ǽ�¼һ��������е��±֮꣬��ѡ������ 
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(DP[i] == cur && L[i] < L[pos]){
			pos = i;  
		// ����һ�飬�ҵ����ŵ������У�ĩβ��С�� 
		}
	}
	vector<int> TEMP;
	while(pos != -1){
		TEMP.push_back(L[pos]);
		pos = pre[pos];	
	}  // ���ݹ������Ž� 
	cout << "����Ϊ��" << cur << endl; 
	for(int i = TEMP.size() - 1; i >= 0; --i) 
		cout << TEMP[i] << " ";
	return 0;	
}
