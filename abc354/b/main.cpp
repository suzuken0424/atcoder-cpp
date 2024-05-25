#include <iostream>
#include<algorithm>
// #include <vector>
// #include <string>
// #include <algorithm> 
using namespace std;

int main()
{
    int N;
    cin >> N;

    string S[100];
    int sum = 0;
    for(int i = 0; i < N; i++) {
        int C;
        cin >> S[i] >> C;
        sum += C;
    }

    sort(S, S+N);

    cout << S[sum % N] << endl;

    return 0;
}