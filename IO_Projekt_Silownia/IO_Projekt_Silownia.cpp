// IO_Projekt_Silownia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "Klient.h"
#include "Trener_Personalny.h"
#include "Pomocnicze.h"
#include "Lista_Klientow.h"
#include "KalendarzG.h"
#include "Pracownik_Administracji.h"
#include <iostream>
int main()
{
	Data data;
	Czas czas;
	Pracownik_Administracji* pracownik = new Pracownik_Administracji(string("Janek"), string("123456"), string("Jan"), string("Kowalski"), 0, data);
	Trener_Personalny* trener = new Trener_Personalny(string("Olka"), string("123"), string("Ola"), string("Oliwkiewicz"), 501, data, 666555444);
	Klient* klient = new Klient(string("Adamek"), string("321"), string("Adam"), string("Maj"), data, 2, 33333333, string("test@wp.pl"));
	Klient* klient2 = new Klient(string("Adamek2"), string("3214"), string("Adam2"), string("Maj2"), data, 4, 33333333, string("test2@wp.pl"));
	Klient* klient3 = new Klient(string("Adamek3"), string("3215"), string("Adam3"), string("Maj3"), data, 5, 33333333, string("test3@wp.pl"));
	Lista_Klientow::getInstance()->Dodaj_Klienta(klient);
	Lista_Klientow::getInstance()->Dodaj_Klienta(klient2);
	Lista_Klientow::getInstance()->Dodaj_Klienta(klient3);
	pracownik->Wyswietl();
	trener->Wyswietl();
	GrTrening* grTrening = pracownik->Zaplanuj_GrTrening(data, czas, czas, string("opis"), 0, trener);
	GrTrening* grTrening2 = pracownik->Zaplanuj_GrTrening(data, czas, czas, string("opis"), 2, trener);
	pracownik->Wyswietl_kalendarz(KalendarzG::getInstance());
	klient->Zapisz_do_GrTrening(grTrening);
	klient3->Zapisz_do_GrTrening(grTrening);
	cout << "Lista uczestnikow:" << endl;
	pracownik->Wyswietl_liste_uczestnikow(grTrening);
	klient->Sprawdz_status();
	pracownik->Dodaj_karnet(5, 0, klient);
	klient->Sprawdz_status();
	trener->Zaplanuj_trening(data, czas, czas, string("opis treningu"), klient);
	klient->Wyswietl_kalendarz();
	Lista_Klientow::getInstance()->Wyswietl();

}
