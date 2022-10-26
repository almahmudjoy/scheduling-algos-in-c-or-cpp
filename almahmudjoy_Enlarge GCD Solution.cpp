#include<bits/stdc++.h>
using namespace std;
 
#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
 
const int MAX = 15000002;
bool flag[MAX];
int fr[MAX];
int main()
{
    FastRead
 
    int n;
    cin >> n;
    int a[n+2] , gc = -1 , best = -1 , mx  = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mx = max(mx,a[i]);
        fr[a[i]]++;
        if(gc == -1)
            gc = a[i];
        else
            gc = __gcd(a[i],gc);
    }
 
    best = INT_MAX;
    for(int i=gc+1;i<=mx;i++)
    {
        if(!flag[i])
        {
            int cnt = 0;
            for(int j=i;j<=mx;j+=i)
            {
                if(fr[j])
                    cnt += fr[j];
                flag[j] = 1;
            }
            if(cnt)
                best = min(best,n-cnt);
        }
    }
    if(best == INT_MAX)
        best = -1;
 
    cout << best << endl;
}
