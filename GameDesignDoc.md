# Game Design Document

## Part 1

The primary "things" I will have are a user controlled "hero" and five different types of "monsters."

The hero and each type of monster will look different through the use of PixMapItems.

The five types of monsters are as follows:
  *`1.` Bombers: move straight down, land on the ground, shake for a couple seconds, and explode
  *`2.` Rockets: move straight down at a fast pace
  *`3.` Swervers: move in a zig zag as they come down the screen
  *`4.` Flyers: move downwards and sidewards in a randomized stair pattern (if they reach the edge of the screen they reappear on the opposite side)
  *`5.` Bouncers: move straight down and bounce back up one time after hitting the bottom of the screen, then resume moving downwards
  
## Part 2

The game will use the left and right arrows keys to move the player's character from side to side to avoid getting hit by the various monsters coming down the screen.

## Part 3

The score only goes up. It increases by one when a monster is successfully avoided.

## Part 4

The player dies when the "hero" character gets hit by a monster. The player only has one life so once they get hit a single time the game is over.

## Part 5

Game layout mockup:

![Check repo if image doesn't come up](https://github.com/usc-csci102-spring2013/game_dylanres/blob/master/gamelayout.png?raw=true "Game Layout")

