#include <iostream>
using namespace std;

int main()
{
    int T, N;
    cin >> T >> N;
    int L[500009], R[500009];
    // L,Rはi番目の従業員の出勤と退勤時間
    for(int i = 1; i <= N; i++) cin >> L[i] >> R[i];

    // 累積和を計算（1時間前との差を計算）
    // diffは時刻i時点での増減
    // diff[1]は時刻1時点での増減
    int diff[500009];

    for(int i = 1; i <= N; i++) {
        // Lは出勤時間なので、時刻L[i]時点で従業員が増加
        diff[L[i]] += 1;
        // Rは退勤時間なので、時刻L[i]時点で従業員が減少
        diff[R[i]] -= 1;
    }

    // 時刻i時点で増減が終わったあとの従業員数
    int employees[500009];
    // 時刻0.5時点の従業員数（時刻0時点の従業員数<増減が終わったあと>） = 時刻0時点の従業員数の増減
    // 時刻1.5時点の従業員数（時刻1時点の従業員数<増減が終わったあと>） = 時刻0時点の従業員数 + 時刻1時点の従業員数の増減
    // 時刻2.5時点の従業員数（時刻2時点の従業員数<増減が終わったあと>） = 時刻1時点の従業員数 + 時刻2時点の従業員数の増減
    employees[0] = diff[0];
    for(int t = 1; t < T; t++) employees[t] = employees[t-1] + diff[t];

    // 回答
    for (int d = 0; d < T; d++) cout << employees[d] << endl;
    return 0;
}