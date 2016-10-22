//Find all prime #s using Sieve of Eratosthenes method.
#include <iostream>
#include <vector>


int main() {
    std::vector<int> prime = {};
    int limit;
    double k;

    std::cout << "Please enter the upper limit to search for primes: ";
    std::cin >> limit;

    //fill in vector up to upper limit as entered by user starting with '2' which is the first prime #.
    for (int i = 2; i <= limit ; ++i) {
        prime.push_back(i);
    }

    //step over vector identifying vector members that are multiple of primes
    for (int i = 2; i <= prime.size(); ++i) {  //starts with 2 as it is the first prime
        for (int j = 0; j <= prime.size(); j++) {  //loops over every vector member, starting with member zero
            k = prime[j] % i;  //calculates reminder of vector[j] by prime i
            if (k == 0 && prime[j] != i) {  //reminder will be zero if vector is multiple of i
                prime.erase(prime.begin() + j);  //removes vector member
                if (j != prime.size()) {  //unless we are at end of vector, counter needs to be reduced as vector was reduced
                    j -= 1;
                }
            }
        }
    }

    //print out prime #s left in vector
    for (int x: prime)
        std::cout << x << std::endl;

    return 0;
}