#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

// clasa Produse - are setter/getter 
// clasa CosCumaraturi
// clasa Utilizator - are setter/getter
// clasa Card - are setter/getter


// CLASA PRODUSE
class Produse
{
private:
    const int cod;
    static int contor;
    float pret;
    char *denumire;
    int stoc;  //cate produse se de acest tip se afla in stoc
    int *marimiDisponibile; //marimile disponibile pentru fiecare produs din stoc
    bool produsNou; // daca produsul este nou sau purtat - ma gandeam la un magazin de tip olx sau ebay

    //contor e generat automat
public:
    // constructori
    Produse(); 
    Produse(float pret, char *denumire, int stoc, int *marimiDisponibile,bool produsNou);
    Produse(float pret, char *denumire,bool produsNou);
    Produse(float pret, char *denumire);
    Produse(const Produse &obj);
    
    Produse& operator=(const Produse &obj);
    friend istream& operator>>(istream&in, Produse &obj);
    friend ostream& operator<<(ostream& out, const Produse &obj);
    
    // operator indexare []
    int operator[](int index);

    //operator ++i
    Produse& operator++();
    // i++
    Produse operator++(int);
    // operatori matematici +/- pentru scumpire/ieftinire pret
    Produse operator+(float scumpire);
    Produse operator-(float ieftinire);
    friend Produse operator+(float scumpire,Produse prod);
    friend Produse operator-(float ieftinire,Produse prod);
    
    // operator cast
    operator int*() const{return this->marimiDisponibile;}
    operator float() const {return this->pret;}
    operator bool() const{return this->produsNou;}
    operator int() const{return this->stoc;}
    operator char*() const{return this->denumire;}

    // operator conditional
    bool operator<(const Produse& p1);
    bool operator>(const Produse& p1);
    // operator ==
    bool operator==(const Produse& p1);
    

    // getters
    static int getContor() {return contor;}
    int getCod() const {return cod;}
    float getPret() {return pret;}
    const char* getDenumire() {return denumire;}
    int getStoc() {return stoc;}  
    const int* getMarimiDisponibile() {return marimiDisponibile;}
    bool getStareProdus() {return produsNou;}

    // setters
    static void getContor(int valoare) {contor = valoare;}
    void setPret(float pret) {this->pret = pret;}
    void setDenumire(char *denumire);
    void setStoc(int stoc) {this->stoc = stoc;}
    void setMarimiDisponibile(int *marimiDisponibile);
    void setStareProdus(bool produsNou) {this->produsNou = produsNou;}


    void citire();
    void afisare();

    // destructor
    ~Produse()
    {
        if(this->denumire != NULL)
            delete[] this->denumire;
        if(this->marimiDisponibile != NULL)
            delete[] this->marimiDisponibile;
    }
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
    int nrProduseWishlist;
    Produse *wishlist;
    

public:
    Utilizator();
    Utilizator(string idUtilizator, char *nume, long numarTelefon, string adresa, char gen,int nrProduseWishlist,Produse* wishlist);
    Utilizator(string idUtilizator, char *nume);
    Utilizator(string IdUtilizator);
    Utilizator(const Utilizator &obj);
    
    Utilizator& operator=(const Utilizator &obj); 
    friend istream& operator>>(istream& in,Utilizator &obj);
    friend ostream& operator<<(ostream& out, const Utilizator &obj);

    // operator indexare 
    Produse operator[](int index);

    // cast
    operator char() const{return this->gen;}
    operator char*() const{return this->nume;}
    operator string() const{return this->idUtilizator;}

    // pentru wishlist - wishlist[i] de tip produs - adauga un produs default la final
    Utilizator& operator++();
    Utilizator operator++(int);
    
    // +/- adauga adresa noua
    Utilizator operator+(string adresaNoua);
    friend Utilizator operator+(string adresaNoua, Utilizator persoana);
    
    // scaderea numarului de telefon - se sterge din profil
    Utilizator operator-(long nrTelefon);
    friend Utilizator operator-(long nrTelefon, Utilizator persoana);


    // operatii cu clasa produse
    // wishlist = wishlist + produs
    Utilizator operator+(Produse produs);
    friend Utilizator operator+(Produse produs, Utilizator ut);

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
    void setNrProduseWishlist(int nrProduseWishlist) {this->nrProduseWishlist = nrProduseWishlist;}
    void setWishlist(Produse *Wishlist);

    //getter
    string getIdUtilizator() {return idUtilizator;}
    const char *getNume() {return nume;}
    long getNumarTelefon() {return numarTelefon;}
    string getAdresa() {return adresa;}
    char getGen() {return gen;}
    int getNrProduseWishlist() {return nrProduseWishlist;}
    const Produse *getWishlist() {return wishlist;}
        
    // metode
    void citire();
    void afisare();
    
    // destructor
    ~Utilizator()
    {
        if(this->nume != NULL)
            delete[] this->nume;
        if(this->wishlist != NULL)
            delete[] this->wishlist;
    }

};

// CLASA COS CUMPARATURI
class CosCumparaturi
{
private:
    Utilizator client;
    int numarProduse;
    Produse *listaProduse;
    double total;
    
public:
    CosCumparaturi();
    CosCumparaturi(Utilizator client,int numarProduse, Produse *listaProduse, double total);
    CosCumparaturi(Utilizator client,int numarProduse, Produse *listaProduse);
    CosCumparaturi(Utilizator client);
    CosCumparaturi(const CosCumparaturi &obj);
    
    CosCumparaturi& operator=(const CosCumparaturi &obj);
    friend istream& operator>>(istream& in, CosCumparaturi &obj);
    friend ostream& operator<<(ostream& out, const CosCumparaturi &obj);

    // operator []
    Produse operator[](int index);

    // cast
    operator int() const{return this->numarProduse;}
    operator double() const{return this->total;}
    
    // operatori matematici
    CosCumparaturi& operator++(); // se adauga un produs default la finalul listei de produse
    CosCumparaturi operator++(int);
    CosCumparaturi& operator--(); // se sterge ultimul produs din lista
    CosCumparaturi operator--(int);
    
    // + adaugi nr de produse (ex +2 adauga 2 produse default in cos)
    CosCumparaturi operator+(int nr);
    friend CosCumparaturi operator+(int nr, CosCumparaturi cos);
    // - la fel ca + doar ca le sterge
    CosCumparaturi operator-(int nr);
    friend CosCumparaturi operator-(int nr, CosCumparaturi cos);

    // operatii intre clase - se adauga/elimina un produs 
    // cos = cos + produs
    CosCumparaturi operator+(Produse produs);
    // cos = produs + cos
    friend CosCumparaturi operator+(Produse produs, CosCumparaturi cos);
    // cos = cos - produs - mai intai il cauta sa verifice ca exista in cos
    CosCumparaturi operator-(Produse produs);

    //opertor> - in functie de pret
    bool operator>(const CosCumparaturi& cos);
    
    //metode
    double getTotal() {return total;}

    void citire();
    void afisare();

    void golireCos(); // cand se efectueaza plata cosul se goleste 

    // destructor
    ~CosCumparaturi()
    {
        if(this->listaProduse != NULL)
            delete[] this->listaProduse;
    }
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
    int *getNumarCard(){return numarCard;}
    char *getNumeCard(){return numeCard;}
    int getCvv(){return cvv;}
    string getDataExpirare(){return dataExpirare;}

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
    stoc = 0;
    marimiDisponibile = NULL;
    produsNou = false;
}
    
Produse::Produse(float pret, char *denumire, int stoc, int *marimiDisponibile,bool produsNou):cod(contor++)
{
    this->pret = pret;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
    this->stoc = stoc;
    this->marimiDisponibile = new int[stoc];
    for (int i = 0; i<stoc; i++)
        this->marimiDisponibile[i] = marimiDisponibile[i];
    this->produsNou = produsNou;
}

Produse::Produse(float pret, char *denumire,bool produsNou):cod(contor++)
{
    this->pret = pret;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
    stoc = 1;
    this->marimiDisponibile = new int[stoc];
    this->marimiDisponibile[0] = -1;
    this->produsNou = produsNou;
}

Produse::Produse(float pret, char *denumire):cod(contor++)
{
    this->pret = pret;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
    stoc = 1;
    this->marimiDisponibile = new int[stoc];
    this->marimiDisponibile[0] = -1;
    this->produsNou = false;
}

Produse::Produse(const Produse &obj):cod(obj.cod)
{
    this->pret = obj.pret;
    this->denumire = new char[strlen(obj.denumire) + 1];
    strcpy(this->denumire, obj.denumire);
    this->stoc = obj.stoc;
    this->marimiDisponibile = new int[obj.stoc + 1];
    for (int i = 0; i<obj.stoc; i++)
        this->marimiDisponibile[i] = obj.marimiDisponibile[i];
    this->produsNou = obj.produsNou;
}

Produse& Produse::operator=(const Produse &obj)
{
    if (this != &obj)
    {
        if(this->denumire != NULL)
            delete[] this->denumire;
        if(this->marimiDisponibile != NULL)
            delete[] this->marimiDisponibile;

        this->pret = obj.pret;
        this->denumire = new char[strlen(obj.denumire) + 1];
        strcpy(this->denumire, obj.denumire);
        this->stoc = obj.stoc;
        this->marimiDisponibile = new int[obj.stoc + 1];
        for (int i = 0; i<obj.stoc; i++)
            this->marimiDisponibile[i] = obj.marimiDisponibile[i];
        this->produsNou = obj.produsNou;
    }
    return *this;
}

istream& operator>>(istream& in, Produse &obj)
{
    if(obj.denumire != NULL)
        delete[] obj.denumire;
    if(obj.marimiDisponibile != NULL)
        delete[] obj.marimiDisponibile;
    
    cout<<endl;

    cout<<"Citeste pretul produsului: ";
    in>>obj.pret;

    char aux[100];
    cout<<"Citeste denumirea: ";
    in.get();
    in.getline(aux, 99);
    obj.denumire = new char[strlen(aux)+1];
    strcpy(obj.denumire, aux);

    cout<<"Citeste cate articole din gama produsului sunt disponibile: ";
    in>>obj.stoc;

    cout<<"Citeste marimile articolelor: "<<endl;
    obj.marimiDisponibile = new int[obj.stoc];
    for (int i = 0; i<obj.stoc; i++)
    {
        cout<<"Articolul "<<i+1<<": ";
        in>>obj.marimiDisponibile[i];
    }

    cout<<"Este produsul purtat? ";
    string temp;
    in>>temp;
    if (temp == "Nu")
    {obj.produsNou = true;}
    else
    {obj.produsNou = false;}


    return in;
}

ostream& operator<<(ostream& out, const Produse &obj)
{
    out<<endl;
    out<<"Codul produsului: "<<obj.cod<<endl;
    out<<"Pretul produsului: "<<obj.pret<<endl;
    out<<"Denumire: "<<obj.denumire<<endl;
    out<<"Numarul de articole disponibile: "<<obj.stoc<<endl;
    out<<"Marimile disponibile: "<<endl; 
    for (int i = 0; i<obj.stoc; i++)
    {
        if(obj.marimiDisponibile[i] != -1)
            {out<<"Articolul "<<i+1<<" are marimea "<<obj.marimiDisponibile[i]<<endl;}
        else
            {out<<"Marimea nu este specificata"<<endl;}
    }
    out<<"Stare produs: ";
    if(obj.produsNou == true)
        {out<<"nou"<<endl;}
    else
        {out<<"purtat"<<endl;}
    return out;
}

void Produse::setMarimiDisponibile(int *marimiDisponibile)
{
    if(this->marimiDisponibile != NULL)
        delete[] this->marimiDisponibile;
    this->marimiDisponibile = new int[stoc + 1];
    for (int i = 0; i<this->stoc; i++)
        this->marimiDisponibile[i] = marimiDisponibile[i];
}

void Produse::setDenumire(char *denumire)
{  
    if(this->denumire != NULL)
        delete[] this->denumire;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
}

void Produse::citire()
    {
        if(this->denumire != NULL)
            delete[] this->denumire;
        if(this->marimiDisponibile != NULL)
            delete[] this->marimiDisponibile;

        cout<<endl;

        cout<<"Citeste pretul produsului: ";
        cin>>this->pret;

        char aux[100];
        cout<<"Citeste denumirea: ";
        cin.get();
        cin.getline(aux, 99);
        this->denumire = new char[strlen(aux)+1];
        strcpy(this->denumire, aux);

        cout<<"Citeste cate articole din gama produsului sunt disponibile: ";
        cin>>this->stoc;

        cout<<"Citeste marimile articolelor: "<<endl;
        this->marimiDisponibile = new int[this->stoc];
        for (int i = 0; i<this->stoc; i++)
        {
            cout<<"Articolul "<<i+1<<" ";
            cin>>this->marimiDisponibile[i];
        }

        cout<<"Este produsul purtat? (Da/Nu) ";
        string temp;
        cin>>temp;
        if (temp=="Nu")
        {this->produsNou = true;}
        else
        {this->produsNou = false;}

    }

void Produse::afisare()
    {
        cout<<endl;
        cout<<"Codul produsului: "<<this->cod<<endl;
        cout<<"Pretul produsului: "<<this->pret<<endl;
        cout<<"Denumire: "<<this->denumire<<endl;
        cout<<"Stare produs: ";
        if(this->produsNou == true)
            {cout<<"nou"<<endl;}
        else
            {cout<<"purtat"<<endl;}
        cout<<endl;
    }

//operator indexare
int Produse::operator[](int index)
    {
        if (index>=0 && index<this->stoc)
            return this->marimiDisponibile[index];
        throw runtime_error("Index invalid.");
    }

//operator ++i - adauga un articol cu marimea 0 (nespecificata) la stoc
Produse& Produse::operator++()
    {
        this->stoc++;
        int *auxMarimi = new int[this->stoc-1];
        for(int i = 0;i<this->stoc-1;i++)
            auxMarimi[i] = this->marimiDisponibile[i];
        if(this->marimiDisponibile != NULL)
            delete[] this->marimiDisponibile;
        this->marimiDisponibile = new int[this->stoc];
        for(int i=0;i<this->stoc-1;i++)
            this->marimiDisponibile[i] = auxMarimi[i];
        this->marimiDisponibile[this->stoc-1] = 0;
        if(auxMarimi != NULL)
            delete[] auxMarimi;
        return *this;
    }
// i++
Produse Produse::operator++(int)
    {
        Produse aux = *this;
        ++(*this);
        return aux;
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

// UTILIZATOR
Utilizator::Utilizator()
{
    idUtilizator = "nume@adresa_mail.com";
    nume = new char[strlen("nedefinit") + 1];
    strcpy(nume, "nedefinit");
    numarTelefon = 700000000;
    adresa = "nedefinita";
    gen = 'O';
    nrProduseWishlist = 0;
    wishlist = NULL;
}

Utilizator::Utilizator(string idUtilizator, char *nume, long numarTelefon, string adresa, char gen,int nrProduseWishlist,Produse* wishlist)
{
    this->idUtilizator = idUtilizator;
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->numarTelefon = numarTelefon;
    this->adresa = adresa;
    this->gen = gen;
    this->nrProduseWishlist = nrProduseWishlist;
    this->wishlist = new Produse[nrProduseWishlist];
    for (int i=0;i<nrProduseWishlist;i++)
        this->wishlist[i] = wishlist[i];

}

Utilizator::Utilizator(string idUtilizator, char *nume):numarTelefon(700000000),adresa("nedefinita"),gen('O'),nrProduseWishlist(0)
{
    this->idUtilizator = idUtilizator;
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    wishlist = NULL;
    
}

Utilizator::Utilizator(string idUtilizator):numarTelefon(700000000),adresa("nedefinita"),gen('O'),nrProduseWishlist(0)
{
    this->idUtilizator = idUtilizator;
    this->nume = new char[strlen("nedefinit")+1];
    strcpy(this->nume,"nedefinit");
    wishlist = NULL;
}

Utilizator::Utilizator(const Utilizator &obj)
{
    this->idUtilizator = obj.idUtilizator;
    this->nume = new char[strlen(obj.nume)+1];
    strcpy(this->nume, obj.nume);
    this->numarTelefon = obj.numarTelefon;
    this->adresa = obj.adresa;
    this->gen = obj.gen;
    this->nrProduseWishlist = obj.nrProduseWishlist;
    this->wishlist = new Produse[obj.nrProduseWishlist];
    for (int i=0;i<obj.nrProduseWishlist;i++)
        this->wishlist[i] = obj.wishlist[i];
}

Utilizator& Utilizator::operator=(const Utilizator &obj)
    {
        if(this != &obj)
        {
            if(this->nume != NULL)
                delete[] this->nume;
            if (this->wishlist != NULL)
                delete[] this->wishlist;
            
            this->idUtilizator = obj.idUtilizator;
            this->nume = new char[strlen(obj.nume)+1];
            strcpy(this->nume, obj.nume);
            this->numarTelefon = obj.numarTelefon;
            this->adresa = obj.adresa;
            this->gen = obj.gen;
            this->nrProduseWishlist = obj.nrProduseWishlist;
            this->wishlist = new Produse[obj.nrProduseWishlist];
            for (int i=0;i<obj.nrProduseWishlist;i++)
                this->wishlist[i] = obj.wishlist[i];
        }
        return *this;
    } 

istream& operator>>(istream& in, Utilizator &obj)
{
    if(obj.nume != NULL)
        delete[] obj.nume;
    if (obj.wishlist != NULL)
        delete[] obj.wishlist;
    
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
    out<<"Numarul de produse din wishlist: "<<obj.nrProduseWishlist<<endl;
    for(int i = 0;i<obj.nrProduseWishlist;i++)
    {
        out<<"Produsul "<<i+1<<": ";
        obj.wishlist[i].afisare();
        //out<<obj.wishlist[i];
    }
    out<<endl;
    return out;
}

void Utilizator::citire()
    {
        if(this->nume != NULL)
            delete[] this->nume;
        if (this->wishlist != NULL)
            delete[] this->wishlist;
    
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

void Utilizator::setWishlist(Produse *Wishlist)
{
    if (this->wishlist != NULL)
        delete[] this->wishlist;
    this->wishlist = new Produse[this->nrProduseWishlist];
    for(int i=0; i<this->nrProduseWishlist;i++)
        this->wishlist[i] = wishlist[i];
}


Produse Utilizator::operator[](int index)
    {
        if (index>=0 && index<this->nrProduseWishlist)
            return this->wishlist[index];
        throw runtime_error("Index invalid.");
    }

// pentru wishlist - wishlist[i] de tip produs
Utilizator& Utilizator::operator++()
    {
        this->nrProduseWishlist++;
        Produse *auxWishlist = new Produse[this->nrProduseWishlist-1];
        for(int i = 0;i<this->nrProduseWishlist-1;i++)
            auxWishlist[i] = this->wishlist[i];
        if(this->wishlist != NULL)
            delete[] wishlist;
        this->wishlist = new Produse[this->nrProduseWishlist];
        for(int i = 0;i<this->nrProduseWishlist-1;i++)
            this->wishlist[i] = auxWishlist[i];
        Produse prod;
        this->wishlist[this->nrProduseWishlist-1] = prod;
        if(auxWishlist != NULL)
            delete[] auxWishlist;
        return *this;
    }
Utilizator Utilizator::operator++(int)
    {
        Utilizator auxUtilizator = *this;
        ++(*this);
        return auxUtilizator;
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

// operatii cu clasa produse
// wishlist = wishlist + produs - adauga un produs in wishlist
Utilizator Utilizator::operator+(Produse produs)
    {
        Utilizator ut = *this;
        ut++;
        ut.wishlist[ut.nrProduseWishlist-1] = produs;
        return ut;
    }

// wishlist = wishlist + cos
Utilizator operator+(Produse produs, Utilizator ut)
{
    ut = ut + produs;
    return ut;
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
    listaProduse = NULL;
    total = 0;
}

CosCumparaturi::CosCumparaturi(Utilizator client,int numarProduse, Produse *listaProduse, double total)
{
    this->client = client;
    this->numarProduse = numarProduse;
    this->listaProduse = new Produse[numarProduse];
    for (int i = 0; i<numarProduse; i++)
        this->listaProduse[i] = listaProduse[i];
    this->total = total;
}

CosCumparaturi::CosCumparaturi(Utilizator client,int numarProduse, Produse *listaProduse)
    {
        this->client = client;
        this->numarProduse = numarProduse;
        this->listaProduse = new Produse[numarProduse];
        float suma = 0;
        for (int i = 0; i<numarProduse; i++)
        {
            this->listaProduse[i] = listaProduse[i];
            suma = suma + listaProduse[i].getPret();
        }
        this->total = suma;
    }

CosCumparaturi::CosCumparaturi(Utilizator client)
{
    this->client = client;
    numarProduse = 0;
    listaProduse = NULL;
    total = 0;
}

CosCumparaturi::CosCumparaturi(const CosCumparaturi &obj)
{
    this->client = obj.client;
    this->numarProduse = obj.numarProduse;
    this->listaProduse = new Produse[obj.numarProduse];
    for (int i = 0; i<obj.numarProduse; i++)
        this->listaProduse[i] = obj.listaProduse[i];
    this->total = obj.total;
}

CosCumparaturi& CosCumparaturi::operator=(const CosCumparaturi &obj)
    {
        if(this != &obj)
        {
            if (this->listaProduse != NULL)
                delete[] this->listaProduse;

            this->client = obj.client;
            this->numarProduse = obj.numarProduse;
            this->listaProduse = new Produse[obj.numarProduse];
            for (int i = 0; i<obj.numarProduse; i++)
                this->listaProduse[i] = obj.listaProduse[i];
            this->total = obj.total;
        }
        return *this;
    }

istream& operator>>(istream& in, CosCumparaturi &obj)
{
    if (obj.listaProduse != NULL)
        delete[] obj.listaProduse;

    cout<<endl;
    cout<<"Citeste utilizatorul: ";
    in>>obj.client;

    cout<<"Citeste numar de produse din cos: ";
    in>>obj.numarProduse;

    cout<<"Citeste lista de produse din cos: ";
    obj.listaProduse = new Produse[obj.numarProduse];
    for(int i = 0; i<obj.numarProduse; i++)
    {
        cout<<endl;
        cout<<"Produs "<<i+1<<" ";
        in>>obj.listaProduse[i];
    }

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
        obj.listaProduse[i].afisare();
    }
    out<<"Pret total: "<<obj.total<<endl;
    return out;
}

void CosCumparaturi::citire()
    {
        if (this->listaProduse != NULL)
        delete[] this->listaProduse;

        cout<<endl;

        cout<<"Citeste utilizatorul: ";
        cin>>this->client;

        cout<<"Citeste numar de produse din cos: ";
        cin>>this->numarProduse;

        cout<<"Citeste lista de produse din cos: ";
        this->listaProduse = new Produse[this->numarProduse];
        for(int i = 0; i<this->numarProduse; i++)
        {
            cout<<endl;
            cout<<"Produs "<<i+1<<": ";
            cin>>this->listaProduse[i];
        }

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

Produse CosCumparaturi::operator[](int index)
    {
        if (index>=0 && index<this->numarProduse)
            return this->listaProduse[index];
        throw runtime_error("Index invalid.");
    }

// ++cos adauga un produs nou (gol) la finalul listei de produse
CosCumparaturi& CosCumparaturi::operator++()
    {
        this->numarProduse++;
        Produse *auxProduse = new Produse[this->numarProduse-1];
        for(int i = 0;i<this->numarProduse-1;i++)
            auxProduse[i] = this->listaProduse[i];
        if(this->listaProduse != NULL)
            delete[] listaProduse;
        this->listaProduse = new Produse[this->numarProduse];
        for(int i = 0;i<this->numarProduse-1;i++)
            this->listaProduse[i] = auxProduse[i];
        Produse prod;
        this->listaProduse[this->numarProduse-1] = prod;
        if(auxProduse != NULL)
            delete[] auxProduse;
        return *this;
    }
// cos++
CosCumparaturi CosCumparaturi::operator++(int)
    {
        CosCumparaturi auxCos = *this;
        ++(*this);
        return auxCos;
    }
// --cos sterge ultimul produs din lista de produse
CosCumparaturi& CosCumparaturi::operator--()
    {
        if (this->numarProduse > 0)
        {
            double auxPret = this->listaProduse[numarProduse-1].getPret();
            this->numarProduse--;
            
            Produse *auxProduse = new Produse[this->numarProduse];
            for(int i = 0;i<this->numarProduse;i++)
                auxProduse[i] = this->listaProduse[i];

            if(this->listaProduse != NULL)
                delete[] this->listaProduse;

            this->listaProduse = auxProduse;
            this->total = this->total - auxPret;
        }

        return *this;
    }
// cos--
CosCumparaturi CosCumparaturi::operator--(int)
    {
        CosCumparaturi auxCos = *this;
        --(*this);
        return auxCos;
    }

// + adaugi nr de produse (ex +2 adauga 2 produse goale in cos) 
CosCumparaturi CosCumparaturi::operator+(int nr)
    {
        CosCumparaturi cos = *this;
        for(int i=0;i<nr;i++)
            ++cos;
        return cos;
    }

CosCumparaturi operator+(int nr, CosCumparaturi cos)
    {
        for(int i=0;i<nr;i++)
            ++cos;
        return cos;
    }

// ca la + doar ca elimina
CosCumparaturi CosCumparaturi::operator-(int nr)
    {
        CosCumparaturi cos = *this;
        if (nr>cos.numarProduse)
            nr = cos.numarProduse;
        for(int i=0;i<nr;i++)
            --cos;
        return cos;
    }


CosCumparaturi operator-(int nr, CosCumparaturi cos)
    {
        if (nr>cos.numarProduse)
            nr = cos.numarProduse;
        for(int i=0;i<nr;i++)
            --cos;
        return cos;
    }

// goleste cosul
void CosCumparaturi::golireCos()
{
    CosCumparaturi aux;
    *this = aux;
}

// OPERATII INTRE CLASE
// cos = cos + produs - se adauga produs la finalul listei de produse
CosCumparaturi CosCumparaturi::operator+(Produse produs)
    {
        CosCumparaturi cos = *this;
        cos++;
        cos.listaProduse[cos.numarProduse-1] = produs;
        cos.total = cos.total + produs.getPret();
        return cos;
    }

// cos = produs + cos
CosCumparaturi operator+(Produse produs, CosCumparaturi cos)
{
    cos = cos + produs;
    return cos;
}

// cos = cos - produs - se sterge produs daca exista in lista de produse
CosCumparaturi CosCumparaturi::operator-(Produse produs)
{
    // cautam produsul in lista de produse
    CosCumparaturi cos = *this;
    bool ok = false;
    int index = -1;
    for(int i=0;i<cos.numarProduse;i++)
    {
        if(cos.listaProduse[i] == produs)
        {
            cout<<"ok";
            ok = true;
            index = i;
            break;
        }
    }

    if(ok)
    {
        cos.total = cos.total - cos.listaProduse[index].getPret();
        // se muta toate produsele cu o pozitie la stanga (dupa cel eliminat)
        for(int i = index;i<cos.numarProduse-1;i++)
            cos.listaProduse[i] = cos.listaProduse[i+1];
        cos.numarProduse--;
    }
    return cos;
}


//opertor> - in functie de pret
bool CosCumparaturi::operator>(const CosCumparaturi& cos)
    {
        if(this->numarProduse>cos.numarProduse)
            return true;
        return false;
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
    vector<Produse> toateProdusele;
    vector<Utilizator> utilizatori;
    vector<CosCumparaturi> cos;


    cout<<"\n------------------ Bine ati venit! ------------------\n";
    int k=1;
    while(k==1)
    {
        
        cout<<"Apasa 1 pentru a citi un produs"<<endl; 
        cout<<"Apasa 2 pentru a afisa toate produsele disponibile"<<endl;
        cout<<"Apasa 3 pentru a va inregistra"<<endl;
        cout<<"Apasa 4 pentru a vizualiza contul"<<endl;
        cout<<"Apasa 5 pentru a adauga un produs in wishlist"<<endl;
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
                    Produse produs;
                    cin>>produs;
                    toateProdusele.push_back(produs);
                    cout<<endl;
                    break;
                }
            case 2:
                {
                    // afiseaza toate produsele din lista
                    for(int i=0;i<toateProdusele.size();i++)
                        {
                            cout<<endl;
                            cout<<"Produsul "<<i+1;
                            cout<<toateProdusele[i];
                        }
                    cout<<endl;
                    break;
                }
            case 3:
                {
                    //inregistrare cu date personale - se creeaza si cosul de cumparaturi in acelasi timp
                    Utilizator persoana;
                    cin>>persoana;
                    utilizatori.push_back(persoana);
                    // am facut un vector cu utilizatorii
                    CosCumparaturi c;
                    cos.push_back(c);
                    // am pus cosul in vector pentru ca am vrut sa il am stocat mereu undeva
                    cout<<endl;
                    break;
                }
            case 4:
                {
                    // afisarea datelor din cont
                    cout<<utilizatori[utilizatori.size()-1];
                    cout<<endl;
                    break;
                }
            case 5:
                {
                    // adauga un produs din lista mare de produse in wishlist
                    cout<<"Ce produs doriti sa adaugati in wishlist? (Introduceti numarul din lista)";
                    int i;
                    cin>>i;
                    utilizatori[utilizatori.size()-1] = utilizatori[utilizatori.size()-1] + toateProdusele[i-1];
                    // am folosit aici adunarea dintre clase
                    cout<<endl;
                    break;
                }
            case 6:
                {
                    // adaugarea unui produs in cos, tot cu adunarea dintre clase
                    cout<<"Ce produs doriti sa adaugati in cosul de cumparaturi? (Introduceti numarul din lista)";
                    int i;
                    cin>>i;
                    if (cos.size() == 0)
                        {
                            // daca cineva a accesat cosul fara sa se inregistreze se creaza acum
                            CosCumparaturi c;
                            cos.push_back(c);
                        }
                    cos[cos.size()-1] = cos[cos.size()-1] + toateProdusele[i-1];
                    cout<<endl;
                    break;
                }
            case 7:
                {
                    cout<<"Ce produs doriti sa eliminati din cosul de cumparaturi? (Introduceti numarul din lista)";
                    int i;
                    cin>>i;
                    cos[cos.size()-1] = cos[cos.size()-1] - toateProdusele[i-1]; 
                    cout<<endl;
                    break;
                }
            case 8:
                {
                    // afisarea cosului
                    cout<<cos[cos.size()-1];
                    cout<<endl;
                    break;
                }
            case 9:
                {
                    // se introduc datele unui card si se goleste cosul de cumparaturi
                    Card card;
                    cout<<"Introduceti datele cardului: ";
                    cin>>card;
                    cos[cos.size()-1].golireCos();
                    cout<<"Plata a fost finalizata!"<<endl;;
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