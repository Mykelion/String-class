#ifndef STRINGCLASS_H_INCLUDED
#define STRINGCLASS_H_INCLUDED

namespace stringspace
{
    class String
    {
        public:
        String(const char* Stringletters);//Konstruktor
        String(const String& other);//Kopierkonstruktor
        String(String&& other);//Move Konstruktur
        String& operator=(const String& other);//Kopier Zuweisung
        String& operator=(String&& other); //Move Zuweisung
        int stringlengthcalc(const char* Stringletters);//lengthSetter
        String();//konstruktor mit nullpointer
        char* getString();//getter für string
        int getLength();//getter für length
        ~String();//Destruktor

        private:
        char* Stringletters;
        int stringlength;
    };
}

#endif // STRINGCLASS_H_INCLUDED
