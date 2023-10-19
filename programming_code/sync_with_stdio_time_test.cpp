streambuf/* 
 *   
 *   A small test for comparing code with and without std::ios::sync_with_stdio(0);
 *
 *
 *
 *  */

#include <iostream>
#include <fstream>
#include <string>

#define NUMBER_CHAR 100000

using namespace std;

int main() {


    int begin_time, end_time, not_use, use;
    cout << "print " << NUMBER_CHAR << " characters\n";

    ofstream out1("out1.txt");
    streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    cout.rdbuf(out1.rdbuf()); //redirect std::cout to out.txt!

    begin_time = time(0);
    for ( int i = 0 ; i < NUMBER_CHAR ; ++i ) {
        cout << "a";
    }
    end_time = time(0);
    not_use = end_time - begin_time;


    ofstream out2("out2.txt");
    coutbuf = std::cout.rdbuf(); //save old buf
    cout.rdbuf(out2.rdbuf()); //redirect std::cout to out.txt!
    // use std::ios::sync_with_stdio(0);

    ios::sync_with_stdio(0);

    begin_time = time(0);
    for ( int i = 0 ; i < NUMBER_CHAR ; ++i ) {
        cout << "a";
    }
    end_time = time(0);
    use = end_time - begin_time;

    cout.rdbuf(coutbuf);
    cout << endl << endl;

    cout << "Not use sync_with_stdio(0). \nTime: " << not_use << endl;
    cout << "Use sync_with_stdio(0). \nTime: " << use << endl;

    return 0;
}

