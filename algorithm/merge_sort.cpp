#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &v, int a1, int a2, int b1, int b2 ) {
    int len = (a2 - a1) + (b2 - b1);

    vector<int> tmp(len);

    int ap = 0, bp = 0;
    for ( int i = 0 ; i < len ; ++i ) {
        tmp[i] = min(v[a1+ap], v[b1 + bp]);
        if (v[a1+ap] < v[b1 + bp]  ) {
            ++ap;
        } else {
            ++bp;
        }
    }

    for ( int i = 0 ; i < len ; ++i ) {
        if ( i < len/2 )
            v[a1 + i] = tmp[i];
        else
            v[b1 + i - len/2] = tmp[i];
    }
}


void merge_sort(vector<int> &v, int Begin, int End) {
    /*  
     *  sort v in the range of [Begin, End) 
     *  
    */

    // sort(v.begin() + Begin, v.begin()+End);

    int mid = (Begin + End)/2;
    cout << "mid = " << mid << endl;
    for ( auto& e : v ) 
        cout << e << " ";
    cout << endl;

    if ( mid != Begin ) {
        merge_sort(v, Begin, mid);
        merge_sort(v, mid, End);
        
        merge(v, Begin, mid, mid, End);
    }
    else {
        ;
    }

    ;
}

int main() {


    vector<int> a = {4, 1, 3, 5, 2, 8, 23, 10};

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

    return 0;
}
