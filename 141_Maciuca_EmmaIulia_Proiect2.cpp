/*
         Produs
       /       \
   Bluza       Fusta
       \       /
        Rochie

 */



#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

// clasa Produse - are setter/getter
// clasa Bluza, Fusta, Pantaloni, Rochie
// clasa CosCumaraturi
// clasa Utilizator - are setter/getter
// clasa Card - are setter/getter


// clasa abstracta
class IOInterface
{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
    virtual void afiseazaProdusInCos() const = 0;
};


// CLASA PRODUSE
class Produse:public IOInterface
{
protected:
    const int cod;
    static int contor;
    float pret;
    char *denumire;
    bool produsNou;// daca produsul este nou sau purtat - ma gandeam la un magazin de tip olx sau ebay
    string marime;
    string material;

    //contor e generat automat
public:
    // constructori
    Produse();
    Produse(float pret, char *denumire,bool produsNou, string marime, string material);
    Produse(float pret, char *denumire);
    Produse(const Produse &obj);

    Produse& operator=(const Produse &obj);
    friend istream& operator>>(istream&in, Produse &obj);
    friend ostream& operator<<(ostream& out, const Produse &obj);

    // operatori matematici +/- pentru scumpire/ieftinire pret
    Produse operator+(float scumpire);
    Produse operator-(float ieftinire);
    friend Produse operator+(float scumpire,Produse prod);
    friend Produse operator-(float ieftinire,Produse prod);

    // operator cast
    operator float() const {return this->pret;}
    operator bool() const{return this->produsNou;}
    operator char*() const{return this->denumire;}

    // operator conditional
    bool operator<(const Produse& p1);
    bool operator>(const Produse& p1);
    // operator ==
    bool operator==(const Produse& p1);


    // getters
    static int getContor()  {return contor;}
    int getCod() const {return cod;}
    float getPret() const {return pret;}
    const char* getDenumire() const {return denumire;}
    bool getStareProdus() const {return produsNou;}
    string getMarime() const {return marime;}
    string getMaterial() const {return material;}

    // setters
    static void getContor(int valoare) {contor = valoare;}
    void setPret(float pret) {this->pret = pret;}
    void setDenumire(char *denumire);
    void setStareProdus(bool produsNou) {this->produsNou = produsNou;}
    void setMarime(string marime) {this->marime = marime;}
    void setMaterial(string material) {this->material = material;}


    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream& out) const;

    virtual void afiseazaProdusInCos() const;

    void aplicaPromotie(string voucher);

    void sizeDown()
    {
        if(this->marime == "S" or this->marime == "s")
            this->marime = "XS";
        else if(this->marime == "M" or this->marime == "m")
            this->marime = "S";
        else if(this->marime == "L" or this->marime == "l")
            this->marime = "M";
        else if(this->marime == "XL" or this->marime == "xl")
            this->marime = "L";
        else if(this->marime == "36")
            this->marime = "34";
        else if(this->marime == "38")
            this->marime = "36";
        else if(this->marime == "40")
            this->marime = "38";
        else if(this->marime == "42")
            this->marime = "40";
        else
            cout<<"Produsul nu se poate modifica\n";
    }

    void sizeUp()
    {
        if(this->marime == "XS" or this->marime == "xs")
            this->marime = "S";
        else if(this->marime == "S" or this->marime == "s")
            this->marime = "M";
        else if(this->marime == "M" or this->marime == "m")
            this->marime = "L";
        else if(this->marime == "L" or this->marime == "l")
            this->marime = "XL";
        else if(this->marime == "34")
            this->marime = "36";
        else if(this->marime == "36")
            this->marime = "38";
        else if(this->marime == "38")
            this->marime = "40";
        else if(this->marime == "40")
            this->marime = "42";
        else
            cout<<"Produsul nu se poate modifica\n";
    }

    // destructor
    ~Produse()
    {
        if(this->denumire != NULL)
            delete[] this->denumire;
    }
};

// CLASA Bluza
class Bluza:public virtual Produse{
protected:
    string lungimeManeca;
    string culoareBluza;
public:
    //CD
    Bluza();
    //CP toti
    Bluza(float pret, char *denumire, bool produsNou,string marime, string material, string lungimeManeca, string culoareBluza);
    //CC
    Bluza(const Bluza& obj);
    //Op=
    Bluza &operator=(const Bluza &obj);
    //Op>>
    friend istream& operator>>(istream&in, Bluza &obj);
    //Op<<
    friend ostream& operator<<(ostream& out, const Bluza &obj);

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    string getLungimeManeca() const {return this->lungimeManeca;}
    string getCuloareBluza() const {return this->culoareBluza;}

    void afiseazaProdusInCos() const;

    //Des
    ~Bluza() = default;
};


// CLASA Fusta
class Fusta:public virtual Produse{
protected:
    string lungimeFusta;
    string culoareFusta;
public:
    //CD
    Fusta();
    //CP toti
    Fusta(float pret, char *denumire, bool produsNou,string marime, string material, string lungimeFusta, string culoareFusta);
    //CC
    Fusta(const Fusta& obj);
    //Op=
    Fusta &operator=(const Fusta &obj);
    //Op>>
    friend istream& operator>>(istream&in, Fusta &obj);
    //Op<<
    friend ostream& operator<<(ostream& out, const Fusta &obj);

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    string getLungimeFusta() const {return this->lungimeFusta;}
    string getCuloareFusta() const {return this->culoareFusta;}

    void afiseazaProdusInCos() const;
    //Des
    ~Fusta() = default;
};

class Pantaloni:public virtual Produse{
protected:
    string lungimePantaloni;
    string culoarePantaloni;
public:
    //CD
    Pantaloni();
    //CP toti
    Pantaloni(float pret, char *denumire, bool produsNou,string marime, string material, string lungimePantaloni, string culoarePantaloni);
    //CC
    Pantaloni(const Pantaloni& obj);
    //Op=
    Pantaloni &operator=(const Pantaloni &obj);
    //Op>>
    friend istream& operator>>(istream&in, Pantaloni &obj);
    //Op<<
    friend ostream& operator<<(ostream& out, const Pantaloni &obj);

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    string getLungimePantaloni() const {return this->lungimePantaloni;}
    string getCuloarePantaloni() const {return this->culoarePantaloni;}

    void afiseazaProdusInCos() const;

    //Des
    ~Pantaloni() = default;
};

// CLASA Rochie
class Rochie: public Bluza, public Fusta
{
public:
    //CD
    Rochie();
    //CP
    Rochie(float pret, char *denumire, bool produsNou,string marime, string material,
           string lungimeManeca, string culoareBluza,string lungimeFusta, string culoareFusta);
    //CC
    Rochie(const Rochie& obj);
    //Op=
    Rochie &operator=(const Rochie &obj);
    //Op>>
    friend istream& operator>>(istream&in, Rochie &obj);
    //Op<<
    friend ostream& operator<<(ostream& out, const Rochie &obj);

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    // creeaza rochie
    Produse creeazaRochie(Bluza bluza, Fusta fusta);

    void afiseazaProdusInCos() const;

    //Des
    ~Rochie() = default;
};

// CLASA UTILIZATOR
class Utilizator
{
private:
    string idUtilizator; // id-ul de inregistrare - de tip mail
    char *nume;
    long numarTelefon;
    string adresa;
    char gen; //F/M/O (other)


public:
    Utilizator();
    Utilizator(string idUtilizator, char *nume, long numarTelefon, string adresa, char gen);
    Utilizator(string idUtilizator, char *nume);
    Utilizator(string IdUtilizator);
    Utilizator(const Utilizator &obj);

    Utilizator& operator=(const Utilizator &obj);
    friend istream& operator>>(istream& in,Utilizator &obj);
    friend ostream& operator<<(ostream& out, const Utilizator &obj);


    // cast
    operator char() const{return this->gen;}
    operator char*() const{return this->nume;}
    operator string() const{return this->idUtilizator;}


    // +/- adauga adresa noua
    Utilizator operator+(string adresaNoua);
    friend Utilizator operator+(string adresaNoua, Utilizator persoana);

    // scaderea numarului de telefon - se sterge din profil
    Utilizator operator-(long nrTelefon);
    friend Utilizator operator-(long nrTelefon, Utilizator persoana);


    // operator conditional - luati in ordine alfabetica crescatoare in functie de idUtilizator
    bool operator>(const Utilizator& persoana);

    // operator ==
    bool operator==(const Utilizator& persoana);

    // setter
    void setIdUtilizator() {this->idUtilizator = idUtilizator;}
    void setNume()
    {
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }
    void setNumarTelefon() {this->numarTelefon = numarTelefon;}
    void setAdresa() {this->adresa = adresa;}
    void setGen() {this->gen = gen;}

    //getter
    string getIdUtilizator() const {return idUtilizator;}
    const char *getNume() const {return nume;}
    long getNumarTelefon() const {return numarTelefon;}
    string getAdresa() const {return adresa;}
    char getGen() const {return gen;}

    // metode
    void citire();
    void afisare();

    // destructor
    ~Utilizator()
    {
        if(this->nume != NULL)
            delete[] this->nume;
    }

};

// CLASA COS CUMPARATURI
class CosCumparaturi
{
private:
    Utilizator client;
    int numarProduse;
    vector <Produse*> listaProduse;
    double total;

public:
    CosCumparaturi();
    CosCumparaturi(Utilizator client,int numarProduse,  vector <Produse*> listaProduse, double total);
    CosCumparaturi(Utilizator client,int numarProduse,  vector <Produse*> listaProduse);
    CosCumparaturi(Utilizator client);
    CosCumparaturi(const CosCumparaturi &obj);

    CosCumparaturi& operator=(const CosCumparaturi &obj);
    friend istream& operator>>(istream& in, CosCumparaturi &obj);
    friend ostream& operator<<(ostream& out, const CosCumparaturi &obj);


    //opertor> - in functie de pret
    bool operator>(const CosCumparaturi& cos);

    //metode
    double getTotal() const {return total;}
    int getNumarProduse() const {return this->numarProduse;}
    void setTotal(double total) {this->total = total;}

    void citire();
    void afisare();


    void golireCos(); // cand se efectueaza plata cosul se goleste

    void adaugaProdusInCos(Produse* p);
    void stergeProdusDinCos(int i);

    Produse* adaugaProdusDinCos(int i);

    // destructor
    ~CosCumparaturi() = default;
};

// CLASA CARD
class Card
{
private:
    int numarCard[4];
    char* numeCard;
    int cvv;
    string dataExpirare;
public:
    Card();
    Card(int numarCard[4], char *numeCard, int cvv, string dataExpirare);
    Card(const Card &obj);
    Card& operator=(const Card &obj);

    int operator[](int index);
    operator int() const{return this->cvv;}
    operator string() const{return this->dataExpirare;}

    // operator << >>
    friend istream& operator>>(istream& in, Card &obj);
    friend ostream& operator<<(ostream& out, const Card &obj);

    // getter
    int *getNumarCard() {return numarCard;}
    char *getNumeCard() const {return numeCard;}
    int getCvv() const {return cvv;}
    string getDataExpirare() const {return dataExpirare;}

    // setter
    void setNumarCard(int *numarCard);
    void setNumeCard(char *numeCard);
    void setCvv(int cvv) {this->cvv = cvv;}
    void setDataExpirare(string dataExpirare) {this->dataExpirare=dataExpirare;}

    Card& operator--(); // sterge datele cardului
    Card operator--(int);

    // card + ceva - modifica datele din campul cvv si data expirare
    Card operator+(int cvv);
    Card operator+(string dataExpirare);
    friend Card operator+(int cvv,Card c);
    friend Card operator+(string dataExpirare,Card c);

    bool operator==(const Card& c);

    //destructor
    ~Card()
    {
        if (this->numeCard != NULL)
            delete[] this->numeCard;
    }
};

// PRODUSE
Produse::Produse():cod(contor++)
{
    pret = 0;
    denumire = new char[strlen("nedefinit") + 1];
    strcpy(denumire, "nedefinit");
    produsNou = false;
    marime = "nedefinita";
    material = "nedefinit";
    cout<<"constr produs\n";

}

Produse::Produse(float pret, char *denumire, bool produsNou, string marime, string material):cod(contor++)
{
    this->pret = pret;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
    this->produsNou = produsNou;
    this->marime = marime;
    this->material = material;
    cout<<"constr produs\n";

}

Produse::Produse(float pret, char *denumire):cod(contor++)
{
    this->pret = pret;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
    this->produsNou = false;
    cout<<"constr produs\n";

}

Produse::Produse(const Produse &obj):cod(obj.cod)
{
    this->pret = obj.pret;
    this->denumire = new char[strlen(obj.denumire) + 1];
    strcpy(this->denumire, obj.denumire);
    this->produsNou = obj.produsNou;
    this->material = obj.material;
    this->marime = obj.marime;
    cout<<"constr produs\n";

}

Produse& Produse::operator=(const Produse &obj)
{
    if (this != &obj)
    {
        if(this->denumire != NULL)
            delete[] this->denumire;

        this->pret = obj.pret;
        this->denumire = new char[strlen(obj.denumire) + 1];
        strcpy(this->denumire, obj.denumire);
        this->produsNou = obj.produsNou;
        this->material = obj.material;
        this->marime = obj.marime;
        cout<<"constr produs\n";

    }
    return *this;
}

void Produse::setDenumire(char *denumire)
{
    if(this->denumire != NULL)
        delete[] this->denumire;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
}


istream& Produse::citire(istream& in)
{
    if(this->denumire != NULL)
        delete[] this->denumire;

    cout<<endl;

    cout<<"Citeste pretul produsului: ";
    in>>this->pret;

    char aux[100];
    cout<<"Citeste denumirea: ";
    in.get();
    in.getline(aux, 99);
    this->denumire = new char[strlen(aux)+1];
    strcpy(this->denumire, aux);

    cout<<"Este produsul purtat? (Da/Nu) ";
    string temp;
    in>>temp;
    if (temp=="Nu")
    {this->produsNou = true;}
    else
    {this->produsNou = false;}

    cout<<"Marimea produsului: ";
    in>>this->marime;

    cout<<"Materialul produslui: ";
    //in>>this->material;
    in.get();
    getline(in, this->material);

    return in;
}

ostream& Produse::afisare(ostream& out) const
{
    out<<endl;
    out<<"Codul produsului: "<<this->cod<<endl;
    out<<"Pretul produsului: "<<this->pret<<endl;
    out<<"Denumire: "<<this->denumire<<endl;
    out<<"Stare produs: ";
    if(this->produsNou)
    {out<<"nou"<<endl;}
    else
    {out<<"purtat"<<endl;}
    out<<"Marimea produsului: "<<this->marime<<endl;
    out<<"Materialul produslui: "<<this->material<<endl;
    return out;
}

istream& operator>>(istream& in, Produse &obj)
{
    return obj.citire(in);
}

ostream& operator<<(ostream& out, const Produse &obj)
{
    return obj.afisare(out);
}


// operatori matematici +/- pentru scumpire/ieftinire pret
Produse Produse::operator+(float scumpire)
{
    Produse prod = *this;
    prod.pret = prod.pret+scumpire;
    return prod;
}

Produse Produse::operator-(float ieftinire)
{
    Produse prod = *this;
    if(prod.pret >= ieftinire)
        prod.pret = prod.pret-ieftinire;
    return prod;
}

Produse operator+(float scumpire,Produse prod)
{
    prod.pret = scumpire+prod.pret;
    return prod;
}

Produse operator-(float ieftinire,Produse prod)
{
    if(prod.pret >= ieftinire)
        prod.pret = -1*ieftinire + prod.pret;
    return prod;
}


// operator conditional
bool Produse::operator<(const Produse& p1)
{
    if (this->pret<p1.pret)
        return true;
    return false;
}

bool Produse::operator>(const Produse& p1)
{
    if (this->pret>p1.pret)
        return true;
    return false;
}

// operator ==
bool Produse::operator==(const Produse& p1)
{
    if (this->cod==p1.cod || strcmp(this->denumire,p1.denumire)==0)
        return true;
    return false;
}

void Produse::aplicaPromotie(string voucher)
{
    if (voucher == "Black Friday")
        this->pret = this->pret/2;
    else if (voucher == "Birthday Promotion")
        this->pret = this->pret - this->pret/5;
    else if (voucher == "other")
        this->pret = this->pret - this->pret/10;
}

void Produse::afiseazaProdusInCos() const
{
    cout<<endl;
    cout<<"Codul produsului: "<<this->cod<<endl;
    cout<<"Pretul produsului: "<<this->pret<<endl;
    cout<<"Denumire: "<<this->denumire<<endl;
    cout<<"Stare produs: ";
    if(this->produsNou)
    {cout<<"nou"<<endl;}
    else
    {cout<<"purtat"<<endl;}
    cout<<"Marimea produsului: "<<this->marime<<endl;
    cout<<"Materialul produslui: "<<this->material<<endl;
}

//Bluza
//CD
Bluza::Bluza():Produse()
{
    this->lungimeManeca = "N/A";
    this->culoareBluza = "N/A";
    cout<<"constr bluza\n";
}

//CP toti
Bluza::Bluza(float pret, char *denumire, bool produsNou,string marime, string material,string lungimeManeca, string culoareBluza):Produse(pret,denumire,produsNou,marime,material)
{
    this->lungimeManeca = lungimeManeca;
    this->culoareBluza = culoareBluza;
    cout<<"constr bluza\n";

}

//CC
Bluza::Bluza(const Bluza& obj):Produse(obj)
{
    this->lungimeManeca = obj.lungimeManeca;
    this->culoareBluza = obj.culoareBluza;
    cout<<"constr bluza\n";

}

//Op=
Bluza& Bluza::operator=(const Bluza &obj)
{
    if(this!=&obj)
    {
        Produse::operator=(obj);
        this->lungimeManeca = obj.lungimeManeca;
        this->culoareBluza = obj.culoareBluza;
        cout<<"constr bluza\n";

    }
    return *this;
}


istream& Bluza::citire(istream& in)
{
    this->Produse::citire(in);
    cout<<"Lungimea manecii: ";
    in>>this->lungimeManeca;
    cout<<"Culoarea bluzei: ";
    in>>this->culoareBluza;

    return in;
}

ostream& Bluza::afisare(ostream& out) const
{
    this->Produse::afisare(out);
    out<<"Lungimea manecii: "<<this->lungimeManeca<<endl;
    out<<"Culoarea bluzei: "<<this->culoareBluza<<endl;
    return out;
}

//Op>>
istream& operator>>(istream&in, Bluza &obj)
{
    return obj.citire(in);
}
//Op<<
ostream& operator<<(ostream& out, const Bluza &obj)
{
    return obj.afisare(out);
}

void Bluza::afiseazaProdusInCos() const
{
    this->Produse::afisare(cout);
    cout<<"Lungimea manecii: "<<this->lungimeManeca<<endl;
    cout<<"Culoarea bluzei: "<<this->culoareBluza<<endl;
}

//Fusta
//CD
Fusta::Fusta():Produse()
{
    this->lungimeFusta = "nedefinita";
    this->culoareFusta = "nedefinita";
    cout<<"constr fusta\n";
}

//CP toti
Fusta::Fusta(float pret, char *denumire, bool produsNou,string marime, string material, string lungimeFusta, string culoareFusta):Produse(pret,denumire,produsNou,marime, material)
{
    this->lungimeFusta = lungimeFusta;
    this->culoareFusta = culoareFusta;
    cout<<"constr fusta\n";
}

//CC
Fusta::Fusta(const Fusta& obj):Produse(obj)
{
    this->lungimeFusta = obj.lungimeFusta;
    this->culoareFusta = obj.culoareFusta;
    cout<<"constr fusta\n";
}

//Op=
Fusta& Fusta::operator=(const Fusta &obj)
{
    if(this!=&obj)
    {
        Produse::operator=(obj);
        this->lungimeFusta = obj.lungimeFusta;
        this->culoareFusta = obj.culoareFusta;
        cout<<"constr fusta\n";
    }
    return *this;
}


istream& Fusta::citire(istream& in)
{
    this->Produse::citire(in);
    cout<<"Lungimea fustei: ";
    in>>this->lungimeFusta;
    cout<<"Culoarea fustei: ";
    in>>this->culoareFusta;
    return in;
}

ostream& Fusta::afisare(ostream& out) const
{
    this->Produse::afisare(out);
    out<<"Lungimea fustei: "<<this->lungimeFusta<<endl;
    out<<"Culoarea fustei: "<<this->culoareFusta<<endl;
    return out;
}
//Op>>
istream& operator>>(istream&in, Fusta &obj)
{
    return obj.citire(in);
}
//Op<<
ostream& operator<<(ostream& out, const Fusta &obj)
{
    return obj.afisare(out);
}

void Fusta::afiseazaProdusInCos() const
{
    this->Produse::afisare(cout);
    cout<<"Lungimea fustei: "<<this->lungimeFusta<<endl;
    cout<<"Culoarea fustei: "<<this->culoareFusta<<endl;
}

//Pantaloni
//CD
Pantaloni::Pantaloni():Produse()
{
    this->lungimePantaloni = "nedefinita";
    this->culoarePantaloni = "nedefinita";
}

//CP toti
Pantaloni::Pantaloni(float pret, char *denumire, bool produsNou,string marime, string material, string lungimePantaloni, string culoarePantaloni):Produse(pret,denumire,produsNou,marime, material)
{
    this->lungimePantaloni = lungimePantaloni;
    this->culoarePantaloni = culoarePantaloni;
}

//CC
Pantaloni::Pantaloni(const Pantaloni& obj):Produse(obj)
{
    this->lungimePantaloni = obj.lungimePantaloni;
    this->culoarePantaloni = obj.culoarePantaloni;
}

//Op=
Pantaloni& Pantaloni::operator=(const Pantaloni &obj)
{
    if(this!=&obj)
    {
        Produse::operator=(obj);
        this->lungimePantaloni = obj.lungimePantaloni;
        this->culoarePantaloni = obj.culoarePantaloni;
    }
    return *this;
}


istream& Pantaloni::citire(istream& in)
{
    this->Produse::citire(in);
    cout<<"Lungimea pantalonilor: ";
    in>>this->lungimePantaloni;
    cout<<"Culoarea pantalonilor: ";
    in>>this->culoarePantaloni;
    return in;
}

ostream& Pantaloni::afisare(ostream& out) const
{
    this->Produse::afisare(out);
    out<<"Lungimea pantalonilor: "<<this->lungimePantaloni<<endl;
    out<<"Lungimea pantalonilor: "<<this->culoarePantaloni<<endl;
    return out;
}
//Op>>
istream& operator>>(istream&in, Pantaloni &obj)
{
    return obj.citire(in);
}
//Op<<
ostream& operator<<(ostream& out, const Pantaloni &obj)
{
    return obj.afisare(out);
}

void Pantaloni::afiseazaProdusInCos() const
{
    this->Produse::afisare(cout);
    cout<<"Lungimea pantalonilor: "<<this->lungimePantaloni<<endl;
    cout<<"Lungimea pantalonilor: "<<this->culoarePantaloni<<endl;
}

// Rochie
//CD
Rochie::Rochie()
{
    cout<<"Constr rochie\n";
}
//CP
Rochie::Rochie(float pret, char *denumire, bool produsNou,string marime, string material,
               string lungimeManeca, string culoareBluza,string lungimeFusta, string culoareFusta ):
        Bluza(pret, denumire, produsNou,marime, material,lungimeManeca,culoareBluza),
        Fusta(pret, denumire, produsNou,marime, material,lungimeFusta,culoareFusta)
{
    this->lungimeFusta = lungimeFusta;
    this->culoareFusta = culoareFusta;
    cout<<"Constr rochie\n";
}

//CC
Rochie::Rochie(const Rochie& obj):Bluza(obj)
{
    this->lungimeFusta = obj.lungimeFusta;
    this->culoareFusta = obj.culoareFusta;
    cout<<"Constr rochie\n";
}

//Op=
Rochie& Rochie::operator=(const Rochie &obj)
{
    if(this!=&obj)
    {
        Bluza::operator=(obj);
        this->lungimeFusta = obj.lungimeFusta;
        this->culoareFusta = obj.culoareFusta;
        cout<<"Constr rochie\n";
    }
    return *this;
}

istream& Rochie::citire(istream& in)
{
    this->Bluza::citire(in);
    cout<<"Lungimea fustei: ";
    in>>this->lungimeFusta;
    cout<<"Culoarea fustei: ";
    in>>this->culoareFusta;
    return in;
}
ostream& Rochie::afisare(ostream& out) const
{
    this->Bluza::afisare(out);
    out<<"Lungimea fustei: "<<this->lungimeFusta<<endl;
    out<<"Culoarea fustei: "<<this->culoareFusta<<endl;
    out<<endl;
    return out;
}

//Op>>
istream& operator>>(istream&in, Rochie &obj)
{
    return obj.citire(in);
}
//Op<<
ostream& operator<<(ostream& out, const Rochie &obj)
{
    return obj.afisare(out);
}


Produse Rochie::creeazaRochie(Bluza bluza, Fusta fusta)
{
    char* aux = new char[strlen("rochie personalizata")+1];
    strcpy(aux, "rochie personalizata");
    Rochie r(fusta.getPret()+bluza.getPret(),aux,bluza.getStareProdus()||fusta.getStareProdus(),bluza.getMarime(),bluza.getMaterial(),
             bluza.getLungimeManeca(),bluza.getCuloareBluza(),fusta.getLungimeFusta(),fusta.getCuloareFusta());
    delete[] aux;
    return r;
}



void Rochie::afiseazaProdusInCos() const
{
    this->Bluza::afisare(cout);
    cout<<"Lungimea fustei: "<<this->lungimeFusta<<endl;
    cout<<"Culoarea fustei: "<<this->culoareFusta<<endl;
    cout<<endl;
}

// UTILIZATOR
Utilizator::Utilizator()
{
    idUtilizator = "nume@adresa_mail.com";
    nume = new char[strlen("nedefinit") + 1];
    strcpy(nume, "nedefinit");
    numarTelefon = 700000000;
    adresa = "nedefinita";
    gen = 'O';
}

Utilizator::Utilizator(string idUtilizator, char *nume, long numarTelefon, string adresa, char gen)
{
    this->idUtilizator = idUtilizator;
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->numarTelefon = numarTelefon;
    this->adresa = adresa;
    this->gen = gen;
}

Utilizator::Utilizator(string idUtilizator, char *nume):numarTelefon(700000000),adresa("nedefinita"),gen('O')
{
    this->idUtilizator = idUtilizator;
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);

}

Utilizator::Utilizator(string idUtilizator):numarTelefon(700000000),adresa("nedefinita"),gen('O')
{
    this->idUtilizator = idUtilizator;
    this->nume = new char[strlen("nedefinit")+1];
    strcpy(this->nume,"nedefinit");
}

Utilizator::Utilizator(const Utilizator &obj)
{
    this->idUtilizator = obj.idUtilizator;
    this->nume = new char[strlen(obj.nume)+1];
    strcpy(this->nume, obj.nume);
    this->numarTelefon = obj.numarTelefon;
    this->adresa = obj.adresa;
    this->gen = obj.gen;
}

Utilizator& Utilizator::operator=(const Utilizator &obj)
{
    if(this != &obj)
    {
        if(this->nume != NULL)
            delete[] this->nume;

        this->idUtilizator = obj.idUtilizator;
        this->nume = new char[strlen(obj.nume)+1];
        strcpy(this->nume, obj.nume);
        this->numarTelefon = obj.numarTelefon;
        this->adresa = obj.adresa;
        this->gen = obj.gen;
    }
    return *this;
}

istream& operator>>(istream& in, Utilizator &obj)
{
    if(obj.nume != NULL)
        delete[] obj.nume;
    cout<<endl;
    cout<<"Citeste ID utilizator (email/id unic): ";
    in>>obj.idUtilizator;

    char aux[100];
    cout<<"Citeste nume complet: ";
    in.get();
    in.getline(aux, 99);
    obj.nume = new char[strlen(aux)+1];
    strcpy(obj.nume, aux);

    cout<<"Citeste numarul de telefon (de tipul 7xx..): +40";
    in>>obj.numarTelefon;

    cout<<"Citeste adresa: ";
    in.get();
    getline(in, obj.adresa);

    cout<<"Citeste genul (F/M/O): ";
    in>>obj.gen;

    return in;
}

ostream& operator<<(ostream& out, const Utilizator &obj)
{
    out<<endl;
    out<<"ID utilizator: "<<obj.idUtilizator<<endl;
    out<<"Nume complet: "<<obj.nume<<endl;
    out<<"Numar de telefon: +40"<<obj.numarTelefon<<endl;
    out<<"Adresa: "<<obj.adresa<<endl;
    out<<"Genul: "<<obj.gen<<endl;
    out<<endl;
    return out;
}

void Utilizator::citire()
{
    if(this->nume != NULL)
        delete[] this->nume;

    cout<<endl;
    cout<<"Citeste ID utilizator (email/id unic): ";
    cin.get();
    getline(cin, this->idUtilizator);

    char aux[100];
    cout<<"Citeste nume complet: ";
    cin.get();
    cin.getline(aux, 99);
    this->nume = new char[strlen(aux)+1];
    strcpy(this->nume, aux);

    cout<<"Citeste numarul de telefon (de tipul 7xx..): +40";
    cin>>this->numarTelefon;

    cout<<"Citeste adresa: ";
    cin.get();
    getline(cin, this->adresa);

    cout<<"Citeste genul (F/M/O): ";
    cin>>this->gen;

}

void Utilizator::afisare()
{
    cout<<endl;
    cout<<"ID utilizator: "<<this->idUtilizator<<endl;
    cout<<"Adresa: "<<this->adresa<<endl;

}


// +/- adauga adresa noua
Utilizator Utilizator::operator+(string adresaNoua)
{
    Utilizator persoana = *this;
    persoana.adresa = persoana.adresa+" / "+adresaNoua;
    return persoana;
}
Utilizator operator+(string adresaNoua, Utilizator persoana)
{
    persoana.adresa = adresaNoua+" / "+persoana.adresa;
    return persoana;
}

// scaderea numarului de telefon - se sterge din profil
Utilizator Utilizator::operator-(long nrTelefon)
{
    Utilizator persoana = *this;
    persoana.numarTelefon = persoana.numarTelefon-nrTelefon;
    return persoana;
}
Utilizator operator-(long nrTelefon, Utilizator persoana)
{
    persoana.numarTelefon = nrTelefon - persoana.numarTelefon;
    return persoana;
}



// operator conditional - luati in ordine alfabetica crescatoare in functie de idUtilizator
bool Utilizator::operator>(const Utilizator& persoana)
{
    if(this->idUtilizator>persoana.idUtilizator)
        return true;
    return false;
}

// operator ==
bool Utilizator::operator==(const Utilizator& persoana)
{
    if(this->idUtilizator == persoana.idUtilizator)
        return true;
    return false;
}


// COS CUMPARATURI
CosCumparaturi::CosCumparaturi()
{
    Utilizator client;
    numarProduse = 0;
    total = 0;
}

CosCumparaturi::CosCumparaturi(Utilizator client,int numarProduse, vector <Produse*> listaProduse, double total)
{
    this->client = client;
    this->numarProduse = numarProduse;
    for (int i = 0; i<numarProduse; i++)
    {
        this->listaProduse[i] = listaProduse[i];
    }

    this->total = total;
}

CosCumparaturi::CosCumparaturi(Utilizator client,int numarProduse,  vector <Produse*> listaProduse)
{
    this->client = client;
    this->numarProduse = numarProduse;
    float suma = 0;
    for (int i = 0; i<numarProduse; i++)
    {
        this->listaProduse[i] = listaProduse[i];
        suma = suma + static_cast<Produse&> (*listaProduse[i]).getPret();
    }
    this->total = suma;
}

CosCumparaturi::CosCumparaturi(Utilizator client)
{
    this->client = client;
    numarProduse = 0;
    total = 0;
}

CosCumparaturi::CosCumparaturi(const CosCumparaturi &obj)
{
    this->client = obj.client;
    this->numarProduse = obj.numarProduse;
    for (int i = 0; i<obj.numarProduse; i++)
        this->listaProduse[i] = obj.listaProduse[i];
    this->total = obj.total;
}

CosCumparaturi& CosCumparaturi::operator=(const CosCumparaturi &obj)
{
    if(this != &obj)
    {

        this->client = obj.client;
        this->numarProduse = obj.numarProduse;
        for (int i = 0; i<obj.numarProduse; i++)
            this->listaProduse[i] = obj.listaProduse[i];
        this->total = obj.total;
    }
    return *this;
}

istream& operator>>(istream& in, CosCumparaturi &obj)
{
    cout<<endl;
    cout<<"Citeste utilizatorul: ";
    in>>obj.client;

    cout<<"Citeste numar de produse din cos: ";
    in>>obj.numarProduse;


    cout<<"Citeste totalul de platit: ";
    in>>obj.total;

    return in;
}

ostream& operator<<(ostream& out, const CosCumparaturi &obj)
{
    out<<endl;
    out<<"Numarul de produse din cos: "<<obj.numarProduse<<endl;
    out<<"Produsele din cos ";
    for(int i = 0; i<obj.numarProduse; i++)
    {
        out<<endl;
        out<<"Produsul "<<i+1<<" ";
        //obj.listaProduse[i].afisare();
        //out<<obj.listaProduse[i];
        obj.listaProduse[i]->afiseazaProdusInCos();
    }

    out<<"Pret total: "<<obj.total<<endl;
    return out;
}

void CosCumparaturi::citire()
{
    cout<<endl;

    cout<<"Citeste utilizatorul: ";
    cin>>this->client;

    cout<<"Citeste numar de produse din cos: ";
    cin>>this->numarProduse;


    cout<<"Citeste totalul de platit: ";
    cin>>this->total;
}

void  CosCumparaturi::afisare()
{
    cout<<"Cosul utilizatorului "<<this->client<<endl;
    cout<<endl;
    cout<<"Numarul de produse din cos: "<<this->numarProduse<<endl;
    cout<<"Produsele din cos: ";
    for(int i = 0; i<this->numarProduse; i++)
    {
        cout<<endl;
        cout<<"Produsul "<<i+1<<" ";
        cout<<this->listaProduse[i];
    }
    cout<<"Pret total: "<<this->total<<endl;
}


// goleste cosul
void CosCumparaturi::golireCos()
{
    CosCumparaturi aux;
    *this = aux;
}

//opertor> - in functie de pret
bool CosCumparaturi::operator>(const CosCumparaturi& cos)
{
    if(this->numarProduse>cos.numarProduse)
        return true;
    return false;
}


void CosCumparaturi::adaugaProdusInCos(Produse* p)
{
    this->listaProduse.push_back(p);
    this->numarProduse++;
    this->total = this->total + (*p).getPret();
}

void CosCumparaturi::stergeProdusDinCos(int i)
{
    if (i<this->listaProduse.size())
    {
        this->total -= this->listaProduse[i]->getPret();
        this->listaProduse.erase(this->listaProduse.begin()+i);
        this->numarProduse--;
    }
}

Produse* CosCumparaturi::adaugaProdusDinCos(int i)
{
    Produse* aux = this->listaProduse[i];
    return aux;
}

// CARD
Card::Card()
{
    for(int i = 0;i<4;i++)
        numarCard[i] = 1111;
    numeCard = new char[strlen("anonim"+1)];
    strcpy(numeCard,"anonim");
    cvv = 0;
    dataExpirare = "00/00";
}

Card::Card(int numarCard[4], char *numeCard, int cvv, string dataExpirare)
{
    for(int i = 0;i<4;i++)
        this->numarCard[i] = numarCard[i];
    this->numeCard = new char[strlen(numeCard+1)];
    strcpy(this->numeCard,numeCard);
    this->cvv = cvv;
    this->dataExpirare = dataExpirare;
}

Card::Card(const Card &obj)
{
    for(int i = 0;i<4;i++)
        this->numarCard[i] = obj.numarCard[i];
    this->numeCard = new char[strlen(obj.numeCard)+1];
    strcpy(this->numeCard,obj.numeCard);
    this->cvv = obj.cvv;
    this->dataExpirare = obj.dataExpirare;
    cout<<"Copy constructor"<<endl;
}

Card& Card::operator=(const Card &obj)
{
    if(this!=&obj)
    {
        if (this->numeCard != NULL)
            delete[] this->numeCard;

        for(int i = 0; i<4; i++)
            this->numarCard[i] = obj.numarCard[i];
        this->numeCard = new char[strlen(numeCard+1)];
        strcpy(this->numeCard,obj.numeCard);
        this->cvv = obj.cvv;
        this->dataExpirare = obj.dataExpirare;
    }

    return *this;
}

int Card::operator[](int index)
{
    if(index >= 0 && index < 4)
        return this->numarCard[index];
    throw runtime_error("Index invalid.");
}

istream& operator>>(istream& in, Card &obj)
{
    if (obj.numeCard != NULL)
        delete[] obj.numeCard;

    cout<<endl;
    cout<<"Citeste numarul cardului (cate 4 cifre): ";
    for(int i = 0; i<4; i++)
    {
        in>>obj.numarCard[i];
    }

    char aux[100];
    cout<<"Citeste numele de pe card: ";
    in.get();
    in.getline(aux, 99);
    obj.numeCard=new char[strlen(aux) + 1];
    strcpy(obj.numeCard, aux);

    cout<<"Citeste CVV: ";
    in>>obj.cvv;

    cout<<"Citeste data de expirare (format mm/yy): ";
    in>>obj.dataExpirare;

    return in;
}

ostream& operator<<(ostream& out, const Card &obj)
{
    out<<endl;
    out<<"Numarul cardului este: ";
    for(int i = 0; i<4; i++)
        out<<obj.numarCard[i]<<" ";
    out<<endl<<"Numele de pe card este: "<<obj.numeCard<<endl;;
    out<<"Codul CVV este: "<<obj.cvv<<endl;
    out<<"Data de expirare este: "<<obj.dataExpirare<<endl;
    return out;
}

void Card::setNumarCard(int *numarCard)
{
    for(int i = 0; i<4; i++)
        this->numarCard[i] = numarCard[i];
}

void Card::setNumeCard(char *numeCard)
{
    if(this->numeCard != NULL)
        delete[] this->numeCard;
    this->numeCard = new char[strlen(numeCard+1)];
    strcpy(this->numeCard,numeCard);
}

Card& Card::operator--()
{
    // sterge datele cardului
    Card aux;
    *this = aux;
    return *this;
}

Card Card::operator--(int)
{
    Card aux = *this;
    --(*this);
    return aux;
}

// card + ceva - modifica datele din campul cvv si data expirare
Card Card::operator+(int cvv)
{
    this->cvv=cvv;
    return *this;
}

Card Card::operator+(string dataExpirare)
{
    this->dataExpirare=dataExpirare;
    return *this;
}

Card operator+(int cvv,Card c)
{
    c.cvv=cvv;
    return c;
}

Card operator+(string dataExpirare,Card c)
{
    c.dataExpirare=dataExpirare;
    return c;
}

bool Card::operator==(const Card& c)
{
    for(int i=0;i<4;i++)
        if(this->numarCard[i] != c.numarCard[i])
            return false;
    return true;
}


// Contorul static pentru codProdus din clasa Produse
int Produse::contor = 10000;

int main()
{

    Rochie r;
    char* denumire = new char (strlen("den")+1);
    strcpy(denumire, "den");

    Rochie r1(10,denumire,true, "M", "bumbac", "scurta", "alba", "scurta", "alba");

    cout<<r;


    vector<Produse*> toateProdusele;
    vector<Utilizator> utilizatori;
    CosCumparaturi cos;


    cout<<"\n------------------ Bine ati venit! ------------------\n";
    int k=1;
    while(k==1)
    {

        cout<<"Apasa 1 pentru a adauga un produs"<<endl;
        cout<<"Apasa 2 pentru a afisa produsele disponibile"<<endl;
        cout<<"Produsele disponibile nu vi se potrivesc? \nApasa 3 pentru a modifica un produs"<<endl;
        cout<<"Apasa 4 pentru a va inregistra"<<endl;
        cout<<"Apasa 5 pentru a vizualiza contul"<<endl;
        cout<<"Apasa 6 pentru a adauga un produs in cosul de cumparaturi"<<endl;
        cout<<"Apasa 7 pentru a elimina un produs din cosul de cumparaturi"<<endl;
        cout<<"Apasa 8 pentru a vizualiza cosul de cumparaturi"<<endl;
        cout<<"Apasa 9 pentru a finaliza comanda"<<endl;
        cout<<"Apasa 10 pentru a iesi"<<endl;
        int comanda;
        cin>>comanda;
        switch(comanda)
        {
            case 1:
            {
                // citeste un produs si il adauga in lista de produse
                int k2=1;
                while (k2==1)
                {
                    cout<<"Apasa 1 pentru a adauga o bluza\n";
                    cout<<"Apasa 2 pentru a adauga o fusta\n";
                    cout<<"Apads 3 pentru a adauga o pereche de pantaloni\n";
                    cout<<"Apasa 4 pentru a adauga o rochie\n";
                    cout<<"Apasa 5 pentru a te intoarce la meniul principal\n";


                    int comanda2;
                    cin>>comanda2;
                    switch(comanda2)
                    {
                        case 1:
                        {
                            toateProdusele.push_back(new Bluza);
                            cin>>*toateProdusele.back();
                            break;
                        }
                        case 2:
                        {
                            toateProdusele.push_back(new Fusta);
                            cin>>*toateProdusele.back();
                            break;
                        }
                        case 3:
                        {
                            toateProdusele.push_back(new Pantaloni);
                            cin>>*toateProdusele.back();
                            break;
                        }
                        case 4:
                        {
                            toateProdusele.push_back(new Rochie);
                            cin>>*toateProdusele.back();
                            break;
                        }
                        case 5:
                        {
                            k2 = 0;
                            break;
                        }
                    }

                }

                cout<<endl;
                break;
            }
            case 2:
            {
                // afisarea produselor
                int k2=1;
                while (k2==1)
                {
                    cout<<"Apasa 1 pentru a afisa toate produsele\n";
                    cout<<"Apasa 2 pentru a afisa toate bluzele disponibile\n";
                    cout<<"Apads 3 pentru a afisa toate fustele disponibile\n";
                    cout<<"Apads 4 pentru a afisa toti pantalonii disponibili\n";
                    cout<<"Apasa 5 pentru a afisa toate rochiile disponibile\n";
                    cout<<"Apasa 6 pentru a te intoarce la meniul principal\n";

                    int comanda2;
                    cin>>comanda2;
                    switch(comanda2)
                    {
                        case 1:
                        {
                            if (toateProdusele.size()>0)
                            {
                                for(int i=0;i<toateProdusele.size();i++)
                                {
                                    cout<<endl;
                                    cout<<"Produsul "<<i+1;
                                    cout<<*toateProdusele[i];
                                }
                            }
                            else
                                cout<<"Moment nu sunt produse disponibile\n";
                            cout<<endl;
                            break;
                        }
                        case 2:
                        {
                            int ok = 0;
                            if (toateProdusele.size()>0) {
                                for (int i = 0; i < toateProdusele.size(); i++) {
                                    if (typeid(Bluza) == typeid(*toateProdusele[i])) {
                                        cout << endl;
                                        cout << "Produsul " << i + 1;
                                        cout << *toateProdusele[i];
                                        ok = 1;
                                    }
                                }
                                if (ok == 0)
                                    cout << "Moment nu sunt bluze disponibile\n";
                            }
                            cout<<endl;
                            break;
                        }
                        case 3:
                        {
                            int ok = 0;
                            if (toateProdusele.size()>0) {
                                for (int i = 0; i < toateProdusele.size(); i++) {
                                    if (typeid(Fusta) == typeid(*toateProdusele[i])) {
                                        cout << endl;
                                        cout << "Produsul " << i + 1;
                                        cout << *toateProdusele[i];
                                        ok = 1;
                                    }
                                }
                                if (ok == 0)
                                    cout << "Moment nu sunt fuste disponibile\n";
                            }
                            cout<<endl;
                            break;
                        }
                        case 4:
                        {
                            int ok = 0;
                            if (toateProdusele.size()>0) {
                                for (int i = 0; i < toateProdusele.size(); i++) {
                                    if (typeid(Pantaloni) == typeid(*toateProdusele[i])) {
                                        cout << endl;
                                        cout << "Produsul " << i + 1;
                                        cout << *toateProdusele[i];
                                        ok = 1;
                                    }
                                }
                                if (ok == 0)
                                    cout << "Moment nu sunt pantaloni disponibili\n";
                            }
                            cout<<endl;
                            break;
                        }
                        case 5:
                        {
                            int ok = 0;
                            if (toateProdusele.size()>0) {
                                for (int i = 0; i < toateProdusele.size(); i++) {
                                    if (typeid(Rochie) == typeid(*toateProdusele[i])) {
                                        cout << endl;
                                        cout << "Produsul " << i + 1;
                                        cout << *toateProdusele[i];
                                        ok = 1;
                                    }
                                }
                                if (ok == 0)
                                    cout << "Moment nu sunt rochii disponibile\n";
                            }
                            cout<<endl;
                            break;
                        }
                        case 6:
                        {
                            k2 = 0;
                            break;
                        }
                    }

                }

                cout<<endl;
                break;
            }
            case 3:
            {
                //modificare produse
                if(toateProdusele.size()>0)
                {
                    int index;
                    cout<<"Alegeti produsul pe care doriti sa il modificati (Numarul din lista de produse):\n ";
                    cin>>index;
                    while(index > toateProdusele.size())
                    {
                        cout<<"Produsul nu exista, introduceti un produs valid.\n";
                        cin>>index;
                    }
                    cout<<"Apasati 1 pentru a modifica marimea produsul in una mai mare: ";
                    cout<<"\nApasati 2 pentru a modifica marimea produsul in una mai mica:\n ";
                    int comanda;
                    cin>>comanda;
                    if (comanda == 1)
                        toateProdusele[index-1]->sizeUp();
                    else
                        toateProdusele[index-1]->sizeDown();
                }
                else
                    cout<<"Nu exista produse disponibile\n";

                cout<<endl;
                break;
            }
            case 4:
            {
                //inregistrare cu date personale - se creeaza si cosul de cumparaturi in acelasi timp
                Utilizator persoana;
                cin>>persoana;
                utilizatori.push_back(persoana);
                // am facut un vector cu utilizatorii
                cout<<endl;
                break;
            }
            case 5:
            {
                // afisarea datelor din cont
                if(utilizatori.size() > 0)
                    cout<<utilizatori[utilizatori.size()-1];
                else
                    cout<<"Nu sunteti logat in cont, apasati 4 pentru a va inregistra\n";
                cout<<endl;
                break;
            }
            case 6:
            {
                // adaugarea unui produs in cos
                cout<<"Ce produs doriti sa adaugati in cosul de cumparaturi? (Introduceti numarul din lista)\n";
                int i;
                cin>>i;
                cos.adaugaProdusInCos(toateProdusele[i-1]);
                toateProdusele.erase(toateProdusele.begin()+i-1);
                cout<<endl;
                break;
            }

            case 7:
            {
                if (cos.getNumarProduse() == 0)
                    cout<<"Cosul de cumparaturi este gol\n";
                else
                {
                    cout<<"Ce produs doriti sa eliminati din cosul de cumparaturi? (Introduceti numarul produsului din cos)\n";
                    int i;
                    cin>>i;
                    Produse* aux = cos.adaugaProdusDinCos(i-1);
                    cos.stergeProdusDinCos(i-1);
                    toateProdusele.push_back(aux);
                }

                cout<<endl;
                break;
            }
            case 8:
            {
                // afisarea cosului
                cout<<cos;
                cout<<endl;
                break;
            }
            case 9:
            {
                if (cos.getNumarProduse() == 0)
                    cout<<"Cosul de cumparaturi este gol\n";
                else
                {
                    cout<<cos;
                    cout<<"\nAdaugati un cod de promotie: \n";
                    string cod;
                    cin>>cod;

                    if (cod.substr(0,2) == "50")
                    {
                        cos.setTotal(cos.getTotal()/2);
                        cout<<"Pret nou: "<<cos.getTotal();
                        cout<<endl;
                    }
                    else if (cod.substr(0,2) == "25")
                    {
                        cos.setTotal(3*cos.getTotal()/4);
                        cout<<"Pret nou: "<<cos.getTotal();
                        cout<<endl;
                    }
                    else if (cod.substr(0,2) == "10")
                    {
                        cos.setTotal(9*cos.getTotal()/10);
                        cout<<"Pret nou: "<<cos.getTotal();
                        cout<<endl;
                    }
                    else
                    {
                        cout<<"Codul introdus nu este valabil";
                        cout<<endl;
                    }

                    Card card;
                    cout<<"Introduceti datele cardului: ";
                    cin>>card;

                    cos.golireCos();
                    cout<<"Plata a fost finalizata!"<<endl;
                }

                cout<<endl;
                break;
            }
            case 10:
            {
                cout<<"\n------------------ La revedere! ------------------\n";
                k=2;
                break;
            }
        }
    }
    return 0;
}

