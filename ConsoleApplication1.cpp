#include <iostream>
#include <cstdlib> 

enum class CellType {
    Vide,
    Joueur,
    Jackpot,
};

const int Tableau = 7;
CellType cells[Tableau * Tableau];

void initializePlayfield() {
   
    for (int i = 0; i < Tableau * Tableau; i++) {
        cells[i] = CellType::Vide;
    }

   
    srand(static_cast<unsigned int>(time(nullptr)));
    int treasureLocation = rand() % (Tableau * Tableau);
    cells[treasureLocation] = CellType::Jackpot;
}

void drawPlayfield() {
    for (int row = 0; row < Tableau; row++) {
        for (int column = 0; column < Tableau; column++) {
            int cellIndex = row * Tableau + column;
            CellType cell = cells[cellIndex];

            char cellChar;
            switch (cell) {
            case CellType::Vide:
                cellChar = '-';
                break;
            case CellType::Joueur:
                cellChar = '0';
                break;
            case CellType::Jackpot:
                cellChar = '-';
                break;
            }

            std::cout << cellChar << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    initializePlayfield();
    const int MaxVie = 10;
    int NbVie = 0;

    while (NbVie < MaxVie) {

        drawPlayfield();
        
        int x, y;
        std::cout << "Rentre les coordonees X horizontale\nEt X verticale (0 to " << (Tableau - 1) << "): ";
        std::cin >> x >> y;

     
        if (x < 0 || x >= Tableau || y < 0 || y >= Tableau) {
            std::cout << "Mauvaise coordonee reessaye\n";
            continue;
      
        int cellIndex = y * Tableau + x;
        if (cells[cellIndex] == CellType::Jackpot) {
            std::cout << "Bravo !! t as trouver le tresor\n";
            cells[cellIndex] = CellType::Joueur;
            drawPlayfield();
            break;
        }
        NbVie++;

        int VieRestante = MaxVie - NbVie;
        if (VieRestante > 0) {
            std::cout << "Il te reste " << VieRestante << " essais.\n";
        }
        else {
            std::cout << "Tu as epuise tous tes essais. Tu as perdu.\n";
            break;
        }
    }

}