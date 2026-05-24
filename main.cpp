#include <iostream>
#include "stringheader.h"
#include <utility>

int stringspace::String::stringlengthcalc(const char* Stringletters)
{
    int counter = 0;
    if(Stringletters == nullptr)
    {
        counter = 0;
        return counter;
    }


    while(*Stringletters != '\0')
    {
        Stringletters = Stringletters+1;//geht eine Adresse weiter?
        counter++;
    }

    return counter;

}
int stringspace::String::getLength()
{
    return stringlength;
}
char* stringspace::String::getString()
{
    return Stringletters;
}
stringspace::String::String(const char* Stringletters)
{
    if (Stringletters == nullptr)
    {
        this->Stringletters = nullptr;
        stringlength = 0;
        return;
    }
    stringlength = stringlengthcalc(Stringletters);
    this->Stringletters = new char[stringlength+1];
    for(int i = 0; i<stringlength+1; i++)
    {
        this->Stringletters[i] = Stringletters[i];
    }
}

stringspace::String::String()
{
    Stringletters = nullptr;
    stringlength = 0;
}
stringspace::String::~String()
{
    delete[]Stringletters;
    stringlength = 0;
    std::cout<<"Objekt wurde geloescht"<<std::endl;
}


stringspace::String::String(const String& other)
{
    Stringletters = new char[other.stringlength+1];
    for(int i = 0; i<other.stringlength+1; i++)
    {
        this->Stringletters[i] = other.Stringletters[i];
    }
    stringlength = other.stringlength;
}

stringspace::String& stringspace::String::operator=(const String& other)
{
    if(this != &other)
    {
        delete[] Stringletters;

        Stringletters = new char[other.stringlength+1];
        for(int i = 0; i<other.stringlength+1; i++)
        {
            this->Stringletters[i] = other.Stringletters[i];
        }

        stringlength = other.stringlength;
    }
    return *this;
}
stringspace::String& stringspace::String::operator=(String&& other)
{
    if(this != &other)
    {
        delete[] Stringletters;

        Stringletters = other.Stringletters;

        stringlength = other.stringlength;
        other.Stringletters = nullptr;
        other.stringlength = 0;
    }
    return *this;
}
stringspace::String::String(String&& other)
{
    Stringletters = other.Stringletters;
    stringlength = other.stringlength;
    other.Stringletters = nullptr;
    other.stringlength = 0;
}

int main()
{
    stringspace::String S("Hallo");
    std::cout<<S.getString()<<"Laenge: "<<S.getLength()<<std::endl;

    stringspace::String Scopied(S);
    std::cout<<Scopied.getString()<<"Kopierkonstruktor Scopied wird mit Inhalt von S erstellt"<<std::endl;

    stringspace::String copyS;//Default Konstruktor
    copyS = S;
    std::cout<<copyS.getString()<<S.getString()<<"Der Inhalt von S wurde in copyS kopiert"<<std::endl;

    stringspace::String movedS1(std::move(S));
    std::cout<<movedS1.getString()<<std::endl;
    if(S.getString()==nullptr)
        std::cout<<"Der String S wurde mit Move Konstruktor in movedS1 verschoben"<<std::endl;

    stringspace::String test("Servus");
    stringspace::String test2("Bonjour");
    test2 = test;//Kopier Zuweisung
    S = std::move(test);
    std::cout<<S.getString()<<test2.getString()<<"Der Inhalt von test wurde in test2 der einen anderen String beinhaltete kopiert"<<std::endl;
    if(test.getString()==nullptr)
        std::cout<<"Der String test wurde mit Move-Zuweisung in S verschoben"<<std::endl;


    return 0;
}
