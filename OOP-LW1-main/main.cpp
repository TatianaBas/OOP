#include <iostream>
#include <string>
#include "check.hpp"


using namespace std;

int main(){
    string s;
    getline(cin, s);
    cout << check(s) << endl;
}