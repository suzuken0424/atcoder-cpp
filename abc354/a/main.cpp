#include <iostream>
using namespace std;

int main()
{
    int H;
    cin >> H;

    int plantHight = 1;
    int glowHight = 2;
    int count = 1;
    while(plantHight <= H) {
        plantHight += glowHight;
        glowHight = glowHight * 2;
        count++;
    }
    cout << count << endl;
    return 0;
}