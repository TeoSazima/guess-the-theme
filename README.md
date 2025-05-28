# Guess the Theme

### 🎮 Console Word-Guessing Game in C++ with SQLite

---

## 📝 Description

**Guess the Theme** is a Czech-language console game written in C++.  
The goal is to identify 5 words related to a hidden theme out of a list of 10 shuffled words.  
Five words are thematically related, and five are randomly selected unrelated words.

The player has **three lives** and must avoid selecting unrelated words.

---

## 🕹️ Rules

- At the beginning of the game, 10 shuffled words are displayed.
- 5 of them are related to a hidden theme (e.g. "Big Cats").
- 5 others are completely unrelated.
- The player selects words by entering a number (1–10).
- If the selected word is related, it is revealed in green.
- If unrelated, it is crossed out and the player loses one life.
- The player **wins** by identifying all 5 related words.
- The player **loses** after 3 incorrect guesses.

---

## ⚙️ Installation and Running

1. Clone the repository or download the files `main.cpp` and `guess-the-theme.db`.
2. Open a terminal and compile the project:
   ```sh
   g++ -o guess-theme main.cpp -lsqlite3
