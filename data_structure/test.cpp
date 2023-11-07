#include <bits/stdc++.h>
using namespace std;

#define MAX (int)1e5

int factorial(int n) {

    int ans = 1;
    for ( int i = 2 ; i <= n ; ++i ) {
        ans *= i;
    }

    return ans;
}

int dup(string s, char c) {

    int d = 0;
    for (auto& e : s) {
        if ( e == c )
            ++d;
    }
    return d;
}

int dp[MAX] = {1};

int main() {

    ios::sync_with_stdio(0);cout.tie(0);

    
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> books(n);

    for ( int i = 0 ; i < n ; ++i ) {
        cin >> books[i].first; // price
    }
    for ( int i = 0 ; i < n ; ++i ) {
        cin >> books[i].second; // pages
    }

    int max_price;
    for ( int i = 1 ; i <= x ; ++i ) {

        max_pages = 0;
        for ( auto& e : books ) {

            if ( e < i ) continue; 
            max_pages = max(max_pages, dp[i-e]);

    return 0;
}
