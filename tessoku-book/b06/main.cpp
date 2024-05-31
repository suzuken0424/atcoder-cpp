#include <iostream>
using namespace std;

int main()
{
    int N, Q, A[100009];
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    
    // 累積和の計算
    int win[100009];
    int lose[100009];
    for(int i=1; i<=N; i++) {
        if(A[i] == 1) {
            win[i] = win[i - 1] + 1;
            lose[i] = lose[i - 1];
        }else{
            win[i] = win[i - 1];
            lose[i] = lose[i - 1] + 1;
        }
    }

    // 質問に答える
    cin >> Q;
    for(int i=1; i<=Q; i++) {
        int L, R, winNum, loseNum;
        cin >> L >> R;
        winNum = win[R] - win[L - 1];
        loseNum = lose[R] - lose[L - 1];
        if(winNum < loseNum) {
            cout << "lose" << endl;
        }else if(winNum > loseNum) {
            cout << "win" << endl;
        }else{
            cout << "draw" << endl;
        }
    }
    return 0;
}