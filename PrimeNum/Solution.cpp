#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
int iter = 0;
mutex m;
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
void PrimeCheck(vector <int>& vec, vector <bool>& res) {
    int temp;
    while (1) {
        unique_lock<mutex> guard(m);
        if (iter == vec.size()) {
            return;
        }
        else {
            iter++;
            temp = iter;
        }
        guard.unlock();
        if(checkPrimeNumber(vec[temp - 1]))
            res[temp - 1] = 1;
    }
}
int main() {
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    cout << "Enter elements: " << endl;
    vector <int> vec(n);
    vector <bool> res(n);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }
   
    cout << endl;
    cout << "Enter count of threads: ";
    int sz;
    cin >> sz;
    vector <thread> th;
    for (int i = 0; i < sz; i++)
    {
        th.emplace_back(ref(vec), ref(res));  // на паре так делали
        //th.emplace_back([&vec, &res]() {PrimeCheck(vec, res); });
    }
    for (int i = 0; i < sz; i++)
    {
        th[i].join();
    }
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
