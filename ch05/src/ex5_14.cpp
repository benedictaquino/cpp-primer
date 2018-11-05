/* This program reads strings from standard input and looks for duplicated words */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string word, oldWord, maxWord;
    cin >> oldWord;
    unsigned cnt = 1, maxCnt = 0;
    while (cin >> word) {
        if (word == oldWord) 
            ++cnt;
        else if (cnt > maxCnt) {
            maxCnt = cnt;
            maxWord = oldWord;
            cnt = 1;
        }
        else cnt = 1;
        oldWord = word;
    }

    if (cnt > maxCnt) {
        maxCnt = cnt;
        maxWord = oldWord;
    }

    cout << "The word " << maxWord << " occured " << maxCnt << " times." << endl;

    return 0;
}
