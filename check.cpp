/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. 
An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.
- Note that an empty string is also considered valid.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ic cout << __LINE__ << endl;


bool check(string str) {
    if(str.size() == 0) return true;
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