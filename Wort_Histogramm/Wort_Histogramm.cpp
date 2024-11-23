#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main() {
    std::map<std::string, int> wordCount;
    std::string word;
    std::string mostCommonWord;
    int maxCount = 0;

    // Wörter einlesen, bis "STOP" eingegeben wird
    while (std::cin >> word && word != "STOP") {
        wordCount[word]++;
        if (wordCount[word] > maxCount) {
            maxCount = wordCount[word];
            mostCommonWord = word;
        }
    }

    // Alle Wörter und ihre Häufigkeit ausgeben
    for (const auto& pair : wordCount) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // Das häufigste Wort ausgeben
    std::cout << "Most common word: " << mostCommonWord << std::endl;

    return 0;
}
