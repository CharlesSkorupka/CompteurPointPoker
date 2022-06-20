#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>
#include "Hauteur.h"
#include "Card.h"

using namespace std;

vector <int> hauteur(vector <Card> hand){
    vector <int> isSuite;//il faut les trier dans l'ordre croissant avant
    vector <int> handValue;
    handValue.push_back(0);
    for(int i = 0; i<5;i++){
        isSuite.push_back(hand[i].Getm_value());
    }
    sort(isSuite.begin(),isSuite.end());
    cout<<"\nLa hauteur de la carte est : "<< isSuite[4]<<"\n";
    handValue.push_back(isSuite[4]);
    return handValue;
}
