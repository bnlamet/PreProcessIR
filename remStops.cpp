#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>

using namespace std;

/*  INPUTS:
        set<string> data - the string set version of a text file of data
        set<string> stop_word - the string set version of the stop words
    OUTPUTS:
        set<string> result - a string set of the text file with all stop words removed 
    DESCRIPTION:
        This function takes in the string sets of the data file and the stop words
        and uses the set difference operation to remove all stop words from the text.
            */

set<string> result; //output of the set difference

//Function to remove stop words
set<string> removeStops(set<string> data, set<string> stop_words){ //given a text file and the stop words
    set<string> result; //output of the set difference
    set<string> a = data; //text file we're cleaning
    set<string> b = stop_words; //stop words

    set_difference( a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
    
    //Output the result so you know it was right:
    /*cout << "Difference" << endl << "-------------" << endl;
    for (set<string>::const_iterator i = result.begin(); i != result.end(); ++i) {
        cout << *i << endl;
    }*/

    return result;
}