/* This program reads a sequence of strings from the standard input until
 * either the same word that begins with an uppercase letter is repeated
 * or all the words have been read. */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string word, oldWord; // initialize empty strings
    while (cin >> word) { // read strings from standard input
        // if word does not begin with an uppercase letter continue to next word
        if (!isupper(word[0])) {
            oldWord = word;
            continue;
        }
        // if a word is repeated print word and terminate loop
        if (word == oldWord) {
            cout << "The word \"" << word << "\" was repeated." << endl;
            break;
        }
        oldWord = word; // copy the value from word into oldWord
    }
    if (!cin) cout << "No words that begin with an uppercase letter were repeated." << endl;
    return 0;
}
