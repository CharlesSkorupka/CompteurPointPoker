#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <array>
#include <mainLaPlusHaute.h>
#include <Card.h>
#include <NomMain.h>

using namespace std;

int mainLaPlusHaute(){
    int score = 0;
    int nbHand = 5;

    //ici c'est pour créer le vecteur joueur 1  joueur 2
    // tu peux juste prendre ce que te donne cloclo

    vector <int> joueur1 =detectionCombinaison(handGeneration());
    vector <int> joueur2 =detectionCombinaison(handGeneration());



    // <Code pour verifier deux mains>

    if (joueur1[0] > joueur2[0])
    {
        //std::cout << "joueur1 gagne" << endl; // je debug

        joueur = "joueur1 ";
        NomsDesMain(joueur1[0]);
        //std::cout << joueur << endl;   //debug
    }
    else if (joueur1[0] < joueur2[0])
    {
        //std::cout << "joueur2 gagne" << endl; // je debug

        joueur = "joueur2 ";
        NomsDesMain(joueur2[0]);
    }
    else if (joueur1[0] = joueur2[0])
    {
        //std::cout << "egalite (pair ou autre)" << endl; // je debug
        if (joueur1[1] > joueur2[1]) // joueur 1 ? la carte la plus petite
        {
            joueur = "joueur1 ";
            NomsDesMain(joueur1[0]);
            // std::cout << "je suis la 2" << endl;
        }
        else if (joueur1[1] < joueur2[1]) //le joueur 2 ? un num?ro plus bas que le joueur 2
        {
            joueur = "joueur2 ";

            NomsDesMain(joueur2[0]);
            //std::cout << "je suis la" << endl;

        }

        else if (joueur1[1] = joueur2[1])
        {
            std::cout << "egalite" << endl;
        }

        //je dois definir l'?galit? mais pour ?a je dois avoir plus d'information sur les cartes.
    }
    else
        std::cout << "Erreur ! cette combinaison n'est pas possible." << endl; // je debug
    return 0;

}
