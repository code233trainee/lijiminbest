#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2, m;
    deque<int> q1, q2;
    set<int> sq1, sq2;
    cin >> n1 >> n2 >> m;
    while(m--)
    {
        int p;
        cin >> p;
        if(sq1.count(p))
        {
            q1.erase(find(q1.begin(), q1.end(), p));
            q1.push_front(p);
        }
        else if(sq2.count(p))
        {
            q2.erase(find(q2.begin(), q2.end(), p));
            sq2.erase(p);
            q1.push_front(p);
            sq1.insert(p);
            if(q1.size() > n1)
            {
                int temp = q1.back();
                q1.pop_back();
                sq1.erase(temp);
                if(q2.size() < n2)
                {
                    q2.push_front(temp);
                    sq2.insert(temp);
                }
            }
        }
        else
        {
            q2.push_front(p);
            sq2.insert(p);
            if(q2.size() > n2)
            {
                int temp = q2.back();
                q2.pop_back();
                sq2.erase(temp);
            }
        }
    }
    for(int i = 0; i < q1.size(); i++)
    {
        cout << q1[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < q2.size(); i++)
    {
        cout << q2[i] << " ";
    }
    cout << "\n";
    return 0;
}