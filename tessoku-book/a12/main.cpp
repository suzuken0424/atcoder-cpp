#include <iostream>
using namespace std;

long long N, K, A[100009];

// x秒時点でチラシの数が十分印刷されているか
bool check(long long x) {
    long long sum = 0;
    for(int i = 1; i <= N; i++) sum += x / A[i];
    if(sum >= K) return true;
    return false;
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> A[i];

    long long Left = 1, Right = 1'000'000'000;
    while(Left < Right) {
        long long Middle = (Left + Right) / 2;
        bool Answer = check(Middle);
        // checkがtrue=>十分に印刷される=>ただ多すぎる可能性はある=>Middleが正解の可能性はあるのでRight=Middle
        // checkがfalsez=>十分に印刷されない=>Middleが正解の可能性がないのでLeft=Middle
        if(Answer) Right = Middle;
        else Left = Middle + 1;
    }

    cout << Left << endl;

    return 0;
}