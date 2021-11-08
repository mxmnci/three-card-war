/**
 * @file Card.h
 * @author Max Monciardini
 * @brief This class is resposible for the functionality of the Card
 * @version 0.1
 * @date 2021-11-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

using namespace std;

extern const std::string validCardSymbols[13] = {
    "2", "3",  "4",    "5",     "6",    "7",  "8",
    "9", "10", "Jack", "Queen", "King", "Ace"};

extern const std::string validCardSuits[4] = {"Hearts", "Diamonds", "Clubs",
                                              "Spades"};

class Card {
public:
  /**
   * @brief Construct a new Card object
   *
   * @param cardSuit
   * @param cardSymbol
   */
  Card(string cardSuit, string cardSymbol);

  /**
   * @brief Destroy the Card object
   *
   */
  virtual ~Card();

  /**
   * @brief This method will convert the card object to a logical string. For
   * example, if the card had a symbol of "Queen" and a suit of "Hearts" we
   * would call it a "Queen of Hearts"
   *
   * @return string
   */
  string toString();

  // NOTE - Comparison operators
  // When a card is compared, each of the comparison operators below will use
  // the symbol's index in the "validCardSymbols" array to determine the card's
  // rank. Example: An "Ace" card has the highest rank because it has the
  // highest index value in the "validCardSymbols" array.

  /**
   * @brief Check the equality of two card objects.
   *
   * @param card
   * @return true
   * @return false
   */
  bool operator==(const Card card);

  /**
   * @brief Check whether a card has a lesser rank than another card
   *
   * @param card
   * @return true
   * @return false
   */
  bool operator<(const Card card);

  /**
   * @brief Check whether a card has a greater rank than another card
   *
   * @param card
   * @return true
   * @return false
   */
  bool operator>(const Card card);

private:
  std::string cardSymbol;
  std::string cardSuit;
};

#endif