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
	cout << "ѡȡ����Ʒ���Ϊ��";
	if(cnt != 1) for(int i = 1; i < cnt; i++) cout << i << " ";
	else cout << "��ѡȡ��Ʒ��"; 
	cout << endl;
	cout << "��������ֵΪ��" << maxvalue; 
	return 0;
}
