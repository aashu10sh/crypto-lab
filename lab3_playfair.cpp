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

int main() {
    struct Message input = Message{};

    std::printf("plaintext: ");

    std::cin >> input.message;

    std::vector<char> matrix;

    if (input.message.length() > chars.size()) {
        std::printf("message cannot be that long");
        return EXIT_FAILURE;
    }

    for (const char character : input.message) {

        if (!matrix.empty() && character == matrix.back()) {
            continue;
        }

        matrix.push_back(character);
    }

    for (const char char_ : chars) {

        if (has(matrix, char_)) {
            continue;
        }

        matrix.push_back(char_);
    }

    std::cout << "your matrix is : " << std::endl;

    int iteration = 0;

    for (const char c : matrix) {

        if (iteration % 5 == 0) {
            std::printf("\n");
        }

        std::printf("%c ", c);
        iteration++;
    }
    

    std::printf("\n");
}
