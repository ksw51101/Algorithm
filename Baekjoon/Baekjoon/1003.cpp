#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 0)
            cout << 1 << ' ' << 0 << endl;
        else if (N == 1)
            cout << 0 << ' ' << 1 << endl;
        else
            cout << fibonacci(N-1) << ' ' << fibonacci(N) << '\n';
    }
}
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}