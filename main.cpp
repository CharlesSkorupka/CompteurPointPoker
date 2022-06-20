#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <array>
#include"Hauteur.h"
#include "include/Card.h"
#include "Color.h"
#include "Suite.h"
#include "Doublet.h"
#include "Brelan.h"
#include "Carre.h"
#include "DoublePaire.h"
#include "Full.h"
#include "QuinteFlush.h"
#include "NomMain.h"

using namespace std;
std::string joueur;



vector<Card> GenerJeuxCarte(){
    vector<Card> JeuxCarte;//on crée le vecteur où seront stocker les cartes
    int carte;
    //int tmp = 0;
    for(int a = 1; a<5; a++){//on créer toutes les cartes
        for(int i = 2 ; i < 15; i++){
            if (a==1){
                carte = 67;
            }else if (a==2){
             carte = 75;
            }else if (a==3){
             carte = 80;
            }else if (a==4){
             carte = 84;
            }
            JeuxCarte.push_back(Card(carte,i));  //on stocke la carte créé
          //  tmp = tmp+1;
    }
}
return JeuxCarte;//on revoie tout le deck
}



vector<int> carteDejaPrise;//on créer une variable global pour toutes les cartes prise
vector<Card> JeuxCarte= GenerJeuxCarte();//on stoke le jeux de cartes


vector<Card> handGeneration(){
    cout<<"\nCréation d'une main...\n";
    srand(time(NULL));//on initiallise l'aléatoire
    vector<Card> handJ1;//on créer la variable main
    if(carteDejaPrise.size()<46){//on regarde s'il y a suffisament de cartes
    while (handJ1.size()<5){//on sort de la boucle lorsque l'on a 5 cartes
            //on choisi un index de carte
            int indexCarte;
            indexCarte = rand() % 52;//on choisit aléatoirement une carte

                if (!count(carteDejaPrise.begin(), carteDejaPrise.end(), indexCarte)) {//on vérifie si la carte n'est pas déjà prise
                    handJ1.push_back(JeuxCarte[indexCarte]);//on stocke la carte dans la main
                    carteDejaPrise.push_back(indexCarte);//on retient que la cartes est prise
                }
            }

    }else{cout<<"Nombre de joueur limite atteint";}
    for(int j = 0; j<handJ1.size();j++){
            cout<<"la carte n "<<j<<" est : "<<handJ1[j]<<endl;//on regarde une main génénrer
    }
    return handJ1;//on revoie la main
}


vector<int> detectionCombinaison(vector <Card> hand){
    //le but est de vérifier ce qu'il y a dans la main
    //on regarde de la combinaison la plus forte a la moins forte
    //s'il existe un moyen plus simple je suis preneur

if (quinteFlush(hand).size()==1){
    //cout<<"\nCe n'est pas une quite flush\n";
    if(carre(hand).size()==1){
      //  cout<<"\nCe n'est pas un carre\n";
        if(full(hand).size()==1){
        //    cout<<"\nCe n'est pas un full\n";
            if(color(hand).size() == 1){
          //      cout<<"\nCe n'est pas une couleur\n";
                if(suite(hand).size()==1){
            //        cout<<"\nCe n'est pas une suite\n";
                    if(brelan(hand).size() == 1){
              //          cout<<"\nCe n'est pas un brelan\n";
                        if(doublePaire(hand).size()==1){
                         //   cout<<"\nCe n'est pas une double paire\n";
                            if (doublet(hand).size()==1){
                                cout<<"\nC'est une hauteur\n";
                                return hauteur(hand);
                            }
                            else{
                                    cout<<"\nC'est une pair\n";
                                    return doublet(hand);}
                        }
                        else{
                                cout<<"\nC'est une double pair\n";
                                return doublePaire(hand);}
                    }
                    else{
                            cout<<"\nC'est un brelan\n";
                            return brelan(hand);}
                }
                else{
                        cout<<"C'est une suite\n";
                        return suite(hand);}
            }
            else{
                    cout<<"\nC'est une couleur\n";
                    return color(hand);}
        }
        else{
                cout<<"\nC'est un full\n";
                return full(hand);}
    }
    else{
            cout<<"\nC'est un carre\n";
            return carre(hand);}
}
else{
        cout<<"\nC'est une quite flush\n";
        return quinteFlush(hand);
        }
}

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


int mainLaPlusHaute(){
    int score = 0;
    int nbHand = 5;

    //ici c'est pour créer le vecteur joueur 1  joueur 2

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

int main()
{
 mainLaPlusHaute();
}
