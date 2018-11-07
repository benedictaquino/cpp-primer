#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::end;

void print(const int *ip)
{
    if (ip) cout << *ip++ << " ";
}

void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << " "; // print the current element
    cout << endl;               // and advance the pointer
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) cout << ia[i] << " ";
    cout << endl;
}

void print(int (&arr)[2])
{
    for (auto elem : arr)
        cout << elem <<  " ";
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    // print(const int*)
    cout << "print(const int *ip)\ni: ";
    print(&i); 
    cout << endl;
    cout << "j: ";
    for (auto val : j) print(&val);
    cout << endl;
    // print(const int *beg, const int *end)
    cout << "print(const int *beg, const int *end)\ni: ";
    print(&i, &i + 1);
    cout << "j: ";
    print(j, end(j));
    // print(const int ia[], size_t size)
    cout << "print(const int ia[], size_t size)\ni: ";
    print(&i, 1);
    cout << "j: ";
    print(j, 2);
    // print(const int (&arr)[n])
    cout << "print(const int (&arr)[n])\ni: ";
    int ia[2];
    ia[0] = i;
    print(ia);
    cout << "j: ";
    print(j);
    return 0;
}
