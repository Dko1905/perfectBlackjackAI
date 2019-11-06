#include <iostream>
#include <array>
#include <cmath>

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

float getAvg(){
  float all, cards;
  all = currentDeck[0]*1;
  all += currentDeck[0]*11;
  cards = currentDeck[0]*2;
  for(int n = 2; n < 12; n++){
    all += currentDeck[n]*n;
    cards += currentDeck[n];
  }
  return all/cards;
}

void ai(int remaining = 21){
  int card;
  float avg, sureness;
  std::cout << "What card did you get?\n";
  std::cin >> card;
  removeCard(card);
  avg = getAvg();

  if(avg > remaining){
    std::cout << "Don't take a card!\n";
  }
  else{
    std::cout << "Take a card! "<< card+remaining << " + "<< avg <<" \n";
    ai(remaining-card);
  }
}

void startup(int people){ // The start of a poker game has special rules.
  int card;
  std::cout << "Specify card for each player, not you.\n";
  for(int n = 0; n < people-1; n++){ // for each player
    std::cin >> card;
    removeCard(card);
    std::cin >> card;
    removeCard(card);
  }
  std::cout << "Done startup.\n";
}

void userInterface1(){
  int people = 0;

  std::cout << "How many decks?\n";
  std::cin >> decks;
  std::cout << "How many people?\n";
  std::cin >> people;
  generateDecks();
  startup(people);
  ai();
}

int main() 
{
  userInterface1();
  return 0;
}