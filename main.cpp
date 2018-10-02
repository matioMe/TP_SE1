#include <iostream>
#include "temps.h"

using namespace std;

int main()
{
    Temps myClock;

    //test
    myClock.afficheTemps();
    /*
    myClock.modifieTemps(0, 0, 0, 0, 0, 2001);
    myClock.afficheTemps();


    //test bisextille
    for(int i=0; i<730; i++) //un peu plus de 2 ans
    {
        myClock.ajouteJ();
        myClock.afficheTemps();
    }

    //test tictac
    for(long int i=0; i<86400; i++) //une journée
    {
        myClock.ticTac();
        myClock.afficheTemps();
    }
*/

    myClock.modifieTemps(0, 0, 0, 0, 12, 2001);
    myClock.afficheTemps();



    //test modifieJMA
    //OK
    myClock.modifieJMA(12, 11, 1222);
    myClock.afficheTemps();
    //ERR J
    myClock.modifieJMA(31, 4, 1222);
    myClock.afficheTemps();
    //ERR M
    myClock.modifieJMA(12, 12, 1222);
    myClock.afficheTemps();
    //test modifieJMA bisextile
    //OUI
    myClock.modifieJMA(28, 1, 2016);
    myClock.afficheTemps();
    //NON
    myClock.modifieJMA(28, 1, 1222);
    myClock.afficheTemps();

    /*
    //test modifieHMS
    //OK
    myClock.modifieHMS(22, 12, 34);
    myClock.afficheTemps();
    //ERR H +
    myClock.modifieHMS(24, 12, 34);
    myClock.afficheTemps();
    //ERR H -
    myClock.modifieHMS(-1, 12, 34);
    myClock.afficheTemps();
    //ERR M +
    myClock.modifieHMS(22, 70, 34);
    myClock.afficheTemps();
    //ERR S +
    myClock.modifieHMS(22, 12, 60);
    myClock.afficheTemps();


    if(myClock.isBissextile(2000)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    if(myClock.isBissextile(1999)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    if(myClock.isBissextile(2016)) cout<<"true"<<endl;
    else cout<<"false"<<endl;*/

    return 0;
}
