#include <iostream>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;

    int count = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            // iとjだけでNを超えた場合はNG
            int k = K - i - j;
            if(k >= 1 && k <= N) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}