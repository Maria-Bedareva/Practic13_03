#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Russian");
    std::string filename = "C:/Users/User/Desktop/practic.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Файл не открывается. Ошибка!" << std::endl;
        return 1;
    }
    std::string line;
    std::unordered_map<std::string, int> word_sum;
    auto count = [&](const std::string& line) {
        std::string word;
        std::istringstream iss(line);
        while (iss >> word) {
            word_sum[word]++;
        }
        };

    for (int i = 0; std::getline(file, line); ++i) {
        count(line);
    }

    std::vector<std::pair<std::string, int>> sorted_words(word_sum.begin(), word_sum.end());
    std::sort(sorted_words.begin(), sorted_words.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
        });

    for (const auto& pair : sorted_words) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}