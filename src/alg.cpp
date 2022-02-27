// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "math.h"


bool checkPrime(uint64_t value) {
    if ((value % 2 == 0 && value != 2) || value == 1) {
        return false;
    } else {
        float limit = pow(value, 0.5);
        for (uint32_t i = 3; i <= limit; i += 2) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }
    uint64_t prime = 3;
    for (uint64_t counter = 2; counter < n; counter++) {
        prime = nextPrime(prime);
    }
    return prime;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t prime = value;
    do {
        prime += 1;
    } while (!checkPrime(prime));
    return prime;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t current = 2; current < hbound; current = nextPrime(current)) {
        sum += current;
    }
    return sum;
}
