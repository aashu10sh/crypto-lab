#include <iostream>
#include <string>
#include <cctype>

std::string prepare_text(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            result.push_back(tolower(c));
        }
    }
    return result;
}

std::string vigenere_encrypt(const std::string& plaintext, const std::string& key) {
    std::string sanitizedText = prepare_text(plaintext);
    std::string sanitizedKey = prepare_text(key);
    
    if (sanitizedKey.empty()) {
        std::cerr << "error: uncool key:p\n";
        return "";
    }
    
    std::string ciphertext;
    size_t keyLength = sanitizedKey.length();
    
    for (size_t i = 0; i < sanitizedText.length(); ++i) {
        char plainChar = sanitizedText[i];
        char keyChar = sanitizedKey[i % keyLength];
        

        int plainValue = plainChar - 'a';
        int keyValue = keyChar - 'a';        

        int encryptedValue = (plainValue + keyValue) % 26;
        
        char encryptedChar = encryptedValue + 'a';
        
        ciphertext.push_back(encryptedChar);
    }
    
    return ciphertext;
}


void display_formatted(const std::string& text, const std::string& label) {
    std::cout << label << ": ";
    
    for (size_t i = 0; i < text.length(); ++i) {
        std::cout << text[i];
    }
    std::cout << std::endl;
}

int main() {
    std::string plaintext, key;
    
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);
    
    std::cout << "Enter key: ";
    std::getline(std::cin, key);
    
    if (key.empty()) {
        std::cerr << "Error: Key cannot be empty.\n";
        return 1;
    }
    
    std::string sanitizedPlaintext = prepare_text(plaintext);
    std::string sanitizedKey = prepare_text(key);
    
    std::cout << "\nSanitized plaintext: " << sanitizedPlaintext << std::endl;
    std::cout << "Sanitized key: " << sanitizedKey << std::endl;
    
    std::string ciphertext = vigenere_encrypt(plaintext, key);
    
    std::cout << "\n--- ENCRYPTION ---\n";
    display_formatted(ciphertext, "Ciphertext");
    
    return 0;
}