//Athour : 7amok4a
//Return Dark ^_^ &_&
#include <bits/stdc++.h>
using namespace std;
const int MX = 26 ;
struct trie {
    trie * child[MX] ;
    bool isLeaf ;
    trie () {
        memset(child , 0 , sizeof(child)) ;
        isLeaf = 0 ;
    }
    void insert (char *str) {
        if(*str == '\0') {
            isLeaf = 1 ;
        }
        else {
            int cur = *str - 'a' ;
            if (child[cur] == 0) {
                child[cur]  = new trie () ;
                child[cur]->insert(str+1) ;
            }
        }
    }
    bool wordExit (char *str) {
        if(*str == '\0') {
            return isLeaf ;
        }
        int cur = *str - 'a' ;
        if (child[cur] == 0) {
                return false ;
            }
        return child[cur]->wordExit(str+1) ;
        }
    bool prefixExit (char *str) {
        if(*str == '\0') {
            return true ;
        }
        int cur = *str - 'a' ;
        if (child[cur] == 0) {
            return false ;
        }
        return child[cur]->prefixExit(str+1) ;
    }
};
int main() {

    return 0;
}
