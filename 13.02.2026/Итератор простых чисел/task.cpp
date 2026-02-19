#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class PrimeIterator {
private:
    vector<int> primes;
    void sieve(int limit) {
        if (limit < 2) return;
        vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int p = 2; p * p <= limit; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= limit; i += p)
                    is_prime[i] = false;
            }
        }

        for (int p = 2; p <= limit; p++) {
            if (is_prime[p]) primes.push_back(p);
        }
    }

public:
    PrimeIterator(int limit) {
        sieve(limit);
    }
    class Iterator {
    private:
        const int* ptr;
    public:
        using iterator_category = forward_iterator_tag;
        using value_type = int;
        using difference_type = ptrdiff_t;
        using pointer = const int*;
        using reference = const int&;

        Iterator(pointer p) : ptr(p) {}
        reference operator*() const { return *ptr; }
        Iterator& operator++() {
            ptr++;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() { return Iterator(&primes[0]); }
    Iterator end() { return Iterator(&primes[0] + primes.size()); }
};

int main() {
    cout << "Простые числа до 20: ";
    PrimeIterator primes(20);
    for (int p : primes) {
        cout << p << " ";
    }
    cout << endl;

    cout << "Простые числа до 100: ";
    PrimeIterator largePrimes(100);
    for (int p : largePrimes) {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}
