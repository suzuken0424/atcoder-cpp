#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    /**
     * （別解）ライブラリを使う
     * long long N;
     * cin >> N;
     * 
     * bitset<10> bs(N);
     * 
     * cout << bs << endl;
     * return 0;
    */ 

    int N;
    cin >> N;

    for(int i = 9; i >= 0; i--) {
        int wari = (1 << i); // iビット左にシフトする → 2^i
        cout << (N / wari) % 2;
    }
    cout << endl;
    return 0;
}