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


   
---

### Code Structure

- **main()**  
  Main game loop; handles user input, output, and game logic.

- **promichaniPoradi()**  
  Shuffles the order of words and assigns related/unrelated flags.

- **vypsaniPromichanychSlov()**  
  Displays the shuffled word list with colors and formatting indicating guesses.

- **uvodnitext()**  
  Prints the introductory text and game rules.

- **kontrolaKonce()**  
  Checks if all related words have been correctly guessed.

---

### Author

This program was created as a demonstration project for practicing:  
- Console input/output handling in C++  
- Integration with SQLite database  
- Basic game design and logic implementation  

If you have any questions or feedback, feel free to contact me.




# Hádej Téma

### 🎮 Konzolová slovní hra v C++ s SQLite

---

## 📝 Popis

**Hádej Téma** je konzolová hra v češtině napsaná v C++.  
Cílem je uhodnout 5 slov, která souvisejí s ukrytým tématem, z celkových 10 zamíchaných slov.  
Pět slov je tematicky propojených a pět je náhodně vybraných nesouvisejících slov.

Hráč má **tři životy** a musí se vyhnout vybírání nesouvisejících slov.

---

## 🕹️ Pravidla

- Na začátku hry je zobrazena 10 zamíchaných slov.  
- 5 z nich souvisí s ukrytým tématem (např. „Velké kočky“).  
- 5 ostatních jsou zcela nesouvisející.  
- Hráč vybírá slova zadáním čísla (1–10).  
- Pokud je vybrané slovo související, zobrazí se zeleně.  
- Pokud je nesouvisející, slovo se přeškrtne a hráč přijde o jeden život.  
- Hráč **vyhraje**, když správně označí všech 5 souvisejících slov.  
- Hráč **prohraje** po 3 chybných výběrech.

---

## ⚙️ Instalace a spuštění

1. Naklonujte repozitář nebo stáhněte soubory `main.cpp` a `guess-the-theme.db`.  
2. Otevřete terminál a přeložte projekt:  
   ```sh
   g++ -o guess-theme main.cpp -lsqlite3

### Struktura kódu

- **main()**  
  Hlavní herní smyčka; zpracovává vstup od uživatele, výstup a herní logiku.

- **promichaniPoradi()**  
  Zamíchá pořadí slov a přiřadí značky, zda jsou slova související nebo nesouvisející.

- **vypsaniPromichanychSlov()**  
  Zobrazí zamíchaný seznam slov s barevným označením a formátováním podle odhadů hráče.

- **uvodnitext()**  
  Vypíše úvodní text a pravidla hry.

- **kontrolaKonce()**  
  Zkontroluje, zda byla správně uhodnuta všechna související slova.

---

### Autor

Tento program byl vytvořen jako demonstrační projekt pro procvičení:

- Práce s konzolovým vstupem a výstupem v C++
- Integrace s databází SQLite
- Základní návrh a implementaci herní logiky

