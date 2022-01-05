#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

#define FNAME "sgb-words.txt"

std::string get_word() {
  srand(time(NULL));
  const int lines = 5757;
  int line_to_get = rand() % lines;
  std::ifstream file(FNAME);
  std::string line;
  while(--line_to_get) {
    getline(file, line);
  }
  return line;
}

bool check_success(const std::string word, const std::string guess) {
  return word == guess;
}

void print_guess(const std::string word, const std::string guess) {
  std::string copy(word);
  for(unsigned int i=0; i < guess.size(); ++i) {
    if(guess[i] == word[i]) {
      std::cout << GREEN << word[i] << RESET;
      copy[i] = ' ';
      continue;
    }
    bool isFound=false;
    for(unsigned int j=0; j < copy.size(); ++j) {
      if(guess[i] == copy[j] &&  guess[j] != copy[j]) {
        std::cout << YELLOW << guess[i] << RESET;
        copy[j] = ' ';
        isFound=true;
        break;
      }
    }
    if(!isFound)
      std::cout << RESET << guess[i];
  }
  std::cout << '\n';
}

int main() {
  const std::string word = get_word();
  std::string guess;

  int tries = 6;
  while(tries--) { 
    std::cin >> guess;
    while(guess.length() != 5) {
      std::cout << RED << "Error Word must be exactly 5 letters. Your guess contained " << guess.length() 
        << RESET << " You have " << GREEN << tries+1 << RESET << " tries remaining\n";
      std::cin >> guess;
    }
    if(check_success(word, guess)) {
      std::cout << "Congratulations! You win! The word was " << GREEN << word << RESET << '\n';
      return 0;
    }

    print_guess(word, guess);
  }
  std::cout << "I'm sorry, you lose. The word was " << RED << word << RESET << '\n';
  return 0;
}
