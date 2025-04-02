#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#define MAX 25

template <typename T> void printVector(const std::vector<T> &vec) {
    for (const T &element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

bool has(std::vector<char> vec, char item) {
    for (const char c : vec) {
        if (item == c) {
            return true;
        }
    }
    return false;
}

struct Message {
    std::string message;
};

std::vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                           't', 'u', 'v', 'w', 'x', 'y', 'z'};

std::pair<int, int> findPosition(char ch, char matrix[5][5]) {
    if (ch == 'j')
        ch = 'i';
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; 
}


std::string prepareText(const std::string& text) {
    std::string result;
    
    for (size_t i = 0; i < text.length(); i++) {
        char current = std::tolower(text[i]);
        
        if (!std::isalpha(current))
            continue;
            
        if (current == 'j')
            current = 'i';
            
        result.push_back(current);
        
        if (i + 1 < text.length() && std::tolower(text[i]) == std::tolower(text[i + 1])) {
            result.push_back('x');
        }
    }
    
    if (result.length() % 2 != 0) {
        result.push_back('x');
    }
    
    return result;
}

std::string encrypt(const std::string& preparedText, char matrix[5][5]) {
    std::string cipher;
    
    for (size_t i = 0; i < preparedText.length(); i += 2) {
        char first = preparedText[i];
        char second = preparedText[i + 1];
        
        auto pos1 = findPosition(first, matrix);
        auto pos2 = findPosition(second, matrix);
        
        int row1 = pos1.first;
        int col1 = pos1.second;
        int row2 = pos2.first;
        int col2 = pos2.second;
        
        // Same row
        if (row1 == row2) {
            cipher.push_back(matrix[row1][(col1 + 1) % 5]);
            cipher.push_back(matrix[row2][(col2 + 1) % 5]);
        }
        // Same column
        else if (col1 == col2) {
            cipher.push_back(matrix[(row1 + 1) % 5][col1]);
            cipher.push_back(matrix[(row2 + 1) % 5][col2]);
        }
        // Rectangle case
        else {
            cipher.push_back(matrix[row1][col2]); 
            cipher.push_back(matrix[row2][col1]);
        }
    }
    
    return cipher;
}

int main() {
    struct Message input = Message{};
    std::string keyWord;
    
    std::cout << "Enter key: ";
    std::cin >> keyWord;
    

    for (auto &c : keyWord) {
        c = std::tolower(c);
        if (c == 'j') c = 'i';
    }
    
    std::cout << "Enter plaintext: ";
    std::cin.ignore(); 
    std::getline(std::cin, input.message);
    
    std::vector<char> matrixVector;
    

    for (const char character : keyWord) {
        if (!has(matrixVector, character) && isalpha(character)) {
            matrixVector.push_back(character);
        }
    }
    

    for (const char char_ : chars) {
        if (!has(matrixVector, char_)) {
            matrixVector.push_back(char_);
        }
    }
    
    std::cout << "Your matrix is: " << std::endl;
    

    char matrix[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = matrixVector[i * 5 + j];
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

    std::string preparedText = prepareText(input.message);
    
    std::cout << "\nPrepared text: " << preparedText << std::endl;
    
    std::string encrypted = encrypt(preparedText, matrix);
    std::cout << "Encrypted text: " << encrypted << std::endl;
    
    return 0;
}