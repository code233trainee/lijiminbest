#include <bits/stdc++.h>
using namespace std;
// struct person{
//     string name;
//     int score;
// };
bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if(a.second > b.second)
    {
        return true;
    }
    if(a.second < b.second)
    {
        return false;
    }
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return true;
}
int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int score[] = {a, b, c, d, e};
    vector<pair<string, int>> people = {{"ABCDE", 0}, {"BCDE", 0}, {"ACDE", 0}, {"ABDE", 0}, 
                                   {"ABCE", 0}, {"ABCD", 0}, {"CDE", 0}, {"BDE", 0},
                                   {"ADE", 0}, {"BCE", 0}, {"ACE", 0}, {"BCD", 0},
                                   {"ABE", 0}, {"ACD", 0}, {"ABD", 0}, {"ABC", 0},
                                   {"DE", 0}, {"CE", 0}, {"BE", 0}, {"CD", 0},
                                   {"AE", 0}, {"BD", 0}, {"AD", 0}, {"BC", 0},
                                   {"AC", 0}, {"AB", 0}, {"E", 0}, {"D", 0}, {"C", 0},
                                   {"B", 0}, {"A", 0}};
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < people[i].first.length(); j++)
        {
            people[i].second += score[people[i].first[j] - 'A'];
        }
    }
    sort(people.begin(), people.end(), cmp);
    for(int i = 0; i < 31; i++)
    {
        cout << people[i].first << "\n";
    }
    return 0;
}