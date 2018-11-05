/* This program reads a sequence of strings from the standard input until
 * either the same word occurs twice in succession or all the words have 
 * been read. */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string word, oldWord; // initialize empty strings
    cin >> oldWord;       // read first string from standard input
    while (cin >> word) { // read strings from standard input
        // if a word is repeated print word and terminate loop
        if (word == oldWord) {
            cout << "The word \"" << word << "\" was repeated." << endl;
            break;
        }
        oldWord = word; // copy the value from word into oldWord
    }
    if (!cin) cout << "No words were repeated." << endl;
    return 0;
}
