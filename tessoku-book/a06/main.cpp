#include <iostream>
using namespace std;

int main()
{
    // 入力
    int N, Q;
    int A[100009];
    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> A[i];
    
    // 累積和の計算
    int sum[100009];
    for(int i=1; i<=N; i++) sum[i] = sum[i - 1] + A[i];

    // 質問に答える
    for(int i=1; i<=Q; i++) {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << endl;
    }

    return 0;
}