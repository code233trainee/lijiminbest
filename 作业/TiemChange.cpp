#include <iostream>
#include <string>
using namespace std;

void valve(int t)
{
    int hour, minu, sec;
    minu = t / 60;
    sec = t % 60;

    hour = minu / 60;
    minu = minu % 60;

    cout << hour << ":" << minu << ":" << sec;
}

int main()
{
    int t = 0;
    cin >> t;
    valve(t);
}