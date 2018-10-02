#include "temps.h"


int Temps::nbHorloges = 0;

Temps::Temps(): sec(0), min(0), heure(0), jour(0), mois(0), an(0) //OK
{
    //def du nb de jour/mois
    nbJourParMois[0]=31; //jan
    nbJourParMois[1]=28; //fev
    nbJourParMois[2]=31; //mars
    nbJourParMois[3]=30; //avril
    nbJourParMois[4]=31; //mai
    nbJourParMois[5]=30; //juin
    nbJourParMois[6]=31; //juil
    nbJourParMois[7]=31; //aout
    nbJourParMois[8]=30; //sept
    nbJourParMois[9]=31; //oct
    nbJourParMois[10]=30; //nov
    nbJourParMois[11]=31; //dec

    Temps::nbHorloges++;
}

Temps::~Temps() //OK
{
    Temps::nbHorloges--;
}

void Temps::modifieTemps(int sec, int min, int heure, int jour, int mois, int an)
{
    if(mois>=0 && mois<12) //evite le depassement de tableau
    {
        if((jour>=0 && jour<nbJourParMois[mois] && heure>=0 &&
            heure<24 && min>=0 && min<60 && sec>=0 && sec<60)
          || (isBissextile(an) && mois==1 && jour>=0 && jour<29))
        {
            this->sec=sec;
            this->min=min;
            this->heure=heure;
            this->jour=jour;
            this->mois=mois;
            this->an=an;
        }
        else
        {
            cout<<"Erreur, une des valeurs d'entrées dans modifieTemps() n'est pas correcte."<<endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cout<<"Erreur, la valeur  mois entrée dans modifieTemps() n'est pas correcte."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Temps::modifieJMA(int jour, int mois, int an) //ERR
{
    if(mois>=0 && mois<12) //evite le depassement de tableau plus bas
    {
        if((jour>=0 && jour<nbJourParMois[mois]) || (isBissextile(an) && mois==1 && jour>=0 && jour<29))
        {
            if(this->isBissextile(an)) //si divisible par 10 et par 4 ou par 4 et par 400
            {
                this->anneeBissextile=true;
                this->jour=jour;
                this->mois=mois-1;
                this->an=an;
            }
            else this->anneeBissextile=false;
        }
        else
        {
            cout<<"Erreur, une des valeurs d'entrées dans modifieJMA() n'est pas correcte."<<endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cout<<"Erreur, une des valeurs d'entrées dans modifieJMA() n'est pas correcte."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Temps::modifieHMS(int heure, int min, int sec) //ERR
{
    if(heure>=0 && heure<24 && min>=0 && min<60 && sec>=0 && sec<60)
    {
        this->heure=heure;
        this->min=min;
        this->sec=sec;
    }
    else
    {
        cout<<"Erreur, une des valeurs d'entrées dans modifieHMS() n'est pas correcte."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Temps::ajouteA() //OK
{
    an++;
}

void Temps::ajouteMois()
{
    mois++;
    if(mois==12)
    {
        mois=0;
        this->ajouteA();
    }
}

void Temps::ajouteJ()
{
    jour++;
    if((jour==this->nbJourParMois[this->mois] && mois!=1) || (jour==this->nbJourParMois[this->mois] && mois==1 && !isBissextile())
            || (jour==this->nbJourParMois[this->mois]+1 && mois==1 && isBissextile()))
    {
        jour=0;
        this->ajouteMois();
    }
}

void Temps::ajouteH() //OK
{
    heure++;
    if(heure==24)
    {
        heure=0;
        this->ajouteJ();
    }
}

void Temps::ajouteMin() //OK
{
    min++;
    if(min==60)
    {
        min=0;
        this->ajouteH();
    }
}

void Temps::ticTac() //OK
{
    sec++;
    if(sec==60)
    {
        sec=0;
        this->ajouteMin();
    }
}

void Temps::ticTac(int T)
{
    int min, heure, jour;

    this->sec+=T;
    min=sec%60;
    this->sec/=60;

    this->min+=min;
    heure=min%60;
    this->min/=60;

    this->heure+=heure;
    jour=heure%24;
    this->heure/=24;

    for(int i=0; i<jour; i++)
    {
        ajouteJ();
    }
}


void Temps::afficheTemps() //OK
{
    cout<<jour+1;
    switch(mois)
    {
    case 0:
        cout<<" janvier ";
        break;
    case 1:
        cout<<" fevrier ";
        break;
    case 2:
        cout<<" mars ";
        break;
    case 3:
        cout<<" avril ";
        break;
    case 4:
        cout<<" mai ";
        break;
    case 5:
        cout<<" juin ";
        break;
    case 6:
        cout<<" juillet ";
        break;
    case 7:
        cout<<" aout ";
        break;
    case 8:
        cout<<" septembre ";
        break;
    case 9:
        cout<<" octobre ";
        break;
    case 10:
        cout<<" novembre ";
        break;
    case 11:
        cout<<" decembre ";
        break;
    }
    cout<<an<<" "<<heure<<":"<<min<<":"<<sec<<endl;
}

int Temps::afficheCompteur() //OK
{
    cout<<"il y a "<<Temps::nbHorloges<<" horloges instanciées."<<endl;

    return Temps::nbHorloges;
}

bool Temps::isBissextile(int an) //OK
{
    //si non divisible par 10 mais par 4 ou par 4 et par 400
    if((an%100!=0 && an%4==0) || (an%400==0))
    {
        anneeBissextile=true;
        return true;
    }
    else
    {
        anneeBissextile=false;
        return false;
    }
}

bool Temps::isBissextile(void) //OK
{
    //si non divisible par 10 mais par 4 ou par 4 et par 400
    if((an%100!=0 && an%4==0) || (an%400==0))
    {
        anneeBissextile=true;
        return true;
    }
    else
    {
        anneeBissextile=false;
        return false;
    }
}
