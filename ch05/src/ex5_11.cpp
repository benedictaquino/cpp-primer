/* This program uses a switch statement to count the number of vowels, blank 
 * spaces, tabs, and newlines read from standard input */
#include <iostream>

using std::cin; using std::cout; using std::endl; using std::noskipws;

int main()
{
    // initialize counters for each vowel, blank spaces, tabs, and newlines
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
             spCnt = 0, tabCnt = 0, nwlCnt = 0;
    char ch;
    while (cin >> noskipws >> ch) {
        ch = tolower(ch);
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            case ' ':
                ++spCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++nwlCnt;
                break;
        }
    }
    // print results
    cout << "Number of vowel a:\t" << aCnt << "\n"
         << "Number of vowel e:\t" << eCnt << "\n"
         << "Number of vowel i:\t" << iCnt << "\n"
         << "Number of vowel o:\t" << oCnt << "\n"
         << "Number of vowel u:\t" << uCnt << "\n"
         << "Number of spaces:\t" << spCnt << "\n"
         << "Number of tabs:\t\t" << tabCnt << "\n"
         << "Number of newlines:\t" << nwlCnt << endl;

    return 0;
}
