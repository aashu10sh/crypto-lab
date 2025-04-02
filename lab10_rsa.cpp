#include <iostream>
#include <cmath>

using namespace std;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) // If exponent is odd
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mod_inverse(long long e, long long phi) {
    long long t = 0, new_t = 1;
    long long r = phi, new_r = e;
    
    while (new_r != 0) {
        long long quotient = r / new_r;
        t = new_t;
        new_t = t - quotient * new_t;
        r = new_r;
        new_r = r - quotient * new_r;
    }
    
    if (t < 0)
        t += phi;
    
    return t;
}

int main() {
    long long p = 61, q = 53;
    long long n = p * q; 
    long long phi = (p - 1) * (q - 1); 
    
    long long e = 17;
    while (gcd(e, phi) != 1) {
        e++; 
    }
    
    long long d = mod_inverse(e, phi);
    
    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;
    
    long long message = 65; 
    long long encrypted = mod_exp(message, e, n);
    cout << "Encrypted Message: " << encrypted << endl;
    
    long long decrypted = mod_exp(encrypted, d, n);
    cout << "Decrypted Message: " << decrypted << endl;
    
    return 0;
}