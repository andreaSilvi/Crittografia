#include <iostream>

using namespace std;

//funzione che trova la posizione del numero minore
int minore(char v[],int dim)
{
    int min=255;
    int pos=0;

    for(int i=0;i<dim;i++)
    {
        if(v[i]!=0)
        {
            //cout<<endl<<min<<">"<<v[i]<<"? ";
            if(min>v[i])
            {
                //cout<<"si\n";
                pos=i;
                min=v[i];
            }
            /*else
                cout<<"no\n";*/
        }
    }

    return pos;
}

//funzione che che ritorna un vettore con la posizione di ogni singolo elemento
void getOrdine(char chiave[],int *posizioni,int dim)
{
    int n=0;
    for(int i=0;i<dim;i++)
    {
        posizioni[minore(chiave,dim)]=n;
        chiave[minore(chiave,dim)]=0;

        n++;
    }
}

int main()
{
    string in;
    string testo;

    cout<<"inserisci la chiave: ";
    cin>>in;

    char c[in.length()];
    int ordine[in.length()];

    //caricare la chiave su un vettore 
    for(int i=0;i<in.length();i++)
    {
        c[i]=in[i];
    }

    getOrdine(c,&ordine[0],in.length());

    cout<<"inserisci il testo da cifrare: ";
    cin>>testo;

    int righe,colonne;

    //definizione dimensione matrice
    colonne=in.length();

    righe=testo.length()/in.length();
    if(testo.length()%in.length()!=0)
        righe++;

    char matrice[righe][colonne];
    int postesto=0;

    //caricamento testo su matrice
    for(int i=0;i<righe;i++)
    {
        for(int j=0;j<colonne;j++)
        {
            matrice[i][j]=testo[postesto];
            postesto++;
        }
    }

    cout<<endl<<endl;

    //lettura matrice in base alla posizione sul vettore prima ordinato
    for(int i=0;i<colonne;i++)
    {
        for(int j=0;j<righe;j++)
        {
            cout<<matrice[j][ordine[i]];
        }
        cout<<" ";
    }

    return 0;
}
