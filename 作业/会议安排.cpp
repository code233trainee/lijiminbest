#include <bits/stdc++.h>
using namespace std;
int i = 0;
int max(vector<int>& a)
{
    int j = 0;
    int maxIndex = 0;
    bool jumj = true;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != 0)
        {
            jumj = false;
            if(a[i] >= j)
            {
                j = a[i];
                maxIndex = i;
            }
        }
    }
    a[maxIndex] = 0;
    return jumj ? 0 : j;
}

void selectionSort(vector<int>& arr, int n)
{
    for (int i = 0; i < n-1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (arr[min] < arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap(arr[i], arr[min]);
		}
	}
}

void solve(vector<int>& A, vector<int>& B)
{
    int count = 0;
    while(max(A))
    {
        int maxA = max(A);
        int maxB = B[i];
        if(maxB >= maxA)
        {
            count++;
            i++;
        }
    }
    cout << "最多安排" << count << "场会议";
    
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> a(n);//代表会议所需的人数
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m = 0;
    cin >> m;
    vector<int> b(m);//代表会议室能容纳的人数
    for(int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    selectionSort(b, b.size());
    solve(a, b);
}