#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
enum meso {svinjetina,junetina,piletina,bez};

class Meso
{
private:
    int gramaza;
    meso vrstaMesa;
public:
    Meso(){gramaza = 0; vrstaMesa = bez;}
    Meso(const Meso &m) {gramaza = m.gramaza; vrstaMesa = m.vrstaMesa;}

    bool setGramaza(int gg)
    {
        if(gg>=0 && gg<=1000)
        {
            gramaza = gg;
            return true;
        }else
            return false;
    }
    void setVrstaMesa(meso vm)
    {
        vrstaMesa = vm;
    }
    int getGramaza()const
    {
        return gramaza;
    }
    string getVrsta()const
    {
        if(vrstaMesa == svinjetina)
        {
            return "svinjetina";
        }else if (vrstaMesa == junetina)
        {
            return "junetina";
        }else if (vrstaMesa == piletina)
        {
            return "piletina";
        }else
            return "nema mesa";
    }
};
void ispisMesa(const Meso m)
{
    cout<<m.getGramaza()<<endl;
    cout<<m.getVrsta()<<endl;
}

enum prilog {riza,pomfrit,pasulj,testenina,bezpriloga};

class Prilozi
{
private:
    prilog p;
public:
    Prilozi(){p = bezpriloga;}
    Prilozi(const Prilozi &pr){p = pr.p;}

    void setPrilog(prilog pp)
    {
        p = pp;
    }

    string getPrilog()const
    {
        if(p == riza)
        {
            return "prilog je riza";
        }else if(p == pomfrit)
        {
            return "prilog je pomfrit";
        }else if(p == pasulj)
        {
            return "prilog je pasulj";
        }else if(p == testenina)
        {
            return "prilog je testenina";
        }else
            return "bez priloga";
    }
};
void ispisiPrilog(const Prilozi pi)
{
    cout<<pi.getPrilog()<<endl;
}
enum stanjeObroka {pocetakOdabira,odabranoMeso,odabranPrilog,Spreman,Zagoreo};

class Obrok
{
private:
    Meso m;
    Prilozi z;
    stanjeObroka stanje;
public:
    Obrok() : m(), z(){stanje = pocetakOdabira;}
    Obrok(const Obrok &obrok) :m(obrok.m), z(obrok.z){stanje = obrok.stanje;}

    Meso getMeso()const
    {
        return m;
    }
    Prilozi getPrilog()const
    {
        return z;
    }
    string getStanje()const
    {
        if(stanje == pocetakOdabira)
        {
            return "Birate obrok";
        }else if(stanje == odabranoMeso)
        {
            return "Odabrali ste meso";
        }else if(stanje == odabranPrilog)
        {
            return "Odabrali ste prilog";
        }else if(stanje == Zagoreo)
        {
             return "Obrok je nazalost zagoreo :(";
        }else
                return "Vas obrok je spremannnn";
    }

    stanjeObroka getStanjeObroka()
    {
        return stanje;
    }
    bool odaberiMeso(meso mm, int gram){
        if(gram>=1 && gram<=1000 && stanje == pocetakOdabira){
            m.setVrstaMesa(mm);
            m.setGramaza(gram);
            stanje = odabranoMeso;
            return true;
        }else
            return false;
    }
     bool odaberiPrilog(prilog pp){
        if(stanje == odabranoMeso){
            stanje = odabranPrilog;
            z.setPrilog(pp);
            return true;
        }else{
            return false;
        }
    }
    bool spremiObrok(){
        if(stanje == odabranPrilog){
        int sansaDaZagori = rand()%10+1;
        if(sansaDaZagori == 1){
            stanje = Zagoreo;
        }else{
            stanje = Spreman;
        }
            return true;
        }else{
            return false;
        }
    }
};
void ispisiObrok(const Obrok o)
{
    cout<<"-----------------"<<endl;
    ispisMesa(o.getMeso());
    ispisiPrilog(o.getPrilog());
    cout<<o.getStanje()<<endl;
    cout<<"-----------------"<<endl;
}
int meni()
{
    int opcija;

    cout<<"1. Izbor zeljenog mesa"<<endl;
    cout<<"2. Izbor zeljenog priloga"<<endl;
    cout<<"3. Spremite porudzbinu"<<endl;
    cin>>opcija;

    return opcija;
}
int main()
{
    Obrok O;
    srand(time(NULL));

    int op; ///opcija
    int odaberiMeso;
    int gramazaMesa;
    int prilogcic;

    bool prom;

    do
    {
        op = meni();
        switch(op)
        {
        case 1:
            cout<<"Odabir vrste i gramaze mesa za obrok: "<<endl;
            cout<<"1. Svinjetina\n2. Junetina\n3. Piletina\n4. Bez mesa\n"<<endl;
            cin>>odaberiMeso>>gramazaMesa;
            if(odaberiMeso == 1)
            {
                prom = O.odaberiMeso(svinjetina,gramazaMesa);
            }else if(odaberiMeso == 2)
            {
                prom = O.odaberiMeso(junetina,gramazaMesa);
            }else if(odaberiMeso == 3)
            {
                prom = O.odaberiMeso(piletina,gramazaMesa);
            }else
                prom = O.odaberiMeso(bez,gramazaMesa);

                break;
        case 2:
            cout<<"Odabir priloga uz obrok: "<<endl;
            cout<<"1. Riza\n2. Pomfrit\n3. Pasulj\n4. Testenina\nBez priloga\n"<<endl;
            cin>>prilogcic;
            if(prilogcic == 1)
            {
                prom = O.odaberiPrilog(riza);
            }else if(prilogcic == 2)
            {
                 prom = O.odaberiPrilog(pomfrit);
            }else if(prilogcic ==3 )
            {
                 prom = O.odaberiPrilog(pasulj);
            }else if(prilogcic == 4)
            {
                 prom = O.odaberiPrilog(testenina);
            }else
                 prom = O.odaberiPrilog(bezpriloga);

                break;
        case 3:
            prom = O.spremiObrok();
        break;
    }
    if(op>3 || op<1)
        cout<<"Izabrali ste nepostojecu opciju pokusajte ponovo!"<<endl;
    else if(prom == true)
        ispisiObrok(O);
    }while(O.getStanjeObroka()!= Zagoreo && O.getStanjeObroka()!= Spreman);

    return 0;
}
