/*#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <array>
#include <NomMain.h>
#include <Card.h>

using namespace std;

void NomsDesMain(int score)
{
    switch (score)
    {
    case 0:
        cout << joueur << "gagne avec la plus haute main " << endl;

        break;
    case 1:
        cout << joueur << "gagne avec une pair " << endl;
        break;
    case 2:
        cout << joueur << "gagne avec une double pair " << endl;
        break;
    case 3:
        cout << joueur << "gagne avec un brelan " << endl;
        break;
    case 4:
        cout << joueur << "gagne avec une suite " << endl;
        break;
    case 5:
        cout << joueur << "gagne avec un flush " << endl;
        break;
    case 6:
        cout << joueur << "gagne avec un full " << endl;
        break;
    case 7:
        cout << joueur << "gagne avec un carre " << endl;
        break;
    case 8:
        cout << joueur << "gagne avec une quite flush " << endl;
        break;
    case 9:
        cout << "invalide argument" << endl;
        break;


    default:
        break;
    }


}
