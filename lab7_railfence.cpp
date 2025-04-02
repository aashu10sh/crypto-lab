#include <iostream>
#include <string>
#include <vector>

std::string railfence_encrypt(const std::string& text, int rails) {
    if (rails <= 1) return text;
    if (text.empty()) return "";
    
    std::vector<std::vector<char>> fence(rails, std::vector<char>(text.length(), ' '));
    
    int row = 0;
    bool dirDown = true;
    
    for (size_t i = 0; i < text.length(); i++) {
        fence[row][i] = text[i];
        
        if (row == 0) {
            dirDown = true;
        } else if (row == rails - 1) {
            dirDown = false;
        }
        
        if (dirDown) {
            row++;
        } else {
            row--;
        }
    }
    
    std::string result;
    for (int i = 0; i < rails; i++) {
        for (size_t j = 0; j < text.length(); j++) {
            if (fence[i][j] != ' ') {
                result += fence[i][j];
            }
        }
    }
    
    return result;
}

void display_rail_pattern(const std::string& text, int rails) {
    std::vector<std::vector<char>> fence(rails, std::vector<char>(text.length(), '.'));
    
    int row = 0;
    bool dirDown = true;
    
    for (size_t i = 0; i < text.length(); i++) {
        fence[row][i] = text[i];
        
        if (row == 0) {
            dirDown = true;
        } else if (row == rails - 1) {
            dirDown = false;
        }
        
        if (dirDown) {
            row++;
        } else {
            row--;
        }
    }
    
    std::cout << "\nRail Pattern:\n";
    for (int i = 0; i < rails; i++) {
        for (size_t j = 0; j < text.length(); j++) {
            std::cout << fence[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::string plaintext;
    int rails = 2;
    
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);
    
    
    std::string textNoSpaces;
    for (char c : plaintext) {
        if (c != ' ') {
            textNoSpaces += c;
        }
    }
    
    display_rail_pattern(textNoSpaces, rails);
    
    std::string ciphertext = railfence_encrypt(textNoSpaces, rails);
    std::cout << "Encrypted text: " << ciphertext << std::endl;
    
    
    return 0;
}