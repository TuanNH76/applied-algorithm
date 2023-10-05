#include<bits/stdc++.h>
#define MAX_N 1000005

using namespace std;

int n, q;
int st[23][MAX_N];

main()
{
    cin >> n;
    for(int i=0; i<n; ++i){
        cin>> st[0][i];
    }
    for(int j=1; j <= (__lg(n)); ++ j){
        for(int i = 0; i + (1<< (j-1)) - 1 < n; ++i){
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]); 
        }
    }
    long long ans = 0;
    cin >> q;
    for(int i=1; i<=(q); ++i){
        int l, r;
        cin >> l >> r;
        int k = __lg(r - l + 1);
        ans += 1ll * min(st[k][l], st[k][r - (1<<k) +1]);
    }
    cout << ans;
    return 0;
}