#include <iostream>
using namespace std;

int main()
{
    int D, N, L[100009], R[100009];
    cin >> D >> N;
    for(int i=1; i<=N; i++) cin >> L[i] >> R[i];

    // 累積和の計算（前日比の計算）
    int diff[100009];
    for(int i=1; i<=N; i++) {
        diff[L[i]]++;
        diff[R[i] + 1]--;
    }

    // 回答
    int visiter[100009];
    for(int i=1; i<=D; i++) {
        visiter[i] = visiter[i - 1] + diff[i];
        cout << visiter[i] << endl;
    }
    
    return 0;
}