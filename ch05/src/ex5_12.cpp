/* This program uses a switch statement to count the number of vowels, blank 
 * spaces, tabs, newlines, ff, f1, and fi read from standard input */
#include <iostream>

using std::cin; using std::cout; using std::endl; using std::noskipws;

int main()
{
    // initialize counters for each vowel, blank spaces, tabs, newlines
    // ff, f1, and fi
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
             spCnt = 0, tabCnt = 0, nwlCnt = 0,
             ffCnt = 0, f1Cnt = 0, fiCnt = 0;
    char ch, chOld;
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
                if (chOld == 'f') ++fiCnt;
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
            case '1':
                if (chOld == 'f') ++f1Cnt;
                break;
            case 'f':
                if (chOld == 'f') ++ffCnt;
        }
        chOld = ch;
    }
    // print results
    cout << "Number of vowel a:\t" << aCnt << "\n"
         << "Number of vowel e:\t" << eCnt << "\n"
         << "Number of vowel i:\t" << iCnt << "\n"
         << "Number of vowel o:\t" << oCnt << "\n"
         << "Number of vowel u:\t" << uCnt << "\n"
         << "Number of spaces:\t" << spCnt << "\n"
         << "Number of tabs:\t\t" << tabCnt << "\n"
         << "Number of newlines:\t" << nwlCnt << "\n"
         << "Number of ff's:\t\t" << ffCnt << "\n"
         << "Number of f1's:\t\t" << f1Cnt << "\n"
         << "Number of fi's:\t\t" << fiCnt << endl;

    return 0;
}
