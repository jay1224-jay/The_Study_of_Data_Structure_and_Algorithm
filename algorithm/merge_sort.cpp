#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &v, int Begin, vector<int> a, vector<int> b) {
    int len = a.size() + b.size();

    vector<int> tmp(len);

    int ap = 0, bp = 0;
    for ( int i = 0 ; i < len ; ++i ) {
        if ( ap == a.size() ) {
            copy(b.begin()+bp, b.end(), tmp.begin()+i);
            cout << i << "d: " << bp << endl;
            break;
        }
        if ( bp == b.size() ) {
            copy(a.begin()+ap, a.end(), tmp.begin()+i);
            cout << "d: " << ap << endl;
            break;
        }
            
        tmp[i] = min(a[ap], b[bp]);
        if (a[+ap] < b[bp]  ) {
            ++ap;
        } else {
            ++bp;
        }
    }

    cout << "tmp = ";
    for ( auto& e : tmp )
        cout << e << " ";
    cout << endl;

    for ( int i = 0 ; i < len ; ++i ) {
        v[Begin + i] = tmp[i];
    }

}


void merge_sort(vector<int> &v, int Begin, int End) {
    /*  
     *  sort v in the range of [Begin, End) 
     *  
    */

    // sort(v.begin() + Begin, v.begin()+End);

    int mid = (Begin + End)/2;
    // cout << "mid = " << mid << endl;
    /*
    for ( auto& e : v ) 
        cout << e << " ";
    cout << endl;
    */

    if ( mid != Begin ) {
        merge_sort(v, Begin, mid);
        merge_sort(v, mid, End);

        vector<int> a(v.begin() + Begin, v.begin() +mid),
                    b(v.begin() + mid, v.begin() + End);
        
        merge(v, Begin, a, b);
    }
}

int main() {


    // vector<int> a = {4, 1, 3, 5, 2, 8, 23, 10};
    int n;
    cin >> n;
    vector<int> a(n);
    for ( auto& e : a )
        cin >> e;
    vector<int> backup = a;

    for ( auto & e : a ) {
        cout << e << " ";
    }
    cout << endl;

    merge_sort(a, 0, a.size());

    cout << "merge sort\n";
    for ( auto & e : a ) {
        cout << e << " ";
    }
    cout << endl;
    cout << "std::sort" << endl;
    sort(backup.begin(), backup.end());
    for ( auto & e : backup ) {
        cout << e << " ";
    }
    cout << endl;


    return 0;
}
