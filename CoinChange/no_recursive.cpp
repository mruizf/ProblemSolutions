#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


long table[50][251];

long getWays(long n, vector < long > c){
    // Complete this function
    
    for (int i =0; i<=n ;i++)
    {
        if (i % c[0] == 0)
            table[0][i] = 1; 
        else
            table[0][i] = 0;
    }       
    
    for (int i =0; i<=n ;i++)
    {    
        for (int k = 1,lim = c.size(); k <= lim; k++ )
        {
            long p = 0;
            if (i - c[k] >= 0 )
                p = table[k][i - c[k]];
            table[k][i] = p + table[k-1][i]; 
        }
    }
        
    return table[c.size()][n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long    ways = getWays(n, c);
    cout << ways << endl;
    return 0;
}