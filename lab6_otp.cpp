#include<iostream>
#include<string>
#include<vector>
#include<ctime>


std::vector<int> generate_random_string(const int &length ){
    std::vector<int> random;
    std::srand(std::time(nullptr));

    for (int i = 0; i < length; i++){
        const int rand = std::rand() % 255;
        random.push_back(rand);
    }

    return random;
}

template <typename T> void printVector(const std::vector<T> &vec) {
    for (const T &element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


int main(void){
    std::string user_input;
    std::cout << "message: ";
    std::getline(std::cin, user_input);

    std::vector<int> plain_text = std::vector<int>(user_input.begin(), user_input.end());
    std::vector<int> random_bytes = generate_random_string(plain_text.size());

    std::cout << "user input: ";
    printVector(plain_text);

    std::cout << "random key: ";
    printVector(random_bytes);

    std::vector<int> cipher_text;

    for ( int i = 0; i<plain_text.size(); i++){
        const int xored = plain_text[i] ^ random_bytes[i] % 255;
        cipher_text.push_back(xored);
    }

    std::cout << "encrypted: ";
    printVector(cipher_text);

    return 0;

}