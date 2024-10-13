#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int w,int h) {
    ll answer = 1;
    ll gcd = 0;
    ll square = (ll)w * (ll)h;
    
    if(w == h)
        return square - w;
    
    int a = w > h ? w : h;
    int b = w > h ? h : w;
    
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    
    return square - (w + h - gcd);
}