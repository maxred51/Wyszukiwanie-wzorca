#include <iostream>

using namespace std;
void naiwny(string,string,int,int);
void tab_dopasowan(string,int,int[]);
void kmp(string,string,int,int,int[]);
int maxi(int,int);
void tab_przesuniec(string,int,int[],char,char);
void bm(string,string,int,int,int[],char);
int main()
{
    string tekst,wzorzec;
    int dlt,dlw,wybor;
    cout << "Podaj tekst: " << endl;
    getline(cin,tekst,'\n');
    cout << "Podaj wzorzec: " << endl;
    getline(cin,wzorzec,'\n');
    dlt = tekst.length();
    dlw = wzorzec.length();
    int p[dlw+1];
    char pocz='a',kon='e';
    cout << "Wybierz opcje 1-3 " << endl;
    cout << "1. Wyszukiwanie wzorca algorytmem naiwnym "<<endl;
    cout << "2. Wyszukiwanie wzorca algorytmem kmp "<<endl;
    cout << "3. Wyszukiwanie wzorca algorytmem bm "<<endl;
    cin >> wybor;
    switch(wybor)
    {
        case 1:
            naiwny(tekst,wzorzec,dlt,dlw);
            break;
        case 2:
            tab_dopasowan(wzorzec,dlw,p);
            kmp(wzorzec,tekst,dlw,dlt,p);
            break;
        case 3:
            tab_przesuniec(wzorzec,dlw,p,pocz,kon);
            bm(wzorzec,tekst,dlw,dlt,p,pocz);
            break;
        default:
            cout<< "Nie ma takiej opcji "<<endl;
    }

    return 0;
}
void naiwny (string tekst, string wzorzec, int dlt, int dlw)
{
    int i=0,j=0;
    while(i<=(dlt-dlw))
    {
        j=0;
        while(j<dlw && (wzorzec[j]==tekst[i+j])) j++;
        if (j==dlw) cout <<"Wzorzec zaczyna sie od indeksu "<< i << endl;
        i++;
    }
}
void tab_dopasowan(string wzorzec,int dlw, int p[])
{
    p[0] = 0;
    p[1] = 0;
    int t=0,i=1;
    while(i<dlw)
    {
        while(t>0 && wzorzec[t]!=wzorzec[i]) t = p[t];
        if(wzorzec[t]==wzorzec[i]) t++;
        p[i+1] = t;
        i++;
    }

}
void kmp(string wzorzec,string  tekst,int dlw,int dlt,int p[])
{
    int i=0,j=0;
    while(i<(dlt-dlw+1))
    {
        while(wzorzec[j]==tekst[i+j] && j<dlw) j++;
        if(j==dlw) cout <<"Wzorzec zaczyna sie od indeksu "<< i << endl;
        i+= maxi(1,j-p[j]);
        j = p[j];
    }
}
int maxi(int a,int b)
{
    if(a>b) return a;
    else return b;
}
void tab_przesuniec(string wzorzec,int dlw,int p[],char pocz,char kon)
{
    int n_pocz = int(pocz);
    int n_kon = int(kon);
    int i=0;
    while(i<=(n_kon - n_pocz))
    {
        p[i] = -1;
        i++;
    }
    i=0;
    while(i<dlw)
    {
        p[wzorzec[i]-n_pocz]=i;
        i++;
    }
}
void bm(string wzorzec,string tekst,int dlw,int dlt,int p[],char pocz)
{
    int n_pocz = int(pocz);
    int i=0,j;
    while(i<=(dlt-dlw))
    {
        j=dlw-1;
        while(j>=-1 && (wzorzec[j]==tekst[i+j])) j--;
        if(j == -1)
        {
            cout <<"Wzorzec zaczyna sie od indeksu "<< i << endl;
            i++;
        }
        else
        {
            i += maxi(1,j-p[tekst[i+j]-n_pocz]);
        }
    }
}
