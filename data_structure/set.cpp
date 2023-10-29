#include <bits/stdc++.h>

using namespace std;

int main() {

    set<int> s = {1, 2, 2, 5, 3, 4, 5};
    unordered_set<int> y = {1, 2, 2, 5, 3, 4, 5};

    printf("index | count\n");

    // cannot use for(int i = 0;i<s.size();++i) because set is not 

    for (auto& e : y ) {
        printf("%-3d | %-3ld\n", e, s.count(e));
    }

    cout << "normal set:\n";
    for ( auto& e : s ) {
        cout << e << " ";
    }
    cout << endl;

    cout << "unordered_set:\n";
    for ( auto& e : y ) {
        cout << e << " ";
    }
    cout << endl;

    cout << endl;

    return 0;
}
