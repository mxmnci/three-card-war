/**
 * @file Player.h
 * @author Max Monciardini
 * @brief This class is responsible for the functionality of the Player
 * @version 0.1
 * @date 2021-11-08
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"
#include <vector>

using namespace std;

class Player {
public:
  /**
   * @brief Construct a new Player object and give them a name
   *
   */
  Player(std::string name);
  /**
   * @brief Destroy the Player object
   *
   */
  virtual ~Player();

  /**
   * @brief If there is an empty space in their hand, add a card to the player's
   * hand.
   *
   * @param card
   */
  void pickCardFromDeck(Card card);

  /**
   * @brief If a player wins a round they will receive two cards. These two
   * cards will be placed into a player's aside pile
   *
   */
  void onWinRound(Card card1, Card card2);

  /**
   * @brief Allow the player to put a card into play. This will remove the card
   * from the player's hand and return it for use by the GameManager. The
   * GameManager will then keep track of the owner of the card.
   *
   * @return Card
   */
  Card playCard();

  /**
   * @brief This method checks whether or not a player's hand is empty. This is
   * used to determine when the game is completed.
   *
   * @return true
   * @return false
   */
  bool isHandEmpty();

  /**
   * @brief This method calculates the total amount of cards that are placed
   * inside of a player's aside pile. This count will be used to determine who
   * wins the game once the deck runs out of cards.
   *
   * @return int
   */
  int amountOfCardsPlacedAside();

  /**
   * @brief Compare two players using their name. This is used by the Game
   * Manager when handling the round winner.
   *
   * @param player
   * @return true
   * @return false
   */
  bool operator==(const Player player);

private:
  int uniqueIdentifier;
  Card hand[3];
  vector<Card> aside;
};

#endif