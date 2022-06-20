#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <array>
#include "QuinteFlush.h"
#include "Card.h"
#include "Suite.h"
#include "Color.h"


using namespace std;

vector<int> quinteFlush(vector <Card> hand){
    vector <int> handValue;// ce que je renvoie a françois
    handValue.push_back(8);//on lui assigne le code d'une quinte Flush
    if(suite(hand).size()>1 && color(hand).size()>1){
        //cout<<"\nC'est une quite Flush\n";
        vector <int> mainRanger;//il faut les trier dans l'ordre croissant avant
        for(int i = 0; i<5;i++){
            mainRanger.push_back(hand[i].Getm_value());//on récupère les valeurs des cartes
        }
        sort(mainRanger.begin(),mainRanger.end());//on trie les valeurs des cartes
        handValue.push_back(mainRanger[4]);
        return handValue;
        }
    else{
        //cout<<"\nCe n'est pas une quite flush\n";
        return handValue;
    }
}
