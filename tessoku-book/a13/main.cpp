#include <iostream>
using namespace std;

int N, K, A[100009], R[100009];
int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> A[i];

    // R[i]：i番目の数字を基準とし、差がK以下であるような数の最大値のindex
    for(int i = 1; i <= N-1; i++) {
        if(i == 1) R[i] = 1;
        else R[i] = R[i - 1];

        while(R[i] < N && A[R[i] + 1] - A[i] <= K) {
            R[i]++;
        }
    }

    long long Answer = 0;
    for(int i = 1; i <= N-1; i++) Answer += (R[i] - i);

    cout << Answer << endl;
    
    return 0;
}