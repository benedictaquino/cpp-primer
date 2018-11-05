/* This program uses a series of if statements to count the number of vowels 
 * in text read from the standard input */
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch) {
        ch = tolower(ch);
        if (ch == 'a') ++aCnt;
        else if (ch == 'e') ++eCnt;
        else if (ch == 'i') ++iCnt;
        else if (ch == 'o') ++oCnt;
        else if (ch == 'u') ++uCnt;
    }
    // print results
    cout << "Number of vowel a:\t" << aCnt << "\n"
         << "Number of vowel e:\t" << eCnt << "\n"
         << "Number of vowel i:\t" << iCnt << "\n"
         << "Number of vowel o:\t" << oCnt << "\n"
         << "Number of vowel u:\t" << uCnt << endl;

    return 0;
}
