#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>
#include "Color.h"
#include "Card.h"

using namespace std;

vector <int> color(vector <Card> hand){
    vector <int> handValue;// ce que je renvoie a françois
    handValue.push_back(5);//on lui assigne le code d'une couleur

    vector <int> mainRanger;//le vectuer avec la main ranger dans l'ordre croissant
    for(int i = 0; i<5;i++){
        mainRanger.push_back(hand[i].Getm_value());//on récupère les valeurs de la main
    }
    sort(mainRanger.begin(),mainRanger.end());//on organise par ordre croissant les cartes

    vector <int> lesCouleursDesCartes;//on va regarder les couleurs des cartes
    for(int i =0;i<5;i++){
        lesCouleursDesCartes.push_back(hand[i].Getm_color());//on récupère les couleurs des cartes
    }
    if(count(lesCouleursDesCartes.begin(),lesCouleursDesCartes.end(),lesCouleursDesCartes[1])==5){//on regarde si c'est cinq fois la même
        //cout<<"C'est une couleur YOUPI!";
        handValue.push_back(mainRanger[4]);
        return handValue;
    }
    else{//cout<<"Ce n'est pas une couleur";
            return handValue;}
}
