#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> *arr, int n)
{
    for (int i = 0; i < n-1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if ((*arr)[min] > (*arr)[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap((*arr)[i], (*arr)[min]);
		}
	}
}

void solve(vector<int> *a, int c, int n)
{
    int l = 0, r = n-1;
    int count = 0;
    while((l != r) && (!a->empty()))
    {
        if((*a)[l] + (*a)[r] <= c )
        {
            count++;
            a->erase(a->begin() + r);
            a->erase(a->begin());
            r = a->size() - 1;
        }
        else
        {
            a->erase(a->begin() + r);
            count++;
        }
    }
    if(!a->empty())
    {
        count++;
    }
    cout << "共需要" << count << "艘船" << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> *a = new vector<int> (n);
    for(int i = 0; i < n; i++)
    {
        cin >> (*a)[i];
    }
    int C = 0;
    cin >> C;
    selectionSort(a, n);
    solve(a, C, n);
}