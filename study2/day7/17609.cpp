#include <iostream>
#include <algorithm>
using namespace std;

int t;

int isPalindrome(string str) {
    int len = str.size();
    int limit = len/2;
    bool answer = true;
    int left = 0;
    int right = len-1;
    bool check;
    while(left < right) {
        if(str[left] != str[right]) {
            if(str[left+1] == str[right]) {
                string temp_str = str.substr(left+1, right-left);
                string temp_str_reverse = temp_str;
                reverse(temp_str_reverse.begin(), temp_str_reverse.end());
                if(temp_str == temp_str_reverse) {
                    return 1;
                }
            }
            if(str[left] == str[right-1]) {
                string temp_str = str.substr(left, right-left);
                string temp_str_reverse = temp_str;
                reverse(temp_str_reverse.begin(), temp_str_reverse.end());
                if(temp_str == temp_str_reverse) {
                    return 1;
                }
            }
            return 2;
        }
        else {
            left += 1;
            right -= 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=0;i<t;i++) {
        string str;
        cin >> str;
        cout << isPalindrome(str) << endl;
        
    }
}