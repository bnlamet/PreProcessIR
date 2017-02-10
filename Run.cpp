#include <stdio.h>
#include <assert.h>
#include <iostream> //allows you to print stuff
#include <cstring>
#include <fstream>
#include <sstream>
#include <set>  //those who do not use sets are lame
#include "remStops.cpp" //contains function to remove stop words
using namespace std;

set<string> clean(string word);
set<string> makesets(string fileName);

int main(){
     /*  INPUTS:
            None.
            User inputs 1 to clean files, 2 to exit.
        OUTPUTS:
            Cleaned files are written to the "corpus" folder. 
        DESCRIPTION:
            Main file that implements the project objectives.
            Line-by-line comments serve as a description.*/
            
    string response;
    cout << "Type 1 if you want to clean data.\nType 2 if you wish to exit." << endl; //Ask user if the want to clean
    cin >> response;
    if (response == "1"){ //If 1, continue:
        set<string> stopSet = makesets("stop_words.txt"); //make a string set of the stop words
        for(int i = 1; i <= 9;i++){ //for text files 1 to 9
            string num = to_string(i);
            string name = "txt0"+num;
            set<string> sets = makesets(name+".txt"); //make string set from the file
            sets = removeStops(sets,stopSet); //remove stop words
            //Assuming we had a stemming that worked, we would call that function here.
            
            //Now create the cleaned file and save it to the corpus
            string newname = "corpus/" + name + "_cleaned.txt";
            //for each string in set
            ofstream os(newname);
            for (set<string>::const_iterator i = sets.begin(); i != sets.end(); ++i) {
                string s = *i + "\n"; //add \n to dat string
                os<<s; //write dat string to dah file
            } //end writing to file
        } //end for 1 to 9    
        
        for(int i = 10; i <= 40;i++){ //for files 10 to 40
            string num = to_string(i);
            string name = "txt"+num;
            set<string> sets = makesets(name+".txt"); //make string set from file
            sets = removeStops(sets,stopSet); //remove stop words
            //stem...
            //new file...
            string newname = "corpus/" + name + "_cleaned.txt";
            //for each string in set
            ofstream os(newname);
            for (set<string>::const_iterator i = sets.begin(); i != sets.end(); ++i) {
                string s = *i + "\n"; //add \n to dat string
                os<<s; //write dat string to dah file
            } //end writing
        } //end txt files 10 to 40
        
        cout<<"The data has been cleaned and stored in the corpus folder."<<endl;
        cout<<"Thank you, good bye."<<endl;
    } //if
     if (response == "2"){ //If 2, quit.
        cout<<"Thank you, good bye."<<endl;
        return 0;
     }    
return 0;
} //end main function

set<string> makesets(string fileName){
   /*  INPUTS:
            string fileName - the text file to be read
        OUTPUTS:
            set<string> sets - a string set of the cleaned words from the file 
        DESCRIPTION:
            This function takes in the name of a text file and transforms the
            data in the text file into a set of strings of the cleaned words 
            from that file. This function reads in the text file word-by-word
            and calls upon the 'clean' function each time until the entire file
            has been converted into a clean set of strings of words.*/
    set<string> sets; 
    //Note: Using string sets means you automatically have unique elements only!
    
    ifstream myFile(fileName); //open file
    
    string word;
    while (myFile >> word){ //reads in file by words
        set<string> the = clean(word); //clean the word of unwanted elements
        for(auto i = the.begin(); i != the.end(); i++){ //for each word of the cleaned set
            sets.insert(*i); //adds word to set of strings
        }
    }
    myFile.close(); //close file when done, because that's good coding practice
    return sets;
} //end makesets()

set<string> clean(string dirty){ //remove unwanted elements from the word string
    /*  INPUTS:
            string dirty - a raw 'word' from the read of the text file
        OUTPUTS:
            set<string> ss - a set of the resulting cleaned words 
        DESCRIPTION:
            This function takes in a 'word', which is any string that was between
            spaces in the text file and therefore read as a word. It separates
            hyphenated words, removes function references, punctuation, nonsensical
            words and characters, non-alphabet characters, numbers, and sets the
            word to all lowercase. The function then returns a string set of the
            resulting clean words from the original dirty 'word'. */
            
    string s = dirty; //copy string so we can manipulate it
    set<string> ss;
    
    for (int i = 0; i < s.length(); i++){
        if(s[i] == '-'){ //words separated by hyphen are two words
            string word1 = s.substr(0,i);
            ss.insert(word1); //insert word before hyphen
            s = s.substr(i+1,s.length());//continue with the rest of the word as a new word
            i=0;
        }
        else if (s[i] == '['){ //removing references to sources of the form []
            int stops = i+1;
            while(s[stops] != ']'){
                stops++;
            }
            stops++;
            s.erase(i,stops);
            i--;
        }
        
        //remove things that are between / and / because they are internet nonsense
         else if (s[i] == '/'){ 
            int stops = i+1;
            while(s[stops] != '/'){
                stops++;
            }
            stops++;
            s.erase(i,stops);
            i--;
        }
        
        else if (ispunct(s[i])){ //remove all punctuation
            s.erase(i,i+1);
            i--;
        }
        else if(!isalpha(s[i])){ //removing non-alphabet letters
            s.erase(i,i+1);
            i--;
        }
        else if(isdigit(s[i])){ //removing nums
            s.erase(i,i+1);
            i--;
        }
        else if(isupper(s[i])){ //set the word to lowercase
            s[i] = tolower(s[i]);
        }
    }
    ss.insert(s);
    return ss;
}//end clean()