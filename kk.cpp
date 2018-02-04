#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#define TRUE 1
#define FALSE 0

using namespace std;


int owins = 0;
int xwins = 0;
int gry = 0;



class Opcje {
	
	private: 
		
		int rodzajGry;
		int menu(void);
		
			
	public:
		
		Opcje() { 
			this -> rodzajGry = 0;
			this -> menu();
		}
		
		int checkRodzajGry(void) { return this -> rodzajGry; }
		void losowanie(int*);
	
};


int Opcje::menu(void) {
	
	cout << "\nWybierz rodzaj gry:\n   1: Gra z komputerem (beginner)\n   2: Gra z komputerem (normal)\n   3: Gra z drugim graczem\n";
	while (this -> rodzajGry < 1 || this -> rodzajGry > 3) {
		cout << "\nTwoj wybor (1-3): ";
		if(!(cin >> this -> rodzajGry)) {
			this -> rodzajGry = 0;
			cin.clear();
			cin.ignore();
		}
	}
	cout << endl;
	
return 0;

}


void Opcje::losowanie(int *d1)
{
    *d1 = rand()%9+1;
	return;
}


class Plansza {

protected:
	
	char values[9];
	bool koniec;

public:

	int pola;
	char winner;
	
	void rysuj(void);
	bool spr_pole(int index);
	bool wstaw(int pozycja, char co);
	int aI(char co);
	bool czyWygrywa(char co);
	bool czyKoniec(void);
		
	Plansza (void) {
		for (int i=0; i < 9; i++) {
			this -> values[i] = ' ';
		}
		
		this -> pola = 9;
		this -> koniec = FALSE;
		this -> winner = ' ';
	}


};



void Plansza::rysuj(void) {

	cout << endl;
	cout << " " << values[0] << " | " << values[1] << " | " << values[2] << " \n";
	cout << "-----------\n";
	cout << " " << values[3] << " | " << values[4] << " | " << values[5] << " \n";
	cout << "-----------\n";
	cout << " " << values[6] << " | " << values[7] << " | " << values[8] << " \n";
	cout << endl;



return;

}


bool Plansza::spr_pole(int index) {

	if (this -> values[index] == ' ') return TRUE;
	else return FALSE;

}


bool Plansza::wstaw(int pozycja, char co) {

	if (this -> spr_pole(pozycja) == TRUE) {
		this -> values[pozycja] = co;
		this -> pola--;
		return TRUE;
	} else return FALSE;

}


int Plansza::aI(char co) {
	
	int v = -2;
	char on;
	
	if (co == 'X') on = 'O';
	else on = 'X';

	// Czy da sie skonczyc gre?
	
	if (' ' == this -> values[0] && (
		(co == this -> values[1] && co == this -> values[2]) or 
		(co == this -> values[3] && co == this -> values[6]) or
		(co == this -> values[4] && co == this -> values[8])
	)) v = 0;
	
	else if (' ' == this -> values[1] && (
		(co == this -> values[0] && co == this -> values[2]) or 
		(co == this -> values[4] && co == this -> values[7])
	)) v = 1;
	
	else if (' ' == this -> values[2] && (
		(co == this -> values[0] && co == this -> values[1]) or 
		(co == this -> values[5] && co == this -> values[8]) or
		(co == this -> values[4] && co == this -> values[6])
	)) v = 2;
	
	else if (' ' == this -> values[3] && (
		(co == this -> values[0] && co == this -> values[6]) or 
		(co == this -> values[4] && co == this -> values[5])
	)) v = 3;
	
	else if (' ' == this -> values[4] && (
		(co == this -> values[1] && co == this -> values[7]) or 
		(co == this -> values[3] && co == this -> values[5]) or
		(co == this -> values[0] && co == this -> values[8]) or
		(co == this -> values[2] && co == this -> values[6])
	)) v = 4;
	
	else if (' ' == this -> values[5] && (
		(co == this -> values[2] && co == this -> values[8]) or 
		(co == this -> values[3] && co == this -> values[4])
	)) v = 5;
	
	else if (' ' == this -> values[6] && (
		(co == this -> values[0] && co == this -> values[3]) or 
		(co == this -> values[7] && co == this -> values[8]) or
		(co == this -> values[4] && co == this -> values[2])
	)) v = 6;
	
	else if (' ' == this -> values[7] && (
		(co == this -> values[6] && co == this -> values[8]) or 
		(co == this -> values[1] && co == this -> values[4])
	)) v = 7;
	
	else if (' ' == this -> values[8] && (
		(co == this -> values[6] && co == this -> values[7]) or 
		(co == this -> values[2] && co == this -> values[5]) or
		(co == this -> values[0] && co == this -> values[4])
	)) v = 8;
	
	
	// Czy musze sie bronic?
	
	else if (' ' == this -> values[0] && (
		(on == this -> values[1] && on == this -> values[2]) or 
		(on == this -> values[3] && on == this -> values[6]) or
		(on == this -> values[4] && on == this -> values[8])
	)) v = 0;
	
	else if (' ' == this -> values[1] && (
		(on == this -> values[0] && on == this -> values[2]) or 
		(on == this -> values[4] && on == this -> values[7])
	)) v = 1;
	
	else if (' ' == this -> values[2] && (
		(on == this -> values[0] && on == this -> values[1]) or 
		(on == this -> values[5] && on == this -> values[8]) or
		(on == this -> values[4] && on == this -> values[6])
	)) v = 2;
	
	else if (' ' == this -> values[3] && (
		(on == this -> values[0] && on == this -> values[6]) or 
		(on == this -> values[4] && on == this -> values[5])
	)) v = 3;
	
	else if (' ' == this -> values[4] && (
		(on == this -> values[1] && on == this -> values[7]) or 
		(on == this -> values[3] && on == this -> values[5]) or
		(on == this -> values[0] && on == this -> values[8]) or
		(on == this -> values[2] && on == this -> values[6])
	)) v = 4;
	
	else if (' ' == this -> values[5] && (
		(on == this -> values[2] && on == this -> values[8]) or 
		(on == this -> values[3] && on == this -> values[4])
	)) v = 5;
	
	else if (' ' == this -> values[6] && (
		(on == this -> values[0] && on == this -> values[3]) or 
		(on == this -> values[7] && on == this -> values[8]) or
		(on == this -> values[4] && on == this -> values[2])
	)) v = 6;
	
	else if (' ' == this -> values[7] && (
		(on == this -> values[6] && on == this -> values[8]) or 
		(on == this -> values[1] && on == this -> values[4])
	)) v = 7;
	
	else if (' ' == this -> values[8] && (
		(on == this -> values[6] && on == this -> values[7]) or 
		(on == this -> values[2] && on == this -> values[5]) or
		(on == this -> values[0] && on == this -> values[4])
	)) v = 8;
	
	
	return v+1;
}


bool Plansza::czyWygrywa(char co) {

	if (
		(co == this -> values[0] && co == this -> values[1] && co == this -> values[2]) or 
		(co == this -> values[3] && co == this -> values[4] && co == this -> values[5]) or
		(co == this -> values[6] && co == this -> values[7] && co == this -> values[8]) or
		
		(co == this -> values[0] && co == this -> values[3] && co == this -> values[6]) or
		(co == this -> values[1] && co == this -> values[4] && co == this -> values[7]) or
		(co == this -> values[2] && co == this -> values[5] && co == this -> values[8]) or
		
		(co == this -> values[0] && co == this -> values[4] && co == this -> values[8]) or
		(co == this -> values[2] && co == this -> values[4] && co == this -> values[6]) 
		) {
			this -> koniec = TRUE;
			this -> winner = co;
			if (co == 'O') owins++;
			else xwins++;
			return TRUE;
		}
	else return FALSE;
}


bool Plansza::czyKoniec(void) {

	if ( this -> pola > 0 && this -> koniec == FALSE && this -> winner == ' ') return FALSE;
	else return TRUE;
}




class Gra {
	
private:

	Plansza *p;
	Opcje *o;
	
public:

	int wolne;
	bool end;
	char player[2];
	int current_player;
	int tura;

	Gra() {
		
		gry++;
		o = new Opcje;
		
		p = new Plansza;
		this -> end = FALSE;
		p -> winner = ' ';
		this -> player[0] = 'O';
		this -> player[1] = 'X';
		this -> current_player = 0;
		this -> tura = 0;
		
		if (o -> checkRodzajGry() > 2) p -> rysuj();
	
	}
	
	~Gra() {
		delete (p);
		delete (o);
	}
	
	void zmianaGracza(void);
	bool gramy(void);
	
};


void Gra::zmianaGracza(void) {
	
	if (this -> current_player == 0) current_player = 1;
	else current_player = 0;
	
}

bool Gra::gramy(void) {
	
	int mode = o -> checkRodzajGry();
	
	while (!(p -> czyKoniec())) {
		
		int gdzie = -1;
		
		if (mode != 3 && this -> player[current_player] == 'O') {
			if (mode == 2) gdzie = p -> aI(this -> player[current_player]);
			//aI nie miało sugestii lub begginer
			if (gdzie == -1) o -> losowanie(&gdzie);
		} else {
			cout << "Player [" << this -> player[current_player] << "] wstaw 1-9: ";
			if (!(cin >> gdzie)) {
				gdzie = -1;
				cin.clear();
				cin.ignore();
			}
		}
		
		if (gdzie >= 1 and gdzie <= 9) {	
		
			 if (p -> wstaw(gdzie-1, this -> player[current_player])) {
				
				p -> czyWygrywa(this -> player[current_player]);
				
				//DEBUG:
				//printf("%i\n", p -> czyKoniec());
				//printf("%i\n", p -> czyWygrywa(this -> player[current_player]));
				//printf("%i\n", p -> pola);
				
				p -> rysuj();
				this -> zmianaGracza();
				
			 }
				
		}
		
	}

	if (p -> winner != ' ') cout << "Player " << p -> winner << " WYGRYWA!\n\n";
	else cout << "REMIS!\n\n";
	
	
return TRUE;

}






int main (int argc, char **argv) {
	
	cout << "\nKolko i krzyzyk v.0.1 by Bart0 (2016)";
	srand(time(NULL)); // reset dla seeda wartości losowej
	char dalej='t';
	
	while (dalej == 't' or dalej == 'T') {
		
		Gra *g;
		g = new Gra;
		
		g -> gramy();
		delete g;
		
		cout << "Jeszcze raz? [t/n]: ";
		cin >> dalej;
	}
	
	cout << "Player O: " << owins << endl;
	cout << "Player X: " << xwins << endl;
	cout << "Rozegranych gier: " << gry << endl << endl;
	
	
return 0;

}
