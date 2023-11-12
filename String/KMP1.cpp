//Athour : 7amok4a
//Return Dark ^_^ &_&
#include <bits/stdc++.h>
using namespace std;
vector<int> ComputePrefix (string &pat) {
    int m = (int) pat.size() ;
    vector<int> longestprefix(m) ;
    for (int i = 1 , k = 0 ; i < m ; ++i){
        while (k>0 and pat[k] != pat[i]) {
            k = longestprefix[k-1] ;
        }
        if(pat[k] == pat[i]) {
            longestprefix[i] = ++k ;
        }
        else {
            longestprefix[i] = k ;
        }
    }
    return longestprefix; 
}
void KMP (string &str , string &pat) {
    int n = (int)str.size() , m = (int)pat.size() ;
    vector<int> longestprefix = ComputePrefix(pat) ;
    for (int i  = 0 , k = 0 ; i < n ; ++ i) {
        while (k > 0 and pat[k] != str[i]) {
            k = longestprefix[k-1] ;
        }
        if (pat[k] == str[i])  {
            ++k ;
        }
        if(k == m) {
            cout << i - m + 1 << endl ;
            k = longestprefix[k-1] ; 
        }
    }
 }
int main() {
    string str, pat ;    cin >> str >> pat ;
    KMP(str , pat) ;
    return 0;
}
