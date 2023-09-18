#include<bits/stdc++.h>
using namespace std;
int n, sum;
int cnt = 0, ans = 0;
int mem[100][100];
int find_way(int i, int val, int coin[]){
    if(val == 0){
        return 1;
    }
    if(i>=n || val<0) return 0;
    if(mem[i][val]!=-1) return mem[i][val];
    int take = find_way(i+1, val-coin[i], coin);
    int dont_take=find_way(i+1, val, coin);
    mem[i][val] = (take+dont_take);
    return mem[i][val];
}
int main()
{
    cin >> n >> sum;
    int coin[n];
    int cnt = 0;
    for(int i =0 ;i<n; ++i){
        cin >> coin[i];
    }
    for(int i =0 ;i<100; ++i){
        for(int j = 0; j<100; ++j){
            mem[i][j]=-1;
        }
    }
    for(int i = 0; i<n; ++i){
        cnt = max(cnt,find_way(i, sum, coin));
    }
    cout << cnt << endl;
}
