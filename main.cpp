#include <iostream>
#include "Cripta.h"

using namespace std;

int main()
{
    Cripta c;

    string n;
    cout<<"inserisci la chiave: ";
    cin>> n;
    c.setChiave(n);
    cout<<"inserisci il testo: ";
    cin>>n;
    c.setTesto(n);
    string s=c.testoCriptato();
    cout<<"testo criptato: "<<s<<endl;
    c.setTesto(s);
    cout<<"testo decriptato: "<<c.testoDecriptato();
}
