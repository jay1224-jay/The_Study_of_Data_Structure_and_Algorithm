#include <bits/stdc++.h>
using namespace std;
int main() {

    stack<int> s;

    int n;
    cin >> n;

    int tmp;
    string op;
    s.push(0);
    while ( n-- ) {
        printf("top: %d\n", s.top());
        cin >> op;
        if ( op == "push" ) {
            cin >> tmp;
            s.push(tmp);
        } else if ( op == "pop" ) {
            s.pop();
        } else {
            printf("unknown operation\n");
        }
    }

    /*  you can only access top
    for ( auto& e : s ) {
        cout << e << " ";
    }
    cout << endl;
    */

    return 0;
}
