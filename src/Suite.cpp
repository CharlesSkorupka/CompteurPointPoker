#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>
#include "Suite.h"
#include "Card.h"

using namespace std;

vector <int> suite(vector <Card> hand){//toute les cartes se suivent    NE FONCTIONNE PAS SI C'EST UN AS
    vector <int> handValue;// ce que je renvoie a françois
    handValue.push_back(4);//on lui assigne le code d'une couleur

    vector <int> mainRanger;//il faut les trier dans l'ordre croissant avant
    for(int i = 0; i<5;i++){
        mainRanger.push_back(hand[i].Getm_value());//on récupère les valeurs des cartes
    }
    sort(mainRanger.begin(),mainRanger.end());//on trie les valeurs des cartes
    if(mainRanger[0]+1==mainRanger[1]&&mainRanger[0]+2==mainRanger[2]&&mainRanger[0]+3==mainRanger[3]&&mainRanger[0]+4==mainRanger[4]){
        //cout<<"\nLa suite est ok\n";
        handValue.push_back(mainRanger[4]);//on stocke la valeur de la carte la plus forte
        return handValue;
    }else{
        //cout<<"Ce n'est pas une suite";
        return handValue;}
}
