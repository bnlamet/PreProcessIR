#include <stdio.h>
#include <assert.h>
#include <iostream> //allows you to print stuff
#include <cstring>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

//****IGNORE THIS INCOMPLETE AND BAD CODE.

set<string> stem(set<string> leafs){
    set<string> stems;//create empty set of "stems"
    //For each word in given set
    for (set<string>::const_iterator i = leafs.begin(); i != leafs.end(); ++i) {
            string s = *i; //current string
        }

    return stems;
} //end stem


/*
int main(){
    set <string> stemmm = {"cats","cat","related","relate"};
    set <string> stemmmm = stem(stemmm);
    for(auto i = stemmmm.begin(); i != stemmmm.end(); i++){
        cout << *i << endl;
    }
    return 0;
}*/