#include<iostream>
#include<string.h>
#include<set>
#include<vector>
#include<list>
#include<map>
using namespace std;


// CLASA PERSOANA

class Persoana{
protected:
    string nume;
    string prenume;
    string CNP;
    string dataNastere;


public:
    Persoana();
    Persoana(string nume, string prenume, string CNP, string dataNastere);
    Persoana(const Persoana &obj);

    Persoana& operator=(const Persoana &obj);
    friend istream& operator>>(istream& in, Persoana &obj);
    friend ostream& operator<<(ostream& out, const Persoana &obj);

    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream&out) const;

    ~Persoana() = default;
};


Persoana::Persoana()
{
    nume = "nedefinit";
    prenume = "nedefinit";
    CNP = "SAALLZZJJNNNC";
    dataNastere = "ZZ/LL/AA";
}

Persoana::Persoana(string nume, string prenume, string CNP, string dataNastere)
{
    this->nume = nume;
    this->prenume = prenume;
    this->CNP = CNP;
    this->dataNastere = dataNastere;
}

Persoana::Persoana(const Persoana &obj)
{
    this->nume = obj.nume;
    this->prenume = obj.prenume;
    this->CNP = obj.CNP;
    this->dataNastere = obj.dataNastere;
}

Persoana& Persoana::operator=(const Persoana &obj)
{
    if (this != &obj)
    {
        this->nume = obj.nume;
        this->prenume = obj.prenume;
        this->CNP = obj.CNP;
        this->dataNastere = obj.dataNastere;
    }
    return *this;
}


//exceptii la introducere date
istream& Persoana::citire(istream& in)
{
    string zi, luna, an;
    cout<<endl;
    cout<<"Citeste numele de familie: ";
    in.get();
    getline(in, this->nume);
    cout<<"Citeste prenumele: ";
    in.get();
    getline(in, this->prenume);
    cout<<"Citeste CNP: ";
    in.get();
    getline(in, this->CNP);
    cout<<"Citeste data de nastere: "<<endl;
    cout<<"ZZ: ";
    in.get();
    getline(in, zi);
    cout<<"LL: ";
    in.get();
    getline(in, luna);
    cout<<"AAAA: ";
    in.get();
    getline(in, an);
    this->dataNastere = zi + "/" + luna + "/" + an;
    return in;
}

ostream& Persoana::afisare(ostream& out) const
{
    out<<endl;
    out<<"Numele de familie: "<<this->nume<<endl;
    out<<"Prenumele: "<<this->prenume<<endl;
    out<<"CNP: "<<this->CNP<<endl;
    out<<"Data nasterii: "<<this->dataNastere<<endl;
    return out;
}

istream& operator>>(istream& in, Persoana &obj)
{
    return obj.citire(in);
}
ostream& operator<<(ostream& out, const Persoana &obj)
{
    return obj.afisare(out);
}



// CLASA ANGAJAT - copil Persoana

class Angajat:public Persoana
{
protected:
    static int contorAngajat;
    const int idAngajat;
    string dataAngajare;
    string pozitie;
    set<string> softSkills;
    int salariu;
public:
    Angajat();
    Angajat(string nume, string prenume, string CNP, string dataNastere,
            string dataAngajare, string pozitie ,set<string> softSkills, int salariu);
    Angajat(const Angajat& obj);

    Angajat& operator=(const Angajat &obj);
    friend istream& operator>>(istream& in, Angajat &obj);
    friend ostream& operator<<(ostream& out, const Angajat &obj);
    bool operator<(const Angajat& obj) const {
        return idAngajat < obj.idAngajat;
    }
    bool operator>(const Angajat& obj) const {
        return idAngajat > obj.idAngajat;
    }
    bool operator==(const Angajat& obj)
    {
        return obj.idAngajat == this->idAngajat;
    }

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    void adaugaSkill(const string& skill);
    void eliminaSkill(const string& skill);

    int getIdAngajat() const {return this->idAngajat;}
    int getSalariu() const {return this->salariu;}




    ~Angajat() = default;
};

Angajat::Angajat():idAngajat(contorAngajat++)
{
    dataAngajare = "ZZ/LL/AAAA";
    pozitie = "nedefinita";
    salariu = 0;
}

Angajat::Angajat(string nume, string prenume, string CNP, string dataNastere,
                 string dataAngajare, string pozitie ,set<string> softSkills, int salariu):
        Persoana(nume, prenume, CNP, dataNastere), idAngajat(contorAngajat++)
{
    this->dataAngajare = dataAngajare;
    this->pozitie = pozitie;
    this->softSkills = softSkills;
    this->salariu = salariu;
}

Angajat::Angajat(const Angajat& obj):Persoana(obj), idAngajat(obj.idAngajat)
{
    this->dataAngajare = obj.dataAngajare;
    this->pozitie = obj.pozitie;
    this->softSkills = obj.softSkills;
    this->salariu = obj.salariu;
}

Angajat& Angajat::operator=(const Angajat &obj)
{
    if(this!=&obj)
    {
        Persoana::operator=(obj);
        this->dataAngajare = obj.dataAngajare;
        this->pozitie = obj.pozitie;
        this->softSkills = obj.softSkills;
        this->salariu = obj.salariu;
    }
    return *this;
}

istream& Angajat::citire(istream &in)
{
    this->Persoana::citire(in);
    string zi, luna, an;
    cout<<"Citeste data de angajare: "<<endl;
    cout<<"ZZ: ";
    in.get();
    getline(in, zi);
    cout<<"LL: ";
    in.get();
    getline(in, luna);
    cout<<"AAAA: ";
    in.get();
    getline(in, an);
    this->dataAngajare = zi + "/" + luna + "/" + an;
    cout<<"Citeste pozitia: ";
    in.get();
    getline(in, this->pozitie);


    // arunca runtime_error si out_of_range pentru comenzile puse gresit
    // citire soft skills cu switch case 
    cout<<"Citeste soft skills: \n";
    int k = 1;
    while (k==1)
    {
        cout<<"Apasa 1 pentru a adauga un soft skill\n";
        cout<<"Apasa 2 pentru a trece la campul salariu\n";

        int comanda;
        try{
            if(!(in>>comanda))
                throw runtime_error("Introduceti o cifra!");
            if (comanda!= 1 && comanda!=2 ) {
                throw out_of_range("Comanda invalida. Introduceti 1 sau 2.");
            }
            switch(comanda)
            {
                case 1:
                {
                    string skill;
                    cout<<"Skill: ";
                    in.get();
                    getline(in, skill);
                    this->softSkills.insert(skill);
                    break;
                }
                case 2:
                {
                    k = 0;
                    break;
                }
            }
        }
        catch (const runtime_error& e) {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');

        } catch (const out_of_range& e) {
            cout << "Eroare: " << e.what() << endl;
        }

    }


    // arunca invalid_argument daca nu e int
    //cout<<"Citeste salariul: ";
    while(true)
    {
        cout<<"Citeste salariu";
        try{
            if(!(in>>this->salariu))
                throw invalid_argument("Input invalid. Introduceti un numar intreg pentru salariu.");
            else
                break;
        }
        catch (const invalid_argument& e)
        {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }

    return in;
}


ostream& Angajat::afisare(ostream& out) const
{
    this->Persoana::afisare(out);
    out<<"Cod angajat: "<<this->idAngajat<<endl;
    out<<"Data angajare: "<<this->dataAngajare<<endl;
    out<<"Pozitia: "<<this->pozitie<<endl;

    out<<"Setul de soft skills: ";
    if (softSkills.size() == 0)
        cout<<"nu este definit\n";
    else
    {
        for(auto skill = softSkills.begin(); skill!=softSkills.end(); skill++)
        {
            if(next(skill) == softSkills.end())
            {
                out<<*skill<<endl;
                break;
            }

            out<<*skill<<", ";
        }
    }


    cout<<"Salariu: "<<this->salariu<<endl;
    return out;
}


istream& operator>>(istream& in, Angajat &obj)
{
    return obj.citire(in);
}

ostream& operator<<(ostream& out, const Angajat &obj)
{
    return obj.afisare(out);
}



// CLASA MANAGER - copil Angaajat, nepot Persoana
class Manager: public Angajat
{
private:
    int experienta;
    int nrSubordonati;
    vector<Angajat> echipa;
public:
    Manager();

    Manager(string nume, string prenume, string CNP, string dataNastere,
            string dataAngajare, string pozitie ,set<string> softSkills, int salariu,
            int experienta, int nrSubordonati,vector<Angajat> echipa);

    Manager(const Manager &obj);

    Manager& operator=(const Manager &obj);

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;


    int getIdAngajat() const {return this->idAngajat;}
    string getNumeManager() const {return this->nume;}

    void salariuManager();

    ~Manager() = default;
};

void Manager::salariuManager()
{
    this->salariu += 1000*nrSubordonati;
}

//C fara param
Manager::Manager()
{
    experienta = 0;
    nrSubordonati = 0;
}

//CP
Manager::Manager(string nume, string prenume, string CNP, string dataNastere,
                 string dataAngajare, string pozitie ,set<string> softSkills, int salariu,
                 int experienta, int nrSubordonati,vector<Angajat> echipa):Angajat(nume, prenume, CNP, dataNastere, dataAngajare, pozitie,softSkills, salariu)
{
    this->experienta = experienta;
    this->nrSubordonati = nrSubordonati;
    this->echipa = echipa;
}

//CC
Manager::Manager(const Manager &obj):Angajat(obj)
{
    this->experienta = obj.experienta;
    this->nrSubordonati = obj.nrSubordonati;
    this->echipa = obj.echipa;
}

//Op=
Manager& Manager::operator=(const Manager &obj)
{
    if (this!=&obj)
    {
        Angajat::operator=(obj);
        this->experienta = obj.experienta;
        this->nrSubordonati = obj.nrSubordonati;
        this->echipa = obj.echipa;
    }
    return *this;
}

// invalid_argument
//pt citire
istream& Manager::citire(istream& in)
{
    this->Angajat::citire(in);

    while(true)
    {
        cout<<"Citeste de cat timp se afla in pozitia de manager (in luni): ";
        try{
            if(!(in>>this->experienta))
                throw invalid_argument("Input invalid. Introduceti un numar natural pentru experienta.");
            else
                break;
        }
        catch (const invalid_argument& e)
        {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }


    while(true)
    {
        cout<<"Citeste cati subordonati are: ";
        try{
            if(!(in>>this->nrSubordonati))
                throw invalid_argument("Input invalid. Introduceti un numar natural pentru numarul de subordonati.");
            else
                break;
        }
        catch (const invalid_argument& e)
        {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    for(int i = 0;i<nrSubordonati;i++)
    {
        Angajat a;
        cout<<"Angajat: ";
        in>>a;
        this->echipa.push_back(a);
    }


    return in;
}

//pt afisare
ostream& Manager::afisare(ostream& out) const
{
    this->Angajat::afisare(out);
    out<<"Experienta in luni: "<<this->experienta<<endl;
    out<<"Numarul de subordonati: "<<this->nrSubordonati<<endl;

    // am facut asa sa se afiseze frumos chiar daca nu echipa e goala
    if (nrSubordonati == 0)
        out<<"Echipa este formata doar din manager\n";
    else
    {
        out<<"Echipa: \n";

        // i pentru a se afisa frumos cu al n-lea membru al echipei
        int i = 1;
        for(auto a = echipa.begin(); a!=echipa.end(); a++)
        {
            out<<"ID angajat "<<i<<": ";
            out<<a->getIdAngajat();
            i++;
            out<<endl;
        }
    }

    return out;
}


// CLASA PROIECT
class Proiect
{
private:
    string nume;
    string descriere;
    const int idProiect;
    static int contorProiect;
    set<Angajat> projectTeam;
    list<string> istoricModificari;


public:
    Proiect();
    Proiect(string nume, string descriere, set<Angajat> projectTeam, list<string>istoricModificari);
    Proiect(const Proiect &obj);

    Proiect& operator=(const Proiect &obj);
    bool operator<(const Proiect& obj) const {
        return idProiect < obj.idProiect;
    }

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    friend istream& operator>>(istream& in, Proiect& obj);
    friend ostream& operator<<(ostream& out, const Proiect& obj);


    bool operator>(const Proiect& obj) const {
        return idProiect > obj.idProiect;
    }
    bool operator==(const Proiect& obj)
    {
        return obj.idProiect == this->idProiect;
    }

    const int getIdProiect() const {return idProiect;}
    string getNumeProiect() const {return nume;}

    void adaugaAngajat(Angajat a){this->projectTeam.insert(a);}


    ~Proiect() = default;

};

Proiect::Proiect():idProiect(contorProiect++)
{
    nume = "Proiect nedefinit";
    descriere = "Un proiect fara descriere";
}

Proiect::Proiect(string nume, string descriere, set<Angajat> projectTeam, list<string>istoricModificari):idProiect(contorProiect++)
{
    this->nume = nume;
    this->descriere = descriere;
    this->projectTeam = projectTeam;
    this->istoricModificari = istoricModificari;
}

Proiect::Proiect(const Proiect &obj):idProiect(obj.idProiect)
{
    this->nume = obj.nume;
    this->descriere = obj.descriere;
    this->projectTeam = obj.projectTeam;
    this->istoricModificari = obj.istoricModificari;
}

Proiect& Proiect::operator=(const Proiect &obj)
{
    if(this!=&obj)
    {
        this->nume = obj.nume;
        this->descriere = obj.descriere;
        this->projectTeam = obj.projectTeam;
        this->istoricModificari = obj.istoricModificari;
    }

    return *this;
}

//runtime error
//out_of_range
istream& Proiect::citire(istream& in)
{
    cout<<"Numele proiectului: ";
    in.get();
    getline(in, this->nume);
    cout<<"Descrierea proiectului: ";
    in.get();
    getline(in, this->descriere);
    cout<<"Angajatii care lucreaza la proiect: \n";

    int k = 1;
    while (k==1)
    {
        cout << "Apasa 1 pentru a adauga un angajat\n";
        cout << "Apasa 2 pentru a trece la campul istoric de modificari\n";

        int comanda;
        try{
            if(!(in>>comanda))
                throw runtime_error("Introduceti o cifra!");
            if (comanda!= 1 && comanda!=2 ) {
                throw out_of_range("Comanda invalida. Introduceti 1 sau 2.");
            }
            switch (comanda) {
                case 1: {
                    Angajat a;
                    cout << "Angajat: ";
                    in >> a;
                    this->projectTeam.insert(a);
                    break;
                }
                case 2: {
                    k = 0;
                    break;
                }
            }
        }
        catch (const runtime_error& e) {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const out_of_range& e) {
            cout << "Eroare: " << e.what() << endl;
        }

    }


    cout<<"Istoricul de modificari: \n";
    int k2 = 1;
    while (k2==1)
    {
        cout << "Apasa 1 pentru a adauga o modificare\n";
        cout << "Apasa 2 pentru a iesi\n";

        int comanda2;
        try{
            if(!(in>>comanda2))
                throw runtime_error("Introduceti o cifra!");
            if (comanda2!= 1 && comanda2!=2 ) {
                throw out_of_range("Comanda invalida. Introduceti 1 sau 2.");
            }
            switch (comanda2) {
                case 1: {
                    string modificare;
                    cout << "Modificare: ";
                    in >> modificare;
                    this->istoricModificari.push_back(modificare);
                    break;
                }
                case 2: {
                    k2 = 0;
                    break;
                }
            }
        }
        catch (const runtime_error& e) {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const out_of_range& e) {
            cout << "Eroare: " << e.what() << endl;
        }
    }
    return in;
}

ostream& Proiect::afisare(ostream& out) const
{
    out<<endl;
    out<<"Numele proiectului: "<<this->nume<<endl;
    out<<"Descrierea proiectului: "<<this->descriere<<endl;
    out<<"ID proiect: "<<this->idProiect<<endl;

    //afisare projectTeam
    if (projectTeam.size() == 0)
        out<<"Momentan nimeni nu lucreaza la acest proiect\n";
    else
    {
        out<<"Angajatii care lucreaza la proiect: \n";;

        // i pentru a se afisa frumos cu al n-lea membru al echipei
        int i = 1;
        for(auto a = projectTeam.begin(); a!=projectTeam.end(); a++)
        {
            out<<"ID angajat "<<i<<": ";
            out<<a->getIdAngajat();
            i++;
            out<<endl;
        }
    }

    //afisare istoric de modificari
    if (istoricModificari.size() == 0)
        cout<<"Istoricul este gol\n";
    else
    {
        out<<"Istoricul de modificari: ";
        for(auto i = istoricModificari.begin(); i!=istoricModificari.end(); i++)
        {
            if(next(i) == istoricModificari.end())
            {
                out<<*i<<endl;
                break;
            }

            out<<*i<<", ";
        }
    }
    return out;
}

istream& operator>>(istream& in, Proiect& obj)
{
    return obj.citire(in);
}

ostream& operator<<(ostream& out, const Proiect& obj)
{
    return obj.afisare(out);
}


class Departament
{
private:
    string numeDepartament;
    set<Angajat> angajatiDepartament;
    Manager managerDepartament;
    const int idDepartament;
    static int contorDepartament;
    map<Proiect,float> proiectBuget;
public:
    Departament();
    Departament(string numeDepartament,set<Angajat> angajatiDepartament, Manager managerDepartament, map<Proiect, float> proiectBuget);
    Departament(const Departament& obj);

    Departament& operator=(const Departament& obj);
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    friend istream& operator>>(istream& in, Departament& obj);
    friend ostream& operator<<(ostream& out, const Departament& obj);

    bool operator>(const Departament& obj) const {
        return this->idDepartament > obj.idDepartament;
    }
    bool operator==(const Departament& obj)
    {
        return obj.idDepartament == this->idDepartament;
    }



    void adaugaAngajat(Angajat a){this->angajatiDepartament.insert(a);}
    void setManager(Manager m){this->managerDepartament = m;}
    string getNumeDepartament() const {return this->numeDepartament;}
    set<Angajat> getAngajati() const {return this->angajatiDepartament;}
    map<Proiect,float> getProiectBuget() const {return this->proiectBuget;}

    ~Departament() = default;
};

Departament::Departament():idDepartament(contorDepartament++)
{
    this->numeDepartament = "nedefinit";
}

Departament::Departament(std::string numeDepartament, set<Angajat> angajatiDepartament,
                         Manager managerDepartament,map<Proiect, float> proiectBuget):idDepartament(contorDepartament++)
{
    this->numeDepartament = numeDepartament;
    this->angajatiDepartament = angajatiDepartament;
    this->managerDepartament = managerDepartament;
    this->proiectBuget = proiectBuget;
}

Departament::Departament(const Departament &obj):idDepartament(obj.idDepartament)
{
    this->numeDepartament = obj.numeDepartament;
    this->angajatiDepartament = obj.angajatiDepartament;
    this->managerDepartament = obj.managerDepartament;
    this->proiectBuget = obj.proiectBuget;
}

Departament& Departament::operator=(const Departament &obj)
{
    if(this!=&obj)
    {
        this->numeDepartament = obj.numeDepartament;
        this->angajatiDepartament = obj.angajatiDepartament;
        this->managerDepartament = obj.managerDepartament;
        this->proiectBuget = obj.proiectBuget;
    }
    return *this;
}

istream& Departament::citire(istream& in)
{
    cout<<"\nNumele departamentului: ";
    in.get();
    getline(in, this->numeDepartament);

    cout<<"Angajatii care fac parte din departament: \n";

    int k = 1;
    while (k==1)
    {
        cout<<endl;
        cout << "Apasa 1 pentru a adauga un angajat\n";
        cout << "Apasa 2 pentru a trece la campul manager\n";

        int comanda;
        try{
            if(!(in>>comanda))
            {
                throw runtime_error("Introduceti o cifra!");
            }
            if (comanda!= 1 && comanda!=2 ) {
                throw out_of_range("Comanda invalida. Introduceti 1 sau 2.");
            }
            switch (comanda) {
                case 1: {
                    Angajat a;
                    cout << "Angajat: ";
                    in >> a;
                    this->angajatiDepartament.insert(a);
                    break;
                }
                case 2: {
                    k = 0;
                    break;
                }
            }
        }
        catch (const runtime_error& e) {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const out_of_range& e) {
            cout << "Eroare: " << e.what() << endl;
        }

    }

    cout<<"Managerul departamentului: ";
    in>>this->managerDepartament;

    cout<<"Proiectele departamentului si bugetul alocat";
    int k2 = 1;
    while (k2==1)
    {
        cout << "Apasa 1 pentru a adauga un proiect\n";
        cout << "Apasa 2 pentru a iesi\n";

        int comanda2;
        try{
            if(!(in>>comanda2))
            {
                throw runtime_error("Introduceti o cifra!");
            }
            if (comanda2!= 1 && comanda2!=2 ) {
                throw out_of_range("Comanda invalida. Introduceti 1 sau 2.");
            }
            switch (comanda2) {
                case 1: {
                    Proiect p;
                    float b;
                    cout<<"Proiectul: ";
                    in>>p;



                    while(true)
                    {
                        cout<<"Buget: ";
                        try{
                            if(!(in>>b))
                                throw invalid_argument("Input invalid. Introduceti un numar natural pentru buget.");
                            else
                                break;
                        }
                        catch (const invalid_argument& e)
                        {
                            cout << "Eroare: " << e.what() << endl;
                            in.clear();
                            in.ignore(numeric_limits<streamsize>::max(), '\n');

                        }
                    }

                    proiectBuget.insert(pair<Proiect,float>(p,b));
                }
                case 2: {
                    k2 = 0;
                    break;
                }
            }
        }
        catch (const runtime_error& e) {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const out_of_range& e) {
            cout << "Eroare: " << e.what() << endl;
        }

    }

    return in;
}

ostream& Departament::afisare(std::ostream &out) const
{
    cout<<"Numele departamentului este: "<<this->numeDepartament<<endl;
    cout<<"ID departament: "<<this->idDepartament<<endl;
    if (angajatiDepartament.size() == 0)
        out<<"Momentan nu lucreaza nimeni in acest departament\n";
    else
    {
        out<<"Angajatii care lucreaza in departament: \n";;

        // i pentru a se afisa frumos cu al n-lea membru al echipei
        int i = 1;
        for(auto a = angajatiDepartament.begin(); a!=angajatiDepartament.end(); a++)
        {
            out<<"ID angajat "<<i<<": ";
            out<<a->getIdAngajat();
            i++;
            out<<endl;
        }
    }

    cout<<"Managerul departamentului: "<<this->managerDepartament.getNumeManager()<<endl;

    if (proiectBuget.size() == 0)
        out<<"Momentan nu exista proiecte\n";
    else
    {
        out << "Proiecte si bugete:\n";
        for (auto it = proiectBuget.begin(); it != proiectBuget.end(); ++it) {
            out<<it->first.getNumeProiect() << ": " << it->second << endl;
        }
    }

    return out;
}

istream& operator>>(istream& in, Departament& obj)
{
    return obj.citire(in);
}

ostream& operator<<(ostream& out, const Departament& obj)
{
    return obj.afisare(out);
}

//static int pentru codul de angajat
int Angajat::contorAngajat = 1000;
//static int pentru codul de proiect
int Proiect::contorProiect = 10;
//static int pentru codul de proiect
int Departament::contorDepartament = 1;


//TEMPLATE
//sortare
template <typename T>
void sortare(vector<T>& v) {
    int n = v.size();
    for(int i = 0;i<n-1;i++)
        for(int j = i+1;j<n;j++)
        {
            if(v[i]>v[j])
            {
                swap(v[i],v[j]);
            }
        }
}

//sterge elem de pe poz i din vector
template <typename T>
void stergeIndex(vector<T>& v,int i)
{
    try{
        if(i < v.size())
            v.erase(v.begin()+i);
        else
            throw out_of_range("Indexul este mai mare decat numarul de elemente");
    }
    catch(exception& e)
    {
        cout<<"Exceptie: "<<e.what()<<endl;
    }
}


//sterge element din vector
template<typename T>
void stergeElement(vector<T>& v, const T &elem)
{
    for(int i = 0;i<v.size();i++)
    {
        if(v[i] == elem)
        {
            v.erase(v.begin()+i);
        }
    }
}

//nu e prea bine
template <typename T>
class Repository
{
private:
    vector<T> v;
public:
    Repository() = default;
    Repository(vector<T> v):v(v) {}

    void adaugaElement(const T& item)
    {
        v.push_back(item);
    }

    void stergeIndex(int i)
    {
        try{
            if(i < v.size())
                v.erase(v.begin()+i);
            else
                throw out_of_range("Indexul este mai mare decat numarul de elemente");
        }
        catch(exception& e)
        {
            cout<<"Exceptie: "<<e.what()<<endl;
        }

    }

    void stergeElement(const T &elem)
    {
        for(int i = 0;i<v.size();i++)
        {
            if(v[i] == elem)
            {
                v.erase(v.begin()+i);
            }
        }
    }


    ~Repository() = default;
};

class Singleton
{

private:
    static Singleton* instance;
    vector<Angajat*> angajati;
    vector<Departament> departamente;
    Singleton() = default;
    ~Singleton();

    //vectori
public:
    static Singleton* getInstance();
    void display();
    void engine();
    void addData();
    void destroy();
};

Singleton* Singleton::getInstance()
{
    if (Singleton::instance != NULL)
        return Singleton::instance;
    else
    {
        instance = new Singleton();
        return instance;
    }
}

void Singleton::addData()
{
    set<string> SoftSkillsA1;
    SoftSkillsA1.insert("bun orator");
    SoftSkillsA1.insert("punctual");
    set<string> SoftSkillsA2;
    SoftSkillsA2.insert("organizat");
    set<string> SoftSkillsA3;
    SoftSkillsA3.insert("creativ");
    SoftSkillsA3.insert("abilitati de rezolvare a problemelor");
    set<string> SoftSkillsA4;
    SoftSkillsA4.insert("bun orator");
    SoftSkillsA4.insert("abilitati de rezolvare a problemelor");
    set<string> SoftSkillsA5;
    SoftSkillsA5.insert("bun orator");
    SoftSkillsA5.insert("abilitati de leader");


    Angajat* a8 = new Angajat("Maris", "Tudor", "1931226412674", "30/12/1992", "23/02/2024", "Expert vanzari", SoftSkillsA2, 2000);
    angajati.push_back(a8);
    Angajat* a5 = new Angajat("Andrei", "Alexandru", "1931226412674", "26/11/1999", "23/04/2024", "Stagiar Marketing", SoftSkillsA4, 1200);
    angajati.push_back(a5);
    vector<Angajat> angMarketing;
    angMarketing.push_back(*a5);
    Angajat* a1 = new Manager("Marin", "Elena", "2931226412674", "26/12/1993", "23/02/2022", "Manager Marketing", SoftSkillsA1, 3500,12,1,angMarketing);
    angajati.push_back(a1);
    Angajat* a2 = new Angajat("Tudor", "Andrei", "1938256492175", "12/01/1995", "13/06/2023", "Software Developer", SoftSkillsA2, 2500);
    angajati.push_back(a2);
    Angajat* a3 = new Angajat("Ionescu", "Andreea", "2932345412974", "29/11/1993", "28/02/2020", "Contabil", SoftSkillsA3, 1800);
    angajati.push_back(a3);
    Angajat* a7 = new Angajat("Pop", "Marius", "1931226412674", "26/12/1993", "23/02/2022", "Inginer Software", SoftSkillsA3, 2600);
    angajati.push_back(a7);
    vector<Angajat> angHR;
    angHR.push_back(*a3);
    angHR.push_back(*a8);
    vector<Angajat> angIT;
    angIT.push_back(*a2);
    angIT.push_back(*a7);

    Angajat* a6 = new Manager("Popescu", "Teodora", "1931226412674", "26/12/1984", "21/01/2018", "Manager IT", SoftSkillsA5, 4000,24,2,angIT);
    angajati.push_back(a6);
    Angajat* a4 = new Manager("Marinescu", "Ioana", "2931226412674", "26/12/1990", "02/12/2019", "Manager HR", SoftSkillsA5, 3200,18,2,angHR);
    angajati.push_back(a4);


    set<Angajat> teamHR;
    teamHR.insert(*a3);
    teamHR.insert(*a4);
    teamHR.insert(*a8);

    set<Angajat> teamIT;
    teamIT.insert(*a6);
    teamIT.insert(*a2);
    teamIT.insert(*a7);

    set<Angajat> teamMArketing;
    teamMArketing.insert(*a1);
    teamMArketing.insert(*a5);

    list<string> istoricModificari;
    istoricModificari.push_back("Start proiect");
    istoricModificari.push_back("Formare echipa");
    istoricModificari.push_back("Desfasurare proiect");

    Proiect p1("Venit", "Total venit anual",teamHR,istoricModificari);
    Proiect p2("Software", "Produs software pentru clienti",teamIT,istoricModificari);
    Proiect p3("Software companie", "Produs software pentru companie",teamIT,istoricModificari);
    Proiect p4("Strategie Marketing", "Strategia de venit a companiei",teamMArketing,istoricModificari);


    map<Proiect,float> proiecteHR;
    proiecteHR.insert(pair<Proiect, float>(p1, 2000));
    map<Proiect,float> proiecteIT;
    proiecteIT.insert(pair<Proiect, float>(p2, 3000));
    proiecteIT.insert(pair<Proiect, float>(p3, 2500));
    map<Proiect,float> proiecteMArketing;
    proiecteMArketing.insert(pair<Proiect, float>(p4, 3500));


    Departament HR("HR",teamHR,*dynamic_cast<Manager*>(a4),proiecteHR);
    Departament IT("IT",teamIT,*dynamic_cast<Manager*>(a6),proiecteIT);
    Departament Marketing("Marketing",teamMArketing,*dynamic_cast<Manager*>(a1),proiecteMArketing);
    departamente.push_back(HR);
    departamente.push_back(IT);
    departamente.push_back(Marketing);


}

void Singleton::destroy()
{
    cout<<"Destroy";
    if(instance!=NULL)
        free(instance);

    //delete instance;
}

void Singleton::display()
{
    cout<<endl;
    cout<<"Apasa 1 pentru a adauga un angajat"<<endl;
    cout<<"Apasa 2 pentru a adauga un departament"<<endl;
    cout<<"Apasa 3 pentru a vizualiza toti angajatii firmei"<<endl;
    cout<<"Apasa 4 pentru a vizualiza managerii"<<endl;
    cout<<"Apasa 5 pentru a vizualiza departamentele"<<endl;
    cout<<"Apasa 6 pentru a genera rapoarte"<<endl;
    cout<<"Apasa 7 pentru a iesi"<<endl;
}


void Singleton::engine()
{
    this->display();
    int k = 1;
    while(k)
    {

        int comanda;
        try{
            if(!(cin>>comanda))
                throw runtime_error("Introduceti o cifra!");
            if (comanda < 1 || comanda > 7 ) {
                throw out_of_range("Comanda invalida. Introduceti o cifra intre 1 si 7.");
            }

            switch(comanda)
            {
                case 1:
                {
                    // citeste angajat de la tastatura
                    // optiune pentru a citi angajat normal sau manager
                    int k2 = 1;
                    while(k2 == 1)
                    {
                        cout<<"Apasa 1 pentru a adauga un angajat\n";
                        cout<<"Apasa 2 pentru a adauga un manager\n";
                        cout<<"Apasa 3 pentru a te intoarce la meniul principal";

                        int comanda2;
                        try
                        {
                            if(!(cin>>comanda2))
                                throw runtime_error("Introduceti o cifra.");
                            if (comanda2 != 1 && comanda2!=2 && comanda2 != 3) {
                                throw out_of_range("Comanda invalida. Introduceti 1, 2 sau 3.");
                            }

                            switch(comanda2) {
                                case 1: {
                                    angajati.push_back(new Angajat);
                                    cin >> *angajati.back();
                                    break;
                                }
                                case 2: {
                                    Angajat* a = new Manager;
                                    cin>>*a;
                                    try
                                    {
                                        dynamic_cast<Manager&>(*a).salariuManager();
                                    }
                                    catch(bad_cast)
                                    {
                                        cout<<"Eroare la conversie";
                                    }
                                    cout<<endl;
                                    angajati.push_back(a);

                                    break;
                                }
                                case 3:
                                {
                                    k2 = 0;
                                    break;
                                }
                            }
                        }
                        catch (const runtime_error& e) {
                            cout << "Eroare: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } catch (const out_of_range& e) {
                            cout << "Eroare: " << e.what() << endl;
                        }

                    }
                    this->display();
                    break;
                }
                case 2:
                {
                    //citeste departament
                    Departament d;
                    cin>>d;
                    departamente.push_back(d);
                    this->display();
                    break;
                }
                case 3:
                {
                    if(angajati.size()>0)
                    {
                        for(int i = 0;i<angajati.size();i++)
                        {
                            cout<<"\nAngajatul "<<i+1;
                            angajati[i]->Angajat::afisare(cout);
                        }
                    }
                    else
                        cout<<"Nu sunt angajati inregistrati\n";
                    this->display();
                    break;
                }
                case 4:
                {
                    int nr = 1;
                    for(int i = 0;i<angajati.size();i++)
                    {
                        if(typeid(*angajati[i]) == typeid(Manager))
                        {
                            cout<<"\nManager "<<nr<<endl;
                            cout<<*angajati[i];
                            nr+=1;
                        }
                    }
                    if(nr==1)
                        cout<<"Nu sunt manageri inregistrti\n";
                    this->display();
                    break;
                }
                case 5:
                {
                    if(departamente.size()>0)
                    {
                        for(int i = 0;i<departamente.size();i++)
                        {
                            cout<<"\nDepartament "<<i+1<<endl;
                            cout<<departamente[i];
                        }
                    }
                    else
                        cout<<"Nu sunt departamente inregistrate\n";
                    this->display();
                    break;
                }
                case 6:
                {
                    int k2 = 1;
                    while(k2 == 1)
                    {
                        cout<<"Apasa 1 pentru a vizualiza salariul mediu al angajatilor in functie de departament\n";
                        cout<<"Apasa 2 pentru a vizualiza bugetul fiecarui departament\n";
                        cout<<"Apasa 3 pentru a te intoarce la meniul principal";

                        int comanda2;
                        try
                        {
                            if(!(cin>>comanda2))
                                throw runtime_error("Introduceti o cifra.");
                            if (comanda2 != 1 && comanda2!=2 && comanda2 != 3) {
                                throw out_of_range("Comanda invalida. Introduceti 1, 2 sau 3.");
                            }

                            switch(comanda2) {
                                case 1: {
                                    for(int i = 0;i<departamente.size();i++)
                                    {
                                        cout<<"Departamentul "<<departamente[i].getNumeDepartament()<<": ";
                                        set<Angajat> a = departamente[i].getAngajati();
                                        int val = 0;
                                        for(int j = 0;j<a.size();j++)
                                        {
                                            Angajat ang = *a.begin();
                                            val+=ang.getSalariu();
                                        }
                                        cout<<val/a.size()<<endl;
                                    }
                                    break;
                                }
                                case 2: {
                                    for(int i = 0;i<departamente.size();i++)
                                    {
                                        cout<<"Departamentul "<<departamente[i].getNumeDepartament()<<": ";
                                        set<Angajat> a = departamente[i].getAngajati();
                                        int val = 0;
                                        for(int j = 0;j<a.size();j++)
                                        {
                                            Angajat ang = *a.begin();
                                            val+=ang.getSalariu();
                                        }

                                        map<Proiect,float> bugetProiecte = departamente[i].getProiectBuget();
                                        {
                                            for (const auto& pair : bugetProiecte)
                                                val+=pair.second;
                                        }
                                        cout<<val<<endl;
                                    }

                                    break;
                                }
                                case 3:
                                {
                                    k2 = 0;
                                    break;
                                }
                            }
                        }
                        catch (const runtime_error& e) {
                            cout << "Eroare: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } catch (const out_of_range& e) {
                            cout << "Eroare: " << e.what() << endl;
                        }

                    }
                    this->display();
                    break;
                }
                case 7:
                {
                    k = 0;
                    break;
                }

            }

        }
        catch (const runtime_error& e) {
            cout << "Eroare: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } catch (const out_of_range& e) {
            cout << "Eroare: " << e.what() << endl;
        }

    }
}

Singleton::~Singleton()
{
    //steregere vectori la final
    cout<<"\nDestructor\n";



    for(int i = 0;i < angajati.size(); ++i)
        delete angajati[i];
    angajati.clear();
    departamente.clear();
}

Singleton* Singleton::instance = NULL;

int main()
{
    Singleton *menu = Singleton::getInstance();
    menu->addData();
    menu->engine();
    menu->destroy();
    //free(menu);
    return 0;
}