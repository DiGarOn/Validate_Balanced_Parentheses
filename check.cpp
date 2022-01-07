#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ic cout << __LINE__ << endl;


bool check(string str) {
    bool res;

    vector<char> s;

    if(str[0] == ')' || str[0] == ']' || str[0] == '}') return false;
    for(int i = 0; i < str.size(); i++) {
        char let = str[i];
        s.push_back(let);
        if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if(s.size() == 1) return false;
            if(!((s[s.size()-2] == '(' && s[s.size()-1] == ')') || (s[s.size()-2] == '[' && s[s.size()-1] == ']') || (s[s.size()-2] == '{' && s[s.size()-1] == '}'))) return false;
            else {
                s.pop_back();
                s.pop_back();
            }
        }
    }

    if(s.size()  > 0) return false;
    return true;
}

int main() {
    string str;
    cin >> str;

    if(check(str)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}