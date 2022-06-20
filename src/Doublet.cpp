#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>
#include "Doublet.h"
#include "Card.h"

    using namespace std;

vector <int> doublet(vector <Card> hand){
    vector <int> handValue;// ce que je renvoie a fran�ois
    handValue.push_back(1);//on lui assigne le code d'une couleur

    vector <int> mainRanger;//il faut les trier dans l'ordre croissant avant
    for(int i = 0; i<5;i++){
        mainRanger.push_back(hand[i].Getm_value());//on r�cup�re les valeurs des cartes
    }

    for(int i =0;i<5;i++){
        if(count(mainRanger.begin(),mainRanger.end(),mainRanger[i])==2){
            handValue.push_back(mainRanger[i]);
        return handValue;
        }
    }
return handValue;
}
