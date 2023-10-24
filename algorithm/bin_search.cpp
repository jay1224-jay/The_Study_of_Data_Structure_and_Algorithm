#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

typedef struct {
    time_t begin_time;
    time_t end_time;

    time_t timeSpan() {
        return end_time - begin_time;
    }
} Timer;

int bin_search_recur( vi& con, int target, int begin, int end ) {

    int mid = (begin + end) / 2;
    
    if ( con[mid] == target ) {
        return mid;
    } 
    else if ( con[mid] != target ) {

        if ( mid == begin ) {
            return -1; // not found
        }

        if ( con[mid] > target ) {
            // searching the left side
            return bin_search_recur(con, target, begin, mid);
        }

        if ( con[mid] < target ) {
            // searching the right side
            return bin_search_recur(con, target, mid, end);
        }
    
    }

    return -1;
}

int bin_search_while_loop(vi& con, int target, int begin, int end ) {

    while ( begin <= end ) {
        int mid = (begin+end)/2;
        if ( con[mid] == target ) {
            printf("found k\n");
            // return mid;
        }

        if ( con[mid] > target ) end = mid - 1;
        else                begin = mid + 1;
    }

    return -1;
}
 

int main() {

    // vi a = {1, 4, 7, 10, 55, 345, 400, 917};

    srand(time(NULL));

    long long int n, target;
    cin >> n;
    vi a(n);
    printf("generating random numbers\n");
    for ( auto& e : a ) 
        e = rand() % n;

    cin >> target;

    sort(a.begin(), a.end());

    for ( auto& e : a ) 
        cout << e << " ";
    cout << endl;



    printf("start binary search\n");
    int index = bin_search_while_loop(a, target, 0, a.size());



    if ( index != -1 ) {
        // found
        cout << "Found " << target << " at " << index << endl;
    }
    else {
        cout << "Target: " << target << " not found\n";
    }

    printf("start normal search\n");

    int flag = 0;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( a[i] == target ) {
            cout << "found\n";
            flag = 1;
            break;
        }
    }
    if (!flag) 
        cout << "not found\n";


    return 1;
}

