#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

// #include <bits/stdc++.h>

#define MAX 5

typedef struct __ { 

    int stack[MAX] = {0};
    int * p_top = stack;
    
    int top(void) {
        return *p_top;
    }

    void push(int val) {

        if ( p_top - stack >= MAX - 1) {
            printf("Stack error: stack size limit exceeded. Max size: %d\n", MAX);
            return;
        }
        ++p_top;
        *p_top = val;

    }

    void pop(void) {

        *p_top = 0;
        --p_top;

    }

} my_stack;


int main() {


    my_stack s;
    
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


    return 0;
}
