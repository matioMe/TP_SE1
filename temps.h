#ifndef TEMPS_H
#define TEMPS_H

#include <iostream>

using namespace std;

class Temps
{
private:
    int sec, min, heure, jour, mois, an;
    static int nbHorloges;
    int nbJourParMois[12];
    bool anneeBissextile=false;

public:
    Temps();
    ~Temps();
    void modifieJMA(int, int, int);
    void modifieHMS(int, int, int);
    void ajouteA();
    void ajouteMois();
    void ajouteJ();
    void ajouteH();
    void ajouteMin();
    void ticTac();
    void ticTac(int);
    void modifieTemps(int sec, int min, int heure, int jour, int mois, int an);
    void afficheTemps();
    bool isBissextile(int an);
    bool isBissextile(void);
    static int afficheCompteur(void);
};

#endif // TEMPS_H
