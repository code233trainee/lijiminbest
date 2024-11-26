#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    
    int a = 1, b = 1, c = 1, d = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;    
        int su = 0;
        
        if((a > c) || (b > d))
        {
            if((a >= c) && (b >= d))
            {
                su++;
            }
        }
        if((a > d) || (b > c))
        {
            if((a >= d) && (b >= c))
            {
                su++;
            }
        }
        
        if((b > c) || (a > d))
        {
            if((b >= c) && (a >= d))
            {
                su++;
            }
        }
        if((b > d) || (a > c))
        {
            if((b >= d) && (a >= c))
            {
                su++;
            }
        }
        
        cout << su << endl;
    }
}

// #include <iostream>
// using namespace std;
// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int ans=0;
// 		int a,b,c,d;
// 		cin>>a>>b>>c>>d;
//         if(a>=c&&b>d||a>c&&b>=d)ans++;
//         if(a>=d&&b>c||a>d&&b>=c)ans++;
//         cout<<ans*2<<endl;	
//     } 
// }