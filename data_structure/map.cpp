#include <bits/stdc++.h>

#define print(x) cout << x << endl;

using namespace std;
int main() {

    map<string, int> age;

    age["jay"] = 17;
    age["peter"] = 60;

    print(age["jay"]);
    print(age["peter"]);
    print(age["eric"]); // 0, because age doesn't contain the key , return 0;
    // afterwards, the key will be added with default value 0

    cout << "----------------\n";

    for ( auto& e : age ) {
        // cout << e.first << " " << e.second << endl;
        printf("%-6s | %-3d\n", e.first.c_str(), e.second);
    }

    cout << sizeof(age) << endl;
    
    cout << "----------------\n";
    string name;
    print("Enter the name you would like to search:");

    cin >> name;

    if ( age.count(name) ) {
        // containing the key name

        cout << "Age: ";
        print(age[name]);

    } else {
        print("Not in the database");
    }



    return 0;

}
