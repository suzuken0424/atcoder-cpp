#include <iostream>
using namespace std;

int N;
int A[100009], B[100009], C[100009], D[100009];
int X[1509][1509], Z[1509][1509]; 
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 四隅に+1,-1を付与
    // https://atcoder.jp/contests/tessoku-book/submissions/53668223を参考にした
    // 0の部分の計算がしにくいので、x,y両方向に１ずつ移動させる
    for(int i = 1; i <= N; i++) {
        X[A[i]+1][B[i]+1]++;
        X[A[i]+1][D[i]+1]--;
        X[C[i]+1][B[i]+1]--;
        X[C[i]+1][D[i]+1]++;
    }

    // 累積和の計算
    // 横方向の計算
    for(int i = 1; i <= 1500; i++) {
        for(int j = 1; j <= 1500; j++) {
            Z[i][j] = Z[i][j - 1] + X[i][j];
        }
    }
    // 横方向の計算
    for(int i = 1; i <= 1500; i++) {
        for(int j = 1; j <= 1500; j++) {
            Z[i][j] = Z[i - 1][j] + Z[i][j];
        }
    }

    // 回答
    int Answer = 0;
    for(int i = 0; i <= 1500; i++) {
        for(int j = 0; j <= 1500; j++) {
            if(Z[i][j] >= 1) Answer++;
        }
    }
    cout << Answer << endl;

    return 0;
}