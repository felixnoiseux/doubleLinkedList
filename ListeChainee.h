//
// Created by Felix Noiseux on 2024-02-03.
//

#ifndef MONPROJET_LISTECHAINEE_H
#define MONPROJET_LISTECHAINEE_H
namespace td3{
    template<typename T>
    class ListeChainee {
    public:
        ListeChainee();
        ~ListeChainee();

        void ajouterQueue(const T &element);
        void ajouterTete(const T &element);
        T& recevoirElementAPos(int pos);
        void retirerElementAPos(int pos);
        void insererElementAPos(const T element, int pos);
        bool appartient(const T &element) const;
        int getLength() const;

    private:
        class Noeud
        {
            public:
                T donnee;
                Noeud* suivant;
                Noeud* precedent;

                Noeud() : donnee(), suivant(), precedent(){};
                Noeud(const T &donne_item, Noeud *ptr_suivant=nullptr, Noeud *ptr_precedent=nullptr):
                       donnee(donne_item), suivant(ptr_suivant), precedent(ptr_precedent)  {};
        };


        int cardinal = 0;
        Noeud *premier;
        Noeud *dernier;

        Noeud* recevoirNoeudAPos(int pos);


    };




}





#endif //MONPROJET_LISTECHAINEE_H
