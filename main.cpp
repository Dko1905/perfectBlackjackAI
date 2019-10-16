#include <iostream>
#include <array>

int decks = 1;
std::array<int, 12> currentDeck;

void generateDecks(){
  currentDeck = {
    4*decks, // ace
    0, // 1 is not existing
    4*decks, // 2 -
    4*decks,
    4*decks,
    4*decks,
    4*decks,
    4*decks,
    4*decks,
    4*decks,
    4*decks, // - 10
    12*decks
  };
}

void removeCard(int card){
  currentDeck[card] = currentDeck[card]-1;
}

void ai(){

}

void startup(int people){ // The start of a poker game has special rules.
  int card;
  std::cout << "Specify card for each player.";
  for(int n = 1; n < people; n++){
    std::cin >> card;
    removeCard(card);
  }
}

void userInterface1(){
  int people = 0;

  std::cout << "How many decks?\n";
  std::cin >> decks;
  std::cout << "How many people?\n";
  std::cin >> people;
  generateDecks();

}

int main() 
{
  userInterface1();
  return 0;
}