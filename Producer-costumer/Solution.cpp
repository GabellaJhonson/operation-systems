#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
int signal = 0;
mutex m;
condition_variable cv;
bool checkPrimeNumber(int n) {
    bool isPrimeNumber = true;
    if (n == 0 || n == 1) {
        isPrimeNumber = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrimeNumber = false;
                break;
            }
        }
    }
    return isPrimeNumber;
}
void FindPrime(int n) {
    for (int i = n;; i++) {
        if (checkPrimeNumber(i)) {
            signal = i;
            cv.notify_all();
            return;
        }
    }
}
void Print(){
    unique_lock<mutex> guard(m);
    while(signal == 0){
    cv.wait(guard);
    }
    cout << signal;
}
int main() {
    int n;
    cin >> n;
    thread first(FindPrime, n);
    thread second(Print);
    first.join();
    second.join();
}
