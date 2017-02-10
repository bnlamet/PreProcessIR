# PreProcessIR
Pre-Processing for an Information Retrieval System coded as part of a course on Computer Algorithms.
More information can be found in this [paper](https://drive.google.com/file/d/0B21tgVksEvzLaVROc1BsV3JQRXM/view?usp=sharing).

This project is designed to take input files and generate a cleaned list of stemmed keywords that would be used for information retrieval. It reads in textfiles, creates a set of words, excluding numbers and symbols that are not English, cleans each word of punctuation and repetition, and finally stems the words before reading them into a new clean file.

The format of the code is as follows:

Ask user for input:
"Type (1) if you want to clean your data."
If the user does not type int, output "invalid entry"
If user types not 1, output "okay, bye"
If the user types 1....
For each txt file:
Loop over each text file by creating a string name that is "txt0"+str(int)+".txt"
Where the int iterates from 1 to 9
Loop over each text file by creating a string name that is "txt"+str(int)+".txt"
Where the int iterates from 10 to 40
Read in text word-by-word
Strip punctuation
Make all lowercase
Strip numbers in [] or in /"garble"/
Strip all words that are just numbers, or representative of numbers (31st, 2nd)
Add all unique words of the txt file to a set since sets do not allow for duplicate words
Compare that list to the stop words list
Only output a list of the set difference between the txt file and the stop words
Then, stem the similar words in this output list
Write the now cleaned & stemmed words in a new file called oldname_cleaned.txt
Store all clean files in a folder called "corpus"
If the user types 2...
The program exits.
Efficiency: The space complexity of the algorithm is that of the number of words in a file plus the number of stop words. First we make a set containing all of the cleaned words in our file before we compare it to the stop words set. During stemming we must have a buffer string but this is negligible.

The time complexity is O(n) to insert a cleaned word into the set for the cleaned file. Since all of the strings are less than a finite number of characters, cleaning can be done in O(1) The complexity of the Porter Algorithm is O(1) for each word since it will do a finite number of checks of the end letters in the word and manipulations of the string can be done in constant time. Each word can be stemmed in O(l) where l is the word length. The overall complexity of the whole algorithm would then be between O(n) and O(n*l) where n is the number of words in the file and the average length of each word is l.
