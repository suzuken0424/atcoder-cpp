#include <iostream>
using namespace std;

int N, D;
int A[100009], L[100009], R[100009], LT[100009], RT[100009];
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    cin >> D;
    for(int i = 1; i <= D; i++) cin >> L[i] >> R[i];

    LT[1] = A[1];
    for(int i = 2; i <= N; i++) {
        // LT[i] = max(A[i], LT[i - 1]);
        if(LT[i - 1] < A[i]) LT[i] = A[i];
        else LT[i] = LT[i - 1];
    }

    RT[N] = A[N];
    for(int i = N-1; i >= 1; i--) {
        // RT[i] = max(A[i], RT[i + 1]);
        if(RT[i + 1] < A[i]) RT[i] = A[i];
        else RT[i] = RT[i + 1];
    }

    for(int i = 1; i <= D; i++) {
        cout << max(LT[L[i] - 1], RT[R[i] + 1]) << endl;
    }
    
    return 0;
}