#include <iostream>
#include <unordered_map>
#include<string>

#define MAX 300

struct Message {
  std::string message;
};

int main(void) {

  std::unordered_map<char, char> map = {
      {'a', 'm'}, {'b', 'o'}, {'c', 'q'}, {'d', 's'}, {'e', 'z'}, {'f', 'x'},
      {'g', 'h'}, {'h', 'k'}, {'i', 'l'}, {'j', 'p'}, {'k', 'n'}, {'l', 'u'},
      {'m', 'v'}, {'n', 'y'}, {'o', 'w'}, {'p', 'r'}, {'q', 't'}, {'r', 'a'},
      {'s', 'j'}, {'t', 'g'}, {'u', 'd'}, {'v', 'i'}, {'w', 'e'}, {'x', 'f'},
      {'y', 'c'}, {'z', 'b'}, {' ',' '}};

  struct Message input = Message{};

  std::printf("enter your message: ");

  std::getline(std::cin, input.message);

  std::string encrypted;

  std::cout << "message: " << input.message << std::endl;

  for (const char character : input.message) {
    if (map.find(character) != map.end()) {
      const char new_key = map[character];
      encrypted += new_key;
    } else {
      std::printf(
          "error: key not in map, please use only lowercase characters\n");
      return -1;
    }
  }

  std::cout << "encrypted: " << encrypted << std::endl;

  return 0;
}