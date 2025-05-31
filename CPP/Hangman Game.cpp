#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void printWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool checkGuess(char guess, const string& word, vector<bool>& guessed) {
    bool correct = false;
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            guessed[i] = true;
            correct = true;
        }
    }
    return correct;
}

int main() {
    vector<string> words = {"hangman", "programming", "computer", "algorithm", "compiler"};
    
    srand(time(nullptr));
    
    string chosenWord = words[rand() % words.size()];
    
    vector<bool> guessed(chosenWord.length(), false);
    
    int attempts = 7;
    
    cout << "Welcome to Hangman!" << endl;
    
    while (attempts > 0) {
        cout << "Attempts left: " << attempts << endl;
        printWord(chosenWord, guessed);
        
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        
        if (checkGuess(guess, chosenWord, guessed)) {
            cout << "Correct guess!" << endl;
        } else {
            cout << "Incorrect guess!" << endl;
            --attempts;
        }
        
        bool allGuessed = true;
        for (bool letterGuessed : guessed) {
            if (!letterGuessed) {
                allGuessed = false;
                break;
            }
        }
        if (allGuessed) {
            cout << "Congratulations! You guessed the word: " << chosenWord << endl;
            break;
        }
    }
    
    if (attempts == 0) {
        cout << "You ran out of attempts! The word was: " << chosenWord << endl;
    }
    
    return 0;
}