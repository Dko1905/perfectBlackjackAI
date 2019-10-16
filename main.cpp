#include <iostream>
#include <array>

int decks;
std::array<int, 12> deck;
int currentDeck[12];

void multiplyArr(int* arr, int num){

}

void generateDecks(){
  deck = {
    4, // ace
    0, // 1 is not existing
    4, // 2 -
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4, // - 10
    12
  };
}

void userInterface1(){
  std::cout << "How many decks?\n";
  std::cin >> decks;

}

int main() 
{
  std::cout << "Hello, World!";
  return 0;
}