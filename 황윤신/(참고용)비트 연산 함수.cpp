/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//https://bloodstrawberry.tistory.com/1035 1��Ʈ ���� ����
//https://bloodstrawberry.tistory.com/1034 ��Ʈ ������ ����ϱ�

#include <iostream>
using namespace std;

template <typename T>
void PrintBitNumber(T number) {
    unsigned int bitSize = sizeof(number) * 8;

    //signed�� MSB ��� 
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
    //number & number -1 ��Ʈ ������ �ϸ� �׻� ���� �����ʿ� �ִ� 1��Ʈ�� �������.
    //0->0 ����, 1�̻�->1����.
    int count = !!number;
    while (number &= (number - 1)) {
        count++;
    }
    cout << count;
}

template <typename T>
int get_bit_gap(T src, T tgt) {
    int gap = 0;

    //MSB ���
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