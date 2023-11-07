#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
void search(int k) {
    
    if ( k == n ) {
        // process subset

        for (auto& e : v) {
            cout << e << " ";
        }
        cout << endl;
    } else {
        search(k+1);
        v.push_back(k);
        search(k+1);
        v.pop_back();
    }

}



int main() {

    
    int a;
    cin >> a;


    n = a;

    search(1);

    return 0;
}
