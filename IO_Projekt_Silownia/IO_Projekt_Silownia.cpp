// IO_Projekt_Silownia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "Klient.h"
#include "Trener_Personalny.h"
#include "Pomocnicze.h"
#include "Lista_Klientow.h"
#include "KalendarzG.h"
#include "Pracownik_Administracji.h"
#include "Lista_Pracownikow.h"
#include <iostream>
void PrintResult(OsobaError error) {
	switch (error)
	{
	case OsobaError::NoError:
		cout << "Udalo sie dodac osobe!" << endl;
		break;
	case OsobaError::SameLogin:
		cout << "Login jest juz zajety!" << endl;
		break;
	case OsobaError::WrongId:
		cout << "Id jest juz zajete!" << endl;
		break;
	default:
		break;
	}
	
}
void PrintResult(KarnetError error) {
	switch (error)
	{
	case KarnetError::NoError:
		cout << "Udalo sie dodac karnet!" << endl;
		break;
	case KarnetError::KarnetJuzPrzypisany:
		cout << "Karnet byl juz przypisany!" << endl;
		break;
	default:
		break;
	}

}
void PrintResult(TreningError error) {
	switch (error)
	{
	case TreningError::NoError:
		cout << "Udalo sie dodac trening!" << endl;
		break;
	case TreningError::TrenerZajety:
		cout << "Trener jest juz zajety w tym terminie!" << endl;
		break;
	case TreningError::KlientZajety:
		cout << "Klient jest juz zajety w tym terminie!" << endl;
		break;
	case TreningError::WrongId:
		cout << "Id jest juz zajete!" << endl;
		break;
	default:
		break;
	}

}

int main()
{
	Data data;
	Czas czas;
	//Tworzymy kilka przykladowych osob. klient2 ma powtorzone id a klient3 ma powtorzony login,wiec powinno sie nie udac ich pozniejsze dodanie
	Pracownik_Administracji* pracownik = new Pracownik_Administracji(string("Janek"), string("123456"), string("Jan"), string("Kowalski"), 0, data);
	Trener_Personalny* trener = new Trener_Personalny(string("Olka"), string("123"), string("Ola"), string("Oliwkiewicz"), 501, data, 666555444);
	Klient* klient = new Klient(string("Adamek"), string("321"), string("Adam"), string("Maj"), data, 2, 33333333, string("test@wp.pl"));
	Klient* klient2 = new Klient(string("Adamek2"), string("3214"), string("Adam2"), string("Maj2"), data, 0, 33333333, string("test2@wp.pl"));
	Klient* klient3 = new Klient(string("Janek2"), string("3215"), string("Adam3"), string("Maj3"), data, 5, 33333333, string("test3@wp.pl"));
	
	//Przykladowe wyswietlenie pracownika i trenera
	pracownik->Wyswietl();
	trener->Wyswietl();

	//Dodawanie tych osob
	PrintResult(Lista_Pracownikow::getInstance()->Dodaj_Pracownika(pracownik));
	PrintResult(Lista_Pracownikow::getInstance()->Dodaj_Pracownika(trener));
	PrintResult(Lista_Klientow::getInstance()->Dodaj_Klienta(klient));
	PrintResult(Lista_Klientow::getInstance()->Dodaj_Klienta(klient2));
	PrintResult(Lista_Klientow::getInstance()->Dodaj_Klienta(klient3));

	//Tworzenie 2 grupowych wydarzen w tym samym czasie dla jednego trenera
	GrTrening* grTrening =  new GrTrening(data, czas, czas, 3, string("utworzony"), string("opis"), trener);
	GrTrening* grTrening2 = new GrTrening(data, czas, czas, 4, string("utworzony"), string("opis"), trener);
	PrintResult(pracownik->Zaplanuj_GrTrening(grTrening));
	PrintResult(pracownik->Zaplanuj_GrTrening(grTrening2));


	pracownik->Wyswietl_kalendarz(KalendarzG::getInstance());


	cout << (klient->Zapisz_do_GrTrening(grTrening) ? "Dodano." : "Klient jest zajety w tym terminie.") << endl;
	cout << (klient3->Zapisz_do_GrTrening(grTrening) ? "Dodano." : "Klient jest zajety w tym terminie.") << endl;


	cout << "Lista uczestnikow:" << endl;
	pracownik->Wyswietl_liste_uczestnikow(grTrening);


	cout <<(klient->Sprawdz_status() ? "Aktywny." : "Nieaktywny." )<< endl;
	PrintResult(pracownik->Dodaj_karnet(5, klient));
	cout << (klient->Sprawdz_status() ? "Aktywny." : "Nieaktywny." ) << endl;


	cout << "WTF??" << endl;
	PrintResult(trener->Zaplanuj_trening(data, czas, czas, string("opis treningu"), klient,7));
	klient->Wyswietl_kalendarz();
	Lista_Klientow::getInstance()->Wyswietl();

}
