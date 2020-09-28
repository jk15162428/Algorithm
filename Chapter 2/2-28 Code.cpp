#include <iostream>
using namespace std;

int X[100010];
int Y[100010];
const int INF = 0x3f3f3f3f;
int a = INF, b = -INF;
double midNumber(int Xleft, int Yleft, int Xnum, int Ynum);
double midNumber2(int S[], int Sleft, int Snum);

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> X[i];
    }
    for(int j = 1; j <= n; j++){
        cin >> Y[j];
    }
    double ans = midNumber(1, 1, n, n);
    cout << ans;
    return 0;
}

double midNumber(int Xleft, int Yleft, int Xnum, int Ynum){  // num表示X和Y中有几个元素	 
	if(Xnum == Ynum && Xnum == 1){
		if(X[Xleft] >= Y[Yleft]){
			a = min(a, X[Xleft]);
			b = max(b, Y[Yleft]);
		}
		else{
			a = min(a, Y[Yleft]);
			b = max(b, X[Xleft]);	
		}
		return (a + b) / 2.0;
	}
	if(Xnum == 0) return midNumber2(Y, Yleft, Ynum);
	if(Ynum == 0) return midNumber2(X, Xleft, Xnum);
	if(Xnum % 2 == 0){
		if(X[Xleft + Xnum/2 - 1] > Y[Yleft + Ynum/2 - 1] && X[Xleft + Xnum/2] < Y[Yleft + Ynum/2]){
			a = min(a, Y[Yleft + Ynum/2]);
			b = max(b, Y[Yleft + Ynum/2 - 1]);
			Ynum = 0;	
		}
		else if(Y[Yleft + Ynum/2 - 1] > X[Xleft + Xnum/2 - 1] && Y[Yleft + Ynum/2] < X[Xleft + Xnum/2]){
			a = min(a, X[Xleft + Xnum/2]);
			b = max(b, X[Xleft + Xnum/2 - 1]);
			Xnum = 0;	
		}
		else if(X[Xleft + Xnum/2 - 1] > Y[Yleft + Ynum/2 - 1] && X[Xleft + Xnum/2] > Y[Yleft + Ynum/2]){
			Xnum /= 2;
			a = min(a, X[Xleft+Xnum]);
			Yleft = Yleft + Ynum/2;
			Ynum /= 2;
			b = max(b, Y[Yleft-1]);
		}
		else {
			Ynum /= 2;
			a = min(a, Y[Yleft + Ynum]);
			Xleft = Xleft + Xnum/2;
			Xnum /= 2;	
			b = max(b, X[Xleft-1]);
		}
	}
	else {
		if(X[Xleft + Xnum/2] < Y[Yleft + Ynum/2]){
			Xleft = Xleft + Xnum/2 + 1;
			Xnum = Xnum - Xnum/2 - 1;
			Ynum = Ynum - (Ynum - Ynum/2);
			a = min(a, Y[Yleft+Ynum]);
			b = max(b, X[Xleft-1]);
		}
		else {
			Yleft = Yleft + Ynum/2 + 1;	
			Ynum = Ynum - Ynum/2 - 1;
			Xnum = Xnum - (Xnum - Xnum/2);
			a = min(a, X[Xleft+Xnum]);
			b = max(b, Y[Yleft-1]);
		}
	}
	return midNumber(Xleft, Yleft, Xnum, Ynum);
}

double midNumber2(int S[], int Sleft, int Snum){  // 只可能是num为偶数时进入这个函数 
	int mid = Sleft + Snum / 2 - 1;
	a = min(a, S[mid + 1]);
	b = max(b, S[mid]);
	return (a + b) / 2.0;
}
