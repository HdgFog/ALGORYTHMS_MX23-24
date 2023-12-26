#include <iostream> 
#include <vector> 
using namespace std;

long fib_ultimate(int n)
{
    int i;
    long back2 = 0, back1 = 1;
    long next;
    if (n == 0) return 0;
    if (n == 1) return 1;
    for (i = 2; i <= n; i++) {
        next = back1 + back2;
        back2 = back1;
        back1 = next;
    }
    return back1;
}

int main()
{
    cout << fib_ultimate(7) << endl;
}