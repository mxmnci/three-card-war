/**
 * @file Deck.h
 * @author Max Monciardini
 * @brief This class is responsible for the functionality of the Deck
 * @version 0.1
 * @date 2021-11-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include <vector>

using namespace std;

class Deck {
public:
  /**
   * @brief Construct a new Deck object
   *
   */
  Deck();
  /**
   * @brief Destroy the Deck object
   *
   */
  virtual ~Deck();

  /**
   * @brief Allow the players to draw a card when needed. When doing so, a card
   * will be removed from the deck and placed into the player's hand.
   *
   * @return Card
   */
  Card drawCard();

private:
  vector<Card> deck;

  /**
   * @brief Fill the empty card vector with 52 unique cards. This method will be
   * run when the deck is created. The cards will be generated by looping
   * through the "validCardSuits" and "validCardSymbols" constants that are
   * exported from the card class and appending each unique card to the deck.
   *
   */
  void generateDeckOfCards();

  /**
   * @brief Shuffle the deck of cards into a random order. This method will be
   * run after the deck of cards is generated and will ensure the fairness of
   * the game.
   *
   */
  void shuffle();
};

#endif