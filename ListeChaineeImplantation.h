//
// Created by Felix Noiseux on 2024-02-03.
//

#ifndef MONPROJET_LISTECHAINEEIMPLANTATION_H
#define MONPROJET_LISTECHAINEEIMPLANTATION_H

#include "ListeChainee.h"


namespace td3 {

    template<typename T>
    ListeChainee<T>::ListeChainee():premier(new Noeud()), dernier(new Noeud()), cardinal(0) {
        premier->suivant = dernier;
        dernier->precedent = premier;
    };

    template<typename T>
    ListeChainee<T>::~ListeChainee() {
        while (premier) {
            Noeud* temp = premier;
            premier = premier->suivant;
            delete temp;
        }
    }

    template<typename T>
    void ListeChainee<T>::ajouterQueue(const T &element) {
        Noeud* nouveau = new Noeud(element, dernier, dernier->precedent);
        dernier->precedent->suivant = nouveau;
        dernier->precedent = nouveau;
        cardinal++;
    }

    template<typename T>
    void ListeChainee<T>::ajouterTete(const T &element) {
        Noeud* nouveau = new Noeud(element, premier->suivant, premier);
        premier->suivant->precedent = nouveau;
        premier->suivant = nouveau;
        cardinal++;
    }

    template<typename T>
    T &ListeChainee<T>::recevoirElementAPos(int pos) {
        Noeud* courant = recevoirNoeudAPos(pos);
        return courant->donnee;
    }

    template<typename T>
    void ListeChainee<T>::retirerElementAPos(int pos) {

        Noeud* courant = recevoirNoeudAPos(pos);

        courant->suivant->precedent = courant->precedent;
        courant->precedent->suivant = courant->suivant;

        delete courant;
        cardinal --;


    }

    template<typename T>
    typename ListeChainee<T>::Noeud *ListeChainee<T>::recevoirNoeudAPos(int pos) {

        if (pos < 0 || pos >= cardinal) {
            throw std::out_of_range("Index hors limites");
        }

        Noeud* courant;
        if(pos < cardinal / 2){
            courant = premier->suivant;
            for(int i = 0; i < pos; ++i ) {
                courant = courant->suivant;
            }
        }
        else {
            courant = dernier->precedent;
            int reversePos = cardinal - pos - 1;
            for(int i = 0; i < reversePos; ++i){
                courant = courant->precedent;
            }
        }

        return courant;
    }

    template<typename T>
    void ListeChainee<T>::insererElementAPos(T element, int pos) {
        Noeud* courant = recevoirNoeudAPos(pos);

        if(pos == 0) ajouterTete(element);
        if(pos == cardinal) ajouterQueue(element);

        Noeud* precedent = recevoirNoeudAPos(pos - 1);
        Noeud* suivant = precedent->suivant;
        Noeud* nouveau = new Noeud(element, suivant, precedent);
        precedent->suivant = nouveau;
        suivant->precedent = nouveau;

        cardinal++;

    }


    template<typename T>
    int ListeChainee<T>::getLength() const {
        return cardinal;
    }

    template<typename T>
    bool ListeChainee<T>::appartient(const T &element) const {
        if(premier->suivant == dernier)  return false;

        Noeud* courant = premier->suivant;
        while(courant != dernier){
            if(courant->donnee == element) return true;
            courant = courant->suivant;
        }

        return false;
    }



}



#endif //MONPROJET_LISTECHAINEEIMPLANTATION_H
