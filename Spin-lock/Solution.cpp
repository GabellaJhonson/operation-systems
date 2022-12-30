#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
using namespace std;

class Spinlock {
private:
	atomic<bool> lock;
public:
	Spinlock() : lock(false) {}

	void Lock() {
		while (lock.exchange(true));
	}

	void Unlock() {
		lock.store(false);
	}
};
