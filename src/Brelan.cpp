#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>
#include "Brelan.h"
#include "Card.h"

using namespace std;

vector<int> brelan(vector <Card> hand){
    vector <int> handValue;// ce que je renvoie a françois
    handValue.push_back(3);//on lui assigne le code d'une couleur

    vector <int> mainRanger;//il faut les trier dans l'ordre croissant avant
    for(int i = 0; i<5;i++){
        mainRanger.push_back(hand[i].Getm_value());//on récupère les valeurs des cartes
    }
    sort(mainRanger.begin(),mainRanger.end());//on trie les valeurs des cartes
    for(int i =0;i<5;i++){
        if(count(mainRanger.begin(),mainRanger.end(),mainRanger[i])==3){
            //cout<<"\tC'est un double\n";
            handValue.push_back(mainRanger[i]);
        return handValue;
        }
    }
return handValue;
}
