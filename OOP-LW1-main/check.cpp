#include <string>

using namespace std;

int check(string s){
    int count = 0;

    for (int i = 0; i < s.size(); i++){
        if ((s[i] == 'a') or (s[i] == 'e') or (s[i] == 'i') or (s[i] == 'o') or (s[i] == 'u') or (s[i] == 'y')){
            count+=1;
        }
    }
    return count;
}
