#include <iostream>
using namespace std;

int main()
{
    string N;
    cin >> N;

    int Answer = 0;
    for(int i = 0; i < N.size(); i++) {
        int kurai = 1 << (N.size() - 1 - i);
        if(N[i] == '1') Answer += kurai;
    }
    cout << Answer << endl;
    return 0;
}