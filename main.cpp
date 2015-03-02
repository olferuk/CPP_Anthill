using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "anthill.h"


int main()
{
    srand(time(0));

    FILE* config = fopen("config.txt", "w");

    fprintf(config, "%i\n", 4); // queenFood
    fprintf(config, "%i\n", 2); // queen will produce 1 larva every 2 turns

    fprintf(config, "%i\n", 2); // soldierFood
    fprintf(config, "%i\n", 2); // soldierPestKillAmount

    fprintf(config, "%i\n", 2); // policeFood
    fprintf(config, "%f\n", 0.1); // policeBonus

    fprintf(config, "%i\n", 1); // workingAntFood
    fprintf(config, "%i\n", 2); // workingAntProduction

    fprintf(config, "%i\n", 3); // larvaFood
    fprintf(config, "%i\n", 3); // larvaTicksToGrow

    fprintf(config, "%i\n", 2); //pestFood
    fprintf(config, "%i\n", 3); // prob to become a pest
    fprintf(config, "%i\n", 5); //pestKill prob

    fprintf(config, "%i\n", 2); // foodStorageSize

    fprintf(config, "%c %i\n", 'c', 1);
    fprintf(config, "%c %i\n", 'w', 5);
    fclose(config);

    config = fopen("config.txt", "r");
    if (config == 0)
        return -1;

    Anthill* anthill = new Anthill(config);

    string command;
    do {
        anthill->Tick();
        getline(cin, command);
        cout << '\n';
    } while (command != "q");

    return 0;
}
