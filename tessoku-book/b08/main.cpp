#include <iostream>
using namespace std;

int N, Q;
int X[100009], Y[100009];
int a[100009], b[100009], c[100009], d[100009];
int S[1509][1509];
int T[1509][1509];
int main()
{
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
    cin >> Q;
    for(int i = 1; i <= Q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    // 各座標にある点の数を数える
    for(int i = 1; i <= N; i++) S[X[i]][Y[i]]++;

    // 累積和の計算
    // 横方向を計算
    for(int i = 1; i <= 1500; i++) {
        for(int j = 1; j <= 1500; j++) {
            T[i][j] = T[i][j - 1] + S[i][j];
        }
    }
    // 縦方向を計算
    for(int j = 1; j <= 1500; j++) {
        for(int i = 1; i <= 1500; i++) {
            T[i][j] = T[i - 1][j] + T[i][j];
        }
    }

    // 答えを求める
    for(int i = 1; i <= Q; i++) {
        cout << T[c[i]][d[i]] - T[c[i]][b[i] - 1] - T[a[i] - 1][d[i]] + T[a[i] - 1][b[i] - 1] << endl;
    }
    
    return 0;
}