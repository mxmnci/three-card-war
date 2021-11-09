## The Card Class

To start this project, I began breaking up the Three Card War game into its most basic pieces. Obviously, you can't have a card game without cards, so I think this is a great starting point!

### Creating a Card - The constructor and setting boundaries

When creating a card object, we want the user of the object to only be able to create cards that have a valid card symbol {"2",  "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"} and a valid card suit {"Hearts", "Diamonds", "Clubs", "Spades"}. Therefore, I began my Card class by defining two external constants for our cards to abide by. So, when a deck of cards is generated, we can iterate through both of these lists and create 52 unique cards. 

### Ranking a card - Overloading operators

To handle the ranking of cards, I decided to overload the "==" operator and the "<" and ">". This way, when we are trying to determine which player wins a round we can compare the two cards using these operators. 

But how will it work? By using the "valid card symbol" array that I created above, we can compare the two cards simply by comparing the index of the cards' symbols of the array. 

### Printing a card - Converting a card to a logical string

Lastly, I wrote a toString method that we can use to convert a Card object to a logical string. When people pronounce the symbol/suit of a card they usually say "{symbol} of {suit}".

## The Deck Class

Now that we have our card object created, the next step in the hierarchy of abstraction is the Deck. Luckily the Deck class is pretty simple as it merely acts as a holding place for the cards. 

### Creating a Deck - Generating a deck of cards and shuffling them

When a Deck is initialized it's constructor will call two methods to prepare the cards. Before the Deck is created, we must recall the two constant arrays of symbols and suits that I exported from the Card class. After importing them, we can then loop through them in the "generateDeckOfCards" method and generate 52 unique cards. Then, the constructor will also run the "shuffle" method which will randomize the order of the deck vector. 

### Drawing a card - Removing a card from the Deck and returning a Card object

The last method that I wrote for the Deck class is the "drawCard" method. It allows the user of the Deck object to remove a Card from the top of the deck and returns that Card. 

## The Player Class

We're almost done! Now that we have a Deck of cards the next level of abstraction is the Player. The Player will be able to hold cards in their hand as put a card into play (remove a card from their hand) and pick a card from the Deck (add a card to their hand). 

### Picking a card - Adding a card to a players hand

The first method that I added to the player class (pickCardFromDeck) was the ability to pick a card. It is a simple method that replaces an empty spot in the player's hand with a card. Luckily, the removal of the card from the card from the Deck will be handled by the Deck class. 

### Playing a card - Removing a card from a player's inventory and putting it into play!

The next method that I added to the player class (playCard) is used when a player's card is put into play. When a card is put into play it is removed from a player's hand and then handled by the GameManager (this will make more sense after reading below). You can think of the GameManager as being the card table which is a temporary card storage.

### Winning a round - If a player wins a round, their cards must be put aside

If a player wins a round, the "onWinRound" method will be called and they will then receive both of the cards on the table to be put into their inventory. I called this pile a player's "aside" pile and it is where a player's winning cards are stored. 

### Additional Functionality - Supplementing the GameManager

Lastly, I added a few functions that are necessary for the GameManager to keep track of a player's. 

- I added an "isHandEmpty" method that is used in conjunction with Deck's "isEmpty" method to determine when the game is over.
- I added an "amountOfCardsPlacedAside" method which is used by the game manager to determine which player has more cards placed aside at the end of the game. The player with the most cards placed aside wins!
- Lastly, to simplify the management of determining which player goes first I added a comparison operator that is used by the GameManager class to determine which player goes first (for more detail see below).

## The GameManager Class - Tying everything together!

Last but not least is the GameManager! This is where I tied each of the steps of the game together in a procedural manner. Of course, we could handle all of our game logic inside of the main.cpp but I think it will be much more clean to handle our game loop inside of an object. Once we're finished with this class, starting the game will be as simple as importing the GameManager into your main.cpp and executing the .start() method!

### Starting the game - Initializing the Deck/Players, passing out cards, and starting the game loop

The "start" method begins the game by doing a few things. It first creates a deck of cards and two player objects. It will then fill each of the player's hands with three cards each. Lastly, it will call the "playRound" method to begin the game loop.

### Play Round Method - Determining which player goes first and playing a card

The "playRound" method will begin by prompting each player to draw a card from their three cards. Unless it is the first round (in which player 1 goes first), the player than won the previous round goes first. Their card choices will then be compared using the overloaded comparison operators provided by the Card class. If both of the cards are ranked the same, that round is a push and both players cards are sent back to their hand. If one player's card is greater, then they are declared the round winner and receive both of the cards and must place them into their aside pile. Finally, the"onRoundEnd" method will be called to begin preparations for the next round.

### On Round End - Has the game ended yet? If not, let's keep playing!

At the end of each round, the "onRoundEnd" method is called which checks to see if the game is supposed to be over. It does this by calling the "isGameOver" method which checks to see if both the deck and player's hands are empty. If so, then it will call the "onGameOver" method which will declare a winner depending on which player has the most cards set aside. If not, then it will execute the "playRound" method again to continue the game loop.
