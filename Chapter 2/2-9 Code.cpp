#include <iostream>
using namespace std;

int a[100010];

void mySort(int m, int n);
int partition(int l, int r, int midnum);
int select(int left, int right, int k);

int main(){
    cout << "请输入n的大小：";
    int n;
    cin >> n;
    cout << "请输入n个合法数字，用空格或换行分割。" << endl;
    for(int i = 0; i < n; i++) cin >> a[i];
    int middle = select(0, n-1, n/2);
    int cnt = 0;
	for(int i = 0; i < n; i++){
    	if(a[i] == middle) cnt++;
    }
    if(cnt > n/2) cout << "存在";
	else cout << "不存在"; 
    return 0;
}

void mySort(int m, int n){
	for (int i = m; i <= n; i++) {
		int x = i;
		for (int j = i + 1; j <= n; j++)
			if (a[x] > a[j])
				x = j;
		if (x != i) {
			int num = a[x];
			a[x] = a[i];
			a[i] = num;
		}
	}
}

int partition(int l, int r, int midnum){
	int point = 0;
	for(int q = l; q <= r; q++)
		if (a[q] == midnum) {
			point = q;
			break;
		}
	int df = a[l];
	a[l] = a[point];
	a[point] = df;
	int i = l, j = r + 1;
	int x = a[l];
	while (1) {
		while (a[++i] < x && i <= r);        
		while (a[--j] > x);
		if (i >= j)	break;
		int m = a[i];
		a[i] = a[j];
		a[j] = m;
	}
	a[l] = a[j];
	a[j] = x;
	return j;
}
 
int select(int left, int right, int k){
	if(right - left < 5){
		mySort(left, right);
		return a[left + k - 1];
	}
	for (int i = 0; i <= (right - left - 4) / 5; i++){
		mySort(left + 5 * i, left + 5 * i + 4);
		int jk = a[left + 5 * i + 2];
		a[left + 5 * i + 2] = a[left + i];
		a[left + i] = jk;
	}
	int x = select(left, left + (right - left - 4) / 5, (right - left - 4) / 10);
	int local = partition(left, right, x), j = local - left + 1;
	if (k <= j) return select(left, local, k);
	else return select(local + 1, right, k - j);
}
