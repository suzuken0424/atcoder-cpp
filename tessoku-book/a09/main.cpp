#include <iostream>
using namespace std;

int H, W, N;
int A[100009], B[100009], C[100009], D[100009];
int X[1509][1509], T[1509][1509]; 
int main()
{
    cin >> H >> W >> N;
    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 四隅に+1,-1を付与
    for(int i = 1; i <= N; i++) {
        X[A[i]][B[i]]++;
        X[C[i] + 1][D[i] + 1]++;
        X[A[i]][D[i] + 1]--;
        X[C[i] + 1][B[i]]--;
    }

    // 累積和の計算
    // 横方向の計算
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            T[i][j] = T[i][j - 1] + X[i][j];
        }
    }
    // 横方向の計算
    for(int j = 1; j <= W; j++) {
        for(int i = 1; i <= H; i++) {
            T[i][j] = T[i - 1][j] + T[i][j];
        }
    }

    // 回答
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if(j >= 2) cout << " ";
            cout << T[i][j];
        }
        cout << endl;
    }


    return 0;
}