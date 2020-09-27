#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[100010]; 

int mainElement(int left, int right);

int main(){
    cout << "请输入n的大小：";
    int n;
    cin >> n;
    cout << "请输入n个合法数字，用空格或换行分割。" << endl;
    for(int i = 0; i < n; i++) cin >> a[i];
	int main = mainElement(0, n - 1);
	if(main == INF) cout << "不存在";
	else cout << "存在，且主元素为" << main; 
	return 0;	
}

int mainElement(int left, int right){
	if(left == right) return a[left];
	int mid = (left + right) / 2;
	int main1 = mainElement(left, mid);
	int main2 = mainElement(mid + 1, right);
	int cnt1 = 0, cnt2 = 0;
	for(int i = left; i <= right; i++){
		if(a[i] == main1) cnt1++;	
		if(a[i] == main2) cnt2++;
	}
	if(cnt1 > (right - left) / 2) return main1;
	if(cnt2 > (right - left) / 2) return main2;
	return INF;
}
