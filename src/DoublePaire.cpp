#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>
#include "DoublePaire.h"
#include "Card.h"
#include "Doublet.h"

    using namespace std;

vector <int> doublePaire(vector <Card> hand){//c'est une double paire tout est dans le nom lol
    vector <int> handValue;// ce que je renvoie a fran�ois
    handValue.push_back(2);//on lui assigne le code d'une couleur
    vector <int> valeurOrdonnee;//il faut les trier dans l'ordre croissant avant
    for(int i = 0; i<5;i++){
        valeurOrdonnee.push_back(hand[i].Getm_value());
    }
    sort(valeurOrdonnee.begin(),valeurOrdonnee.end());
    if(doublet(hand).size()>1){
           // cout<<"\nOn a au moins un double\n";
            vector<int> valeurDuDouble =doublet(hand);
            for(int index=0;index<4;index++){
                if(valeurDuDouble[1]<valeurOrdonnee[index]){
                    //on est au dessus de notre double de base
                   // cout<<valeurDuDouble[1]<<" > "<<valeurOrdonnee[index];
                    if(valeurOrdonnee[index]==valeurOrdonnee[index+1]){
                        //cout<<valeurOrdonnee[index]<<" == "<<valeurOrdonnee[index+1];
                        handValue.push_back(valeurOrdonnee[index]);
                        handValue.push_back(valeurDuDouble[1]);
                        return handValue;
                    }
                }
            }

    }
    return handValue;
}
