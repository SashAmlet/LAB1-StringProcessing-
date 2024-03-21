#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

vector<string> split(const string& input) {
    vector<string> words;
    string word;

    for (char c : input) {
        if (isalpha(c)) {
            word += c;
        }
        else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

bool hasDoubleConsonants(const string& word) {
    char vowels[] = "aeiou";
    for (size_t i = 0; i < word.length() - 1; ++i) {
        if (word[i] == word[i + 1] and find(begin(vowels), end(vowels), tolower(word[i])) == end(vowels)) {
            return true;
        }
    }
    return false;
}

vector<string> findWordsWithDoubleConsonants(const vector<string>& words) {
    
    vector<string> result;
    for (const string& word : words) {
        if (hasDoubleConsonants(word)) {
            result.push_back(word);
        }
    }
    return result;
}


int main() {
    ifstream in("test.txt");
    string line;
    vector<string> words, result;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            vector<string> w = split(line);

            if (!w.empty()) {
                words.insert(words.end(), w.begin(), w.end());
            }
        }
    }
    in.close();

    result = findWordsWithDoubleConsonants(words);

    cout << "Words with double consonants:" << endl;
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}