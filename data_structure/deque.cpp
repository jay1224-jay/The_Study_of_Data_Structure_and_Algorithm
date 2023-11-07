#include <bits/stdc++.h>
using namespace std;
int main() { 

    deque<int> d;

    d.push_back(1);
    d.push_back(3);
    d.push_front(2);

    for ( auto& e : d ) 
        cout << e << " ";
    cout << endl;

    d.pop_back(); // remove 3

    for ( auto& e : d ) 
        cout << e << " ";
    cout << endl;

    return 0;
}
