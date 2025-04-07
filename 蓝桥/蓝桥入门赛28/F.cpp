#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> result;

    int len = s.size();
    for (int i = 0; i <= len; ++i) { 
        for (char d = '0'; d <= '9'; ++d) {
            string newStr = s.substr(0, i) + d + s.substr(i);
            if (newStr[0] != '0') { 
                result.insert(newStr);
            }
        }
    }

    cout << result.size() << endl;
    return 0;
}
