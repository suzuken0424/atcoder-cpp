#include <iostream>
using namespace std;


int main()
{
    int N;
    cin >> N;

    int A[N];
    for (int i = 1; i <= N; i++) cin >> A[i];

    bool Answer = false;
    for (int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            for(int k = j + 1; k <= N; k++) {
                if (A[i] + A[j] + A[k] == 1000) {
                    Answer = true;
                    break;
                }
            }
        }
    }

    if(Answer) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}