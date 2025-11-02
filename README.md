# Overview

I programmed a Hangman game to test my ability to work through the logic and problem solving of game creation. 
Using the C++ language, I was able to test my knowledge of loops, vectors and randomization. 

This program is a Hangman style game in which the user will see displayed an empty gallows with several blank 
dashes beneath it. The user will be prompted to guess a letter of the alphabet. If the user guesses correctly,
their letter will replace all the dashes in the word where they belong. If the letter they guess is wrong, 
it will be added to a list of wrong letters and a piece of a body will be added to the gallows. If the user guesses
the word correctly, they win. If they do not guess within 6 turns, they will see the whole body on the gallows and
be prompted to try again.

I wrote this software to gain greater understanding of the C++ language and practice using it in real time. I wanted to use it to build a game because C++ is commonly used in game creation and I wanted to explore my desire to create games. 

[Hangman Demonstration](https://www.youtube.com/watch?v=qUQle1kzhcw)

# Development Environment

To develop this software, I used the C++ language in Visual Studio Code as well as GitHub to publish my work. 

C++ has several libraries that I used to create this program, including iostream and ifstream to handle my input and output features, vector to allow the use of vectors, and random and algorithm to use in my calculations of the program to create the game logic.

# Useful Websites

- [W3 Schools](https://www.w3schools.com/cpp/default.asp)
- [Programiz](https://www.programiz.com/cpp-programming/do-while-loop)

# Future Work

- Add a draw class to draw the program in a separate window where it will update dynamically.
- Add a box in the upper right hand corner containing the wrong letters guessed by the user.
- Update my program so it is separated into classes for better encapsulation and inheritance.
