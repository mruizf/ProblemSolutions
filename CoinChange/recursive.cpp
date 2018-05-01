#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

long getWays(long n, vector < long > c){
    // Complete this function
    
    if (c.size() == 1)
    {
        if (n % c[0] == 0)
            return 1;
        else 
            return 0;
    }
        
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    vector<long> t = c;
    
    t.pop_back();
    
    return getWays(n,t) + getWays(n-c.back(),c);
    
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    
    sort(c.begin(),c.end());
    
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout << ways << endl;
    return 0;
}