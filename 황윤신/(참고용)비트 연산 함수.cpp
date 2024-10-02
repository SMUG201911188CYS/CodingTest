/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//https://bloodstrawberry.tistory.com/1035 1비트 개수 세기
//https://bloodstrawberry.tistory.com/1034 비트 단위로 출력하기

#include <iostream>
using namespace std;

template <typename T>
void PrintBitNumber(T number) {
    unsigned int bitSize = sizeof(number) * 8;

    //signed의 MSB 고려 
    T mask = (1ull) << (bitSize - 1);
    cout << ((number & mask) == mask);

    mask = (1ull) << (bitSize - 2);
    for (int i = 1; i < bitSize; i++) {
        cout << ((number & mask) == mask);
        mask >>= 1;
        if (i % 8 == 7) cout << ' ';
    }
    cout << '\n';
}

template <typename T>
void PrintBitCount(T number) {
    //number & number -1 비트 연산을 하면 항상 가장 오른쪽에 있는 1비트가 사라진다.
    //0->0 으로, 1이상값->1으로.
    int count = !!number;
    while (number &= (number - 1)) {
        count++;
    }
    cout << count;
}

template <typename T>
int get_bit_gap(T src, T tgt) {
    int gap = 0;

    //MSB 고려
    int bit_size = sizeof(src) * 8;
    T mask = (1ull) << (bit_size - 1);
    if (((mask & src) == mask) != ((mask & tgt) == mask)) gap++;

    mask = (1ull) << (bit_size - 2);
    for (int i = 1; i < bit_size; i++) {
        if (((mask & src) == mask) != ((mask & tgt) == mask)) gap++;
        mask >>= 1;
    }

    return gap;
}

int main()
{
    int a = 123;
    int b = 1234;

    PrintBitNumber(a);
    PrintBitNumber(b);

    cout << get_bit_gap(a, b);

    return 0;
}