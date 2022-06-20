#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>
#include "Full.h"
#include "Card.h"
#include "Brelan.h"
#include "Doublet.h"

using namespace std;


vector<int> full(vector <Card> hand){// PAS FINI IL NE PASSE PAS DANS LES DOUBLET
    vector <int> handValue;// ce que je renvoie a françois
    handValue.push_back(6);//on lui assigne le code d'une couleur

    if(brelan(hand).size()>1&&doublet(hand).size()>1){
    vector <int> cardOrdered; //vecteur qui aura les cartes rangé dans l'ordre croissant
    bool isBrelan=0;        //on va vérifier si c'est un brelan
    bool isDoublet=0;       //on va vérifier si c'est un double

    for(int i = 0; i<5;i++){
        cardOrdered.push_back(hand[i].Getm_value());//on récupère les valeurs
    }
    sort(cardOrdered.begin(),cardOrdered.end());//on ordonne nos cartes

    if(cardOrdered[2]==cardOrdered[3]){
        handValue.push_back(cardOrdered[2]);
        handValue.push_back(cardOrdered[1]);
    }
    else if(cardOrdered[2]==cardOrdered[1]){
        handValue.push_back(cardOrdered[2]);
        handValue.push_back(cardOrdered[3]);
    }
    return handValue;
    }
    return handValue;
}
