#include <iostream>
#include <cmath>

using namespace std;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long p = 23;  // Prime number
    long long g = 5;   // Primitive root mod p

    long long a = 6;  // Alice's private key
    long long b = 15; // Bob's private key

    long long A = mod_exp(g, a, p); // Alice's public key
    long long B = mod_exp(g, b, p); // Bob's public key

    long long shared_secret_A = mod_exp(B, a, p); // Alice computes shared key
    long long shared_secret_B = mod_exp(A, b, p); // Bob computes shared key

    cout << "Prime (p): " << p << ", Generator (g): " << g << endl;
    cout << "Alice's Private Key: " << a << ", Public Key: " << A << endl;
    cout << "Bob's Private Key: " << b << ", Public Key: " << B << endl;
    cout << "Shared Secret (Alice): " << shared_secret_A << endl;
    cout << "Shared Secret (Bob): " << shared_secret_B << endl;

    if (shared_secret_A == shared_secret_B)
        cout << "Key Exchange Successful! Shared Key: " << shared_secret_A << endl;
    else
        cout << "Error in Key Exchange!" << endl;

    return 0;
}
