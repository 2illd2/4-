#include <iostream>
#include <string>
#include <algorithm>
#include <random>



std::string reverse(const std::string& word) {
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}

std::string removeVowels(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (std::tolower(c) != 'a' && std::tolower(c) != 'e' && std::tolower(c) != 'i' && std::tolower(c) != 'o' && std::tolower(c) != 'u') {
            result += c;
        }
    }
    return result;
}

std::string removeConsonants(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (std::isalpha(c) && !(std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' || std::tolower(c) == 'o' || std::tolower(c) == 'u')) {
            result += c;
        }
    }
    return result;
}

std::string shuffle(const std::string& word) {
    std::string shuffledWord = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledWord.begin(), shuffledWord.end(), g);
    return shuffledWord;
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::string word;
    int choice;

    std::cout << "введите слово: ";
    std::cin >> word;

    std::cout << "выберите действие:" << std::endl;
    std::cout << "1. слово выводится задом наперед." << std::endl;
    std::cout << "2. вывести слово без гласных." << std::endl;
    std::cout << "3. вывести слово без согласных." << std::endl;
    std::cout << "4. рандомно раскидывать буквы заданного слова." << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "результат: " << reverse(word) << std::endl;
        break;
    case 2:
        std::cout << "результат: " << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "результат: " << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::cout << "результат: " << shuffle(word) << std::endl;
        break;
    default:
        std::cout << "некорректный выбор." << std::endl;
    }

    return 0;
}