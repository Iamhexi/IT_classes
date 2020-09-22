#include <iostream>
using namespace std;

string szyfruj(string wyraz, int klucz, string alfabet){
	string wynik = "";

	int dlugoscAlfabetu = alfabet.length();
	int dlugoscTekstu = wyraz.length();

	for (int i=0; i<dlugoscTekstu; i++){
		for (int j=0; j < dlugoscAlfabetu; j++){
			if (wyraz[i] == alfabet[j])
				wynik += alfabet[(j+klucz)%dlugoscAlfabetu];
		}
	}
	return wynik;
}

int pozycjaLitery(string tekst, char litera){ // -1 jeœli nie zawiera
    int l = tekst.length();
    for (int i = 0; i < l; i++)
        if (tekst[i] == litera)
            return i;
    return -1;
}

string generujAlfabet(char rozpoczynajacaLitera){
	string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int p = pozycjaLitery(alfabet, rozpoczynajacaLitera);
	string czesc1 = alfabet.substr(p);

    int dlugoscCzesci2 = alfabet.length() - czesc1.length();
    string czesc2 = alfabet.substr(0, dlugoscCzesci2);

	return  czesc1 + czesc2;;
}

string przygotujKluczGlowny(string kluczGlowny){
    string nowyKlucz = "";
    int dlugoscKlucza = kluczGlowny.length();
    for (int i=0; i<dlugoscKlucza; i++)
        if (pozycjaLitery(nowyKlucz, kluczGlowny[i]) == -1)
            nowyKlucz += kluczGlowny[i];
    return nowyKlucz;
}

int main(){
    string alfabetJawny = generujAlfabet('A');
	string wyraz = "NIEOBECNY SAM SOBIE SZKODZI";
	string klucz = "TELEFON";
	string szyfrogram = "";

	int indeksKlucza = 0;
	int indeksZnaku = 0;

    klucz = przygotujKluczGlowny(klucz);
    int dlugoscKlucza = klucz.length();
    int dlugoscWyrazuDoZaszyfrowania = wyraz.length();

    while (szyfrogram.length() < dlugoscWyrazuDoZaszyfrowania){
        for (int i=0; i<dlugoscKlucza; i++){

            if (indeksZnaku >= dlugoscWyrazuDoZaszyfrowania)
                break;

            else if (wyraz[indeksZnaku] != ' '){
                char kluczDlaLitery = klucz[indeksKlucza];
                int pozycjaWJawnym = pozycjaLitery(alfabetJawny, wyraz[indeksZnaku]);
                string alfabetTajny = generujAlfabet(kluczDlaLitery);
                szyfrogram += alfabetTajny[pozycjaWJawnym];
                indeksKlucza++;
            }

            else
                szyfrogram += ' ';

            if (indeksKlucza >= dlugoscKlucza)
                indeksKlucza = 0;

            indeksZnaku++;
        }
    }

    cout << szyfrogram;
	return 0;
}

