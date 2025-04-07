#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, h, m;
    cin >> t;
    cin >> h >> m;
    string Date = to_string(h) + "-";
    if (m < 10) {
        Date += "0" + to_string(m);
    }else {
        Date += to_string(m);
    }
    set<string> A, B, C;
    while(t--)
    {
        string id, year, time;
        cin >> id >> year >> time;
        if(year.substr(0, 7) != Date)
        {
            continue;
        }
        string check = time.substr(0, 2);
        if(check == "07" || check == "08" || check == "18" || check == "19" || time == "09:00:00" || time == "20:00:00")
        {
            A.insert(id);
        }
        else if(check == "11" || check == "12" || time == "13:00:00")
        {
            B.insert(id);
        }
        else if(check == "22" || check == "23" || check == "00" || time == "01:00:00")
        {
            C.insert(id);
        }
    }
    cout << A.size() << " " << B.size() << " " << C.size() << "\n";
    return 0;
}