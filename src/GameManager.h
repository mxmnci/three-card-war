/**
 * @file GameManager.h
 * @author Max Monciardini
 * @brief This class is responsible for managing the functionality of the Three
 * Card War game
 * @version 0.1
 * @date 2021-11-08
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Deck.h"
#include "Player.h"

class GameManager {
public:
  GameManager();
  virtual ~GameManager();

  /**
   * @brief This method will start the game. In doing so, it will create a
   * shuffled deck of cards and create two players. It will then fill each of
   * the player's empty hands with three cards each. Lastly, it will call the
   * "drawCard" method to begin the game loop
   *
   */
  void start();

private:
  Player roundWinner;
  Player player1;
  Player player2;
  Deck deck;

  /**
   * @brief This method will prompt each player to draw a card from their three
   * cards. Unless it is the first round (in which player 1 goes first), the
   * player that won the previous round goes first. Their card choices will then
   * be compared using the overloaded comparison operators provided by the Card
   * class. If both of the cards are ranked the same, that round is a push and
   * both players cards are sent back to their hand. If one player's card is
   * greater, then they are declared the round winner and receive both of the
   * cards and must place them into their aside pile. Finally, the
   * "onRoundEnd()" method will be called to begin prepartions for the next
   * round.
   *
   */
  void playRound();

  /**
   * @brief Once the round is complete, we first must check if the game is over
   * using the "isGameOver()" method. If so, then we will call the "onGameEnd()"
   * method. If not, each player must draw another card from the deck and then
   * the "playRound()" method is called to begin the next round.
   *
   */
  void onRoundEnd();

  /**
   * @brief Once we have determined that the game is complete this method is
   * called. It will query each player to determine which player has the most
   * cards set aside. The player with the most cards set aside is declared the
   * winner.
   *
   */
  void onGameOver();

  /**
   * @brief This method will be called at the end of each round and will
   * determine whether or not the game has ended by checking the remaining cards
   * in the deck. If the game has ended declare a winner. If not, continue the
   * game loop.
   *
   * @return true
   * @return false
   */
  bool isGameOver();
};

#endif