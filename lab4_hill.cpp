#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <numeric>

int charToInt(char c) {
    return tolower(c) - 'a';
}

char intToChar(int n) {
    n = (n % 26 + 26) % 26;
    return static_cast<char>(n + 'a');
}

// TODO(aashutosh): calculate determinant of a 2x2 matrix
int determinant(const std::vector<std::vector<int>>& matrix) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

int modInverse(int a, int m) {
    a = (a % m + m) % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}


bool isValidKey(const std::vector<std::vector<int>>& matrix) {
    int det = determinant(matrix);
    det = (det % 26 + 26) % 26;
    

    if (det == 0) return false;
    
    int gcd = std::gcd(det, 26);
    return gcd == 1;
}

std::vector<std::vector<int>> inverseMatrix(const std::vector<std::vector<int>>& matrix) {
    int det = determinant(matrix);
    det = (det % 26 + 26) % 26;
    
    int detInv = modInverse(det, 26);
    
    std::vector<std::vector<int>> inverse = {
        {(matrix[1][1] * detInv) % 26, (-matrix[0][1] * detInv) % 26},
        {(-matrix[1][0] * detInv) % 26, (matrix[0][0] * detInv) % 26}
    };
    
    for (auto& row : inverse) {
        for (auto& val : row) {
            val = (val % 26 + 26) % 26;
        }
    }
    
    return inverse;
}

std::string prepareText(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            result.push_back(tolower(c));
        }
    }
    
    if (result.length() % 2 != 0) {
        result.push_back('x');
    }
    
    return result;
}

std::string hillEncrypt(const std::string& plaintext, const std::vector<std::vector<int>>& keyMatrix) {
    std::string prepared = prepareText(plaintext);
    std::string ciphertext;
    
    for (size_t i = 0; i < prepared.length(); i += 2) {
        int p1 = charToInt(prepared[i]);
        int p2 = charToInt(prepared[i + 1]);
        
        int c1 = (keyMatrix[0][0] * p1 + keyMatrix[0][1] * p2) % 26;
        int c2 = (keyMatrix[1][0] * p1 + keyMatrix[1][1] * p2) % 26;
        
        ciphertext.push_back(intToChar(c1));
        ciphertext.push_back(intToChar(c2));
    }
    
    return ciphertext;
}

int main() {
    std::vector<std::vector<int>> keyMatrix = {
        {5, 8},
        {17, 3}
    };
    
    if (!isValidKey(keyMatrix)) {
        std::cerr << "Error: Invalid key matrix. The determinant must be coprime with 26.\n";
        return 1;
    }
    
    std::cout << "Using key matrix:\n";
    std::cout << keyMatrix[0][0] << " " << keyMatrix[0][1] << "\n";
    std::cout << keyMatrix[1][0] << " " << keyMatrix[1][1] << "\n\n";
    
    std::string plaintext;
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);
    
    // Encrypt
    std::string ciphertext = hillEncrypt(plaintext, keyMatrix);
    std::cout << "Encrypted text: " << ciphertext << std::endl;
    
    
    return 0;
}