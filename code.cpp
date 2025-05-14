#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale.h>
#include <string>
#include <vector>
#include "sqlite3.h"
#include <algorithm>
#include <ctime>


using namespace std;

struct Record {
    std::string theme;
    std::string souv1;
    std::string souv2;
    std::string souv3;
    std::string souv4;
    std::string souv5;
   
    
    std::string nesouv1;
    std::string nesouv2;
    std::string nesouv3;
    std::string nesouv4;
    std::string nesouv5;
};

void promichaniPoradi(string SlovaNezamichana[10], bool Sloty[10], string SlavaZamichana[10]);

int main()
{

    srand(NULL);


    bool volneSlotyProPromichani[10] = { false, false, false, false, false, false, false, false, false, false};
    int zivoty = 3;
    string ZamichanaSlova[10] = {};
    string NezamichanaSlova[10] = {};


    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_CTYPE, "");

    sqlite3* db;
    sqlite3_stmt* stmt;
    Record slova;

    // Otevření databáze
    if (sqlite3_open("guess-the-theme.db", &db) != SQLITE_OK) {
        std::cerr << "Chyba při otevírání databáze: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    //  Dotaz pro 1 náhodný řádek z tabulky themes
    const char* sql_theme = "SELECT theme, souv1, souv2, souv3, souv4, souv5 FROM themes ORDER BY RANDOM() LIMIT 1;";
    if (sqlite3_prepare_v2(db, sql_theme, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Chyba při přípravě dotazu (themes): " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Načtení jednoho řádku z themes
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        slova.theme = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        slova.souv1 = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        slova.souv2 = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        slova.souv3 = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        slova.souv4 = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        slova.souv5 = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));

        std::cout << "Náhodný záznam z themes:\n";
        std::cout << "Theme: " << slova.theme << std::endl;
        std::cout << "Souv1: " << slova.souv1 << std::endl;
        std::cout << "Souv2: " << slova.souv2 << std::endl;
        std::cout << "Souv3: " << slova.souv3 << std::endl;
        std::cout << "Souv4: " << slova.souv4 << std::endl;
        std::cout << "Souv5: " << slova.souv5 << std::endl;

      
        
        NezamichanaSlova[0] = slova.souv1;
        NezamichanaSlova[1] = slova.souv2;
        NezamichanaSlova[2] = slova.souv3;
        NezamichanaSlova[3] = slova.souv4;
        NezamichanaSlova[4] = slova.souv5;
       
       
    }
    else {
        std::cerr << "Tabulka themes je prázdná nebo nelze číst data.\n";
    }

    // Uvolnění předchozího dotazu
    sqlite3_finalize(stmt);

    //  Dotaz pro 5 náhodných slov z tabulky nesouvisejici-slova
    const char* sql_slova = "SELECT slovo FROM nesouvisejici_slova ORDER BY RANDOM() LIMIT 5;";
    if (sqlite3_prepare_v2(db, sql_slova, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Chyba při přípravě dotazu (nesouvisejici_slova): " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    std::cout << "\n5 náhodných nesouvisejících slov:\n";
    int count = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string slovo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        
        NezamichanaSlova[count + 5] = slovo;

        std::cout << count++ + 1  << ". " << slovo << std::endl;
    }

    // Uvolnění a uzavření
    sqlite3_finalize(stmt);
    sqlite3_close(db);
   



    promichaniPoradi(NezamichanaSlova, volneSlotyProPromichani, ZamichanaSlova);
    cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
         
        cout << i+1 << ". " << ZamichanaSlova[i] << std::endl;

    }



    return 0;
}


void promichaniPoradi(string SlovaNezamichana[10], bool Sloty[10], string SlovaZamichana[10]) {
    // Nejprve nastavíme všechny sloty jako volné
    for (int i = 0; i < 10; i++) {
        Sloty[i] = false;
    }

    // Pro každé slovo z původního pole najdeme náhodnou volnou pozici
    for (int i = 0; i < 10; i++) {
        int nahodnaPozice;

        // Hledáme náhodnou volnou pozici
        do {
            nahodnaPozice = rand() % 10; // Generuje číslo 0-9
        } while (Sloty[nahodnaPozice]); // Opakujeme, dokud nenajdeme volný slot

        // Umístíme slovo na náhodnou pozici a označíme slot jako obsazený
        SlovaZamichana[nahodnaPozice] = SlovaNezamichana[i];
        Sloty[nahodnaPozice] = true;
    }
}
