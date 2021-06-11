#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <thread>
#include <cstdio>


using namespace std;

void tamagotchi();
void Karmienie_zwierzaka();
void Zabawa_z_zwierzakiem();
void Rozmowa_z_zwierzakiem();
void Czas();
void Statystyki();
void exit();

//////////////////////////
string name, wellbeing;
int hunger, bored, time1=0;
/////////////////////////

int main() {



	ifstream plik("nowy.txt");

	if(plik)
	{
   		for(int i = 0;i<3;i++)
   		{
   			plik >> name;
			plik >> hunger;
			plik >> bored;
			plik >> wellbeing;
		}

		/*	cout << "Imie " << name << endl;
			cout << "Glod " << hunger << endl;
			cout << "Znudzenie " << bored << endl;
			cout << "Samopoczucie " << wellbeing << endl;
		*/

		tamagotchi();


	}
	else
  	{
  		ofstream plik("nowy.txt");

  		cout << "Jak bedzie nazywal sie twoj pupil: \t";
  		cin >> name;

  		plik << name << endl;

  		hunger = 0;
  		bored = 0;
  		wellbeing = "bardzo_szczesliwy";

  		plik << hunger << endl;
  		plik << bored << endl;
  		plik << wellbeing << endl;

  		tamagotchi();

	}

	return 0;
}

void tamagotchi()
{
    system("cls");

    time1 = clock()/1000;

//       cout << "Czas \t" << time1 << endl;

  std::thread t(Czas);
   // t.join();
	int choice;


	cout << endl;
	cout << endl;

	cout << " 1. Karmienie zwierzaka " << endl;
	cout << " 2. Zabawa z zwierzakiem " << endl;
	cout << " 3. Rozmowa z zwierzakiem " << endl;
	cout << " 4. Wyswietlenie statystyk zwierzaka " << endl;
	cout << " 5. Exit " << endl;

	cout << endl;

	cout << "Wybierz (1-5): \t";
	cin >> choice;

	while(choice < 1 || choice > 5 )
	{
		cout << "Podano zly numer." << endl;
		cout << "Wybierz (1-4): \t";
		cin >> choice;
	}


    switch(choice)
	{
		case 1: Karmienie_zwierzaka(); break;
		case 2: Zabawa_z_zwierzakiem(); break;
		case 3: Rozmowa_z_zwierzakiem(); break;
		case 4: Statystyki(); break;
		case 5: exit(); break;
	}
}

void Karmienie_zwierzaka()
{
    system("cls");
	int random, choosen, t=0;
	cout << " Karmienie zwierzaka." << endl;
	Sleep( 2000 );
	cout << " " << name << " swoje ulubione jedzenie czyma w kuchenej szafce.... " << endl;
	Sleep( 2000 );
	cout << " Ale ktos zamknol ja na kludke." << endl;
	Sleep( 2000 );
	cout << " Twoim zadnaie jest zgadnac cztero cyfrowy kod.  Powodzenia!" << endl;
	Sleep( 3000 );

	system("cls");


	for(int i =1; i<=4;i++)
	{
		srand(time(NULL));
		random = 1 + rand() % (3-1+1);
		cout << " Runda: " << i << endl;
		cout << endl;


	//	cout << "Wylosowana: " << random << endl;

		do
		{
			cout << " Podaj liczbe: \t";
			cin >> choosen;



			if(random == choosen)
			{
				cout << "Udalo ci sie odgadnac liczbe! " << endl;
				cout << endl;
				t=0;
			}
			else
			{
				if(choosen < random)
				{
					cout << "Podaj wiekszom liczbe." << endl;
					t=1;
				}
				else
				{
					cout << "Podaj mniejsza liczbe." << endl;
					t=1;
				}
			}
		}while(t==1);
	}

		Sleep( 1000 );

		hunger = 0;
		cout << "Udalo ci sie nakarmic swojego pupila. " << endl;
		Sleep( 3000 );
		system("cls");


		tamagotchi();
}

void Zabawa_z_zwierzakiem()
{
	system("cls");
	cout << "Zabawa z zwierzakiem" << endl;
	Sleep( 1000 );
	cout << " Twoj pupil wymaga specjalenj troski...  " << endl;
	Sleep( 2000 );
	cout << " Dlatego zeby mu sie nie nudzilo zagraj z nim w paier, kamien, nozyce." << endl;
	Sleep( 5000 );
	cout << " Niech wygra lepszy. " << endl;
	Sleep( 2000 );
	system("cls");

	int yourchoice, choice, yourpoints=0, points=0;

	for(int i=1;i<4;i++)
	{
		srand(time(NULL));

		cout << "Runda: " << i << endl;

		choice = 1 + rand() % (3-1+1);

	//	cout << "Boot wybra³: " << choice << endl;

		cout << endl;
		cout << endl;
		cout << " 1. Kamien " << endl;
		cout << " 2. Papier " << endl;
		cout << " 3. Nozyce " << endl;
		cout << endl;

		cout << "Wybierz (1-3): \t";
		cin >> yourchoice;

		while(yourchoice < 1 || yourchoice > 3 )
		{
			cout << "Podano zly numer." << endl;
			cout << "Wybierz (1-3): \t";
			cin >> yourchoice;
		}

		if(yourchoice == 1)
		{
			cout << "\n Wybrales kamien." << endl;
		}

		if(yourchoice == 2)
		{
			cout << "\n Wybrales papier." << endl;
		}

		if(yourchoice == 3)
		{
			cout << "\n Wybrales nozyce." << endl;
		}


		if(choice == 1)
		{
			cout << "\n" << name << " wybral kamien." << endl;
		}

		if(choice == 2)
		{
			cout << "\n" << name << " wybral papier." << endl;
		}

		if(choice == 3)
		{
			cout << "\n" << name << " wybral nozyce." << endl;
		}
	//////////////////////////////////////////////////////////////////
		if(yourchoice == 1 && choice == 1)
		{
			cout << "\n Remis" << endl;
		}

		if(yourchoice == 1 && choice == 2)
		{
			cout << "\n" << name << " zdobywa punkt." << endl;
			points++;
		}

		if(yourchoice == 1 && choice == 3)
		{
			cout << "\n Ty zdobywasz punkt." << endl;
			yourpoints++;
		}
	////////////////////////////////////////////////////////////////////

	if(yourchoice == 2 && choice == 1)
		{
			cout << "\n Ty zdobywasz punkt." << endl;
			yourpoints++;
		}

		if(yourchoice == 2 && choice == 2)
		{
			cout << "\n Remis" << endl;
		}

		if(yourchoice == 2 && choice == 3)
		{
			cout << "\n" << name << " zdobywa punkt." << endl;
			points++;
		}

	/////////////////////////////////////////////////////////////////////

		if(yourchoice == 3 && choice == 1)
		{
			cout << "\n" << name << " zdobywa punkt." << endl;
			points++;
		}

		if(yourchoice == 3 && choice == 2)
		{
			cout << "\n Ty zdobywasz punkt." << endl;
			yourpoints++;
		}

		if(yourchoice == 3 && choice == 3)
		{
			cout << "\n Remis" << endl;
		}
	//////////////////////////////////////////////////////////////////////////

		cout << "\t\t Punkty: " << endl;
		cout << "\t\t Ty: " << yourpoints << endl;
		cout << "\t\t " << name << ": " <<  points << endl;
	}

	if( yourpoints == points)
	{
		cout << endl;
		cout << "Remis!"<< endl;
	}
	else
	{
		if(yourpoints>points)
		{
			cout << endl;
			cout << "Wygrales!" << endl;
		}
		else
		{
			cout << endl;
			cout << name << " wygral!" << endl;
		}
	}

	bored = 0;

	Sleep( 3000 );
	system("cls");


	tamagotchi();

}

void Rozmowa_z_zwierzakiem()
{
	string wellbeing1;

	if(hunger == 4 && bored == 4)
	{
		wellbeing = "bardzo_smutny";
		wellbeing1 = "bardzo smutny";
	}
	else
    {
        if(hunger < 4 && bored == 4)
        {
            wellbeing = "bardzo_smutny";
            wellbeing1 = "bardzo smutny";
        }
        else
        {
            if(hunger == 4 && bored < 4)
            {
                wellbeing = "bardzo_smutny";
                wellbeing1 = "bardzo smutny";
            }
        }
    }

	if(hunger == 3 && bored == 3)
	{
		wellbeing = "smutny";
		wellbeing1 = "smutny";
	}
	else
	{
		if(hunger < 3 && bored == 3)
		{
			wellbeing = "smutny";
			wellbeing1 = "smutny";
		}
		else
		{
			if(hunger == 3 && bored < 3)
			{
				wellbeing = "smutny";
				wellbeing1 = "smutny";
			}
		}
	}
////////////////////////////////////////////////
	if(hunger == 2 && bored == 2)
	{
		wellbeing = "obojetny";
		wellbeing1 = "obojetny";
	}
	else
	{
		if(hunger < 2 && bored == 2)
		{
			wellbeing = "obojetny";
			wellbeing1 = "obojetny";
		}
		else
		{
			if(hunger == 2 && bored < 2)
			{
				wellbeing = "obojetny";
				wellbeing1 = "obojetny";
			}
		}
	}
/////////////////////////////////////////////////////
	if(hunger == 1 && bored == 1)
	{
		wellbeing = "szczesliwy";
		wellbeing1 = "szczesliwy";
	}
	else
	{
		if(hunger < 1 && bored == 1)
		{
			wellbeing = "szczesliwy";
			wellbeing1 = "szczesliwy";
		}
		else
		{
			if(hunger == 1 && bored < 1)
			{
				wellbeing = "szczesliwy";
				wellbeing1 = "szczesliwy";
			}
		}
	}

	if(hunger == 0 && bored == 0)
	{
		wellbeing = "bardzo_szczesliwy";
		wellbeing1 = "bardzo szczesliwy";
	}

	system("cls");

		system("COLOR 01");
		cout << "              ###########" << endl;
		Sleep( 500 );
		system("COLOR 02");
		cout << "            ###############" << endl;
		Sleep( 500 );
		system("COLOR 03");
		cout << "          ###################" << endl;
		Sleep( 500 );
		system("COLOR 04");
		cout << "        #######################" << endl;
		Sleep( 500 );
		system("COLOR 05");
		cout << "      ###########################" << endl;
		Sleep( 500 );
		system("COLOR 06");
		cout << "    ###############################" << endl;
		Sleep( 500 );
		system("COLOR 07");
		cout << "  ###################################" << endl;
		Sleep( 500 );
		system("COLOR 08");
		cout << "  ###################################" << endl;
		Sleep( 500 );
		system("COLOR 09");
		cout << "  ###################################" << endl;
		Sleep( 500 );
		system("COLOR 0A");
		cout << "    ###############################" << endl;
		Sleep( 500 );
		system("COLOR 0B");
		cout << "      ###########################" << endl;
		Sleep( 500 );
		system("COLOR 0C");
		cout << "        #######################" << endl;
		Sleep( 500 );
		system("COLOR 0D");
		cout << "          ###################" << endl;
		Sleep( 500 );
		system("COLOR 0E");
		cout << "            ###############" << endl;
		Sleep( 500 );
		system("COLOR 0F");

		cout << "\n\n";
		cout << "\t" << name << " jest " <<	wellbeing1 << "." << endl;

		Sleep( 2000 );
		system("cls");
		tamagotchi();

//	cout << "Stan pupila: " << wellbeing << endl;


}

void Czas()
{
           Sleep(600000);

    if(hunger<=3 || bored<=3)
        {

           if(hunger<=3)
            {
                hunger++;
            }

            if(bored<=3)
            {
                bored++;
            }
        }
}

void Statystyki()
{
    system("cls");
	cout << "Imie: " << name << endl;
	Sleep(1000);
	cout << "Poziom glod: " << hunger << "/4"<< endl;
	Sleep(1000);
	cout << "Stopien znudzenia: " << bored << "/4" << endl;
//	cout << "Odczuwane samopoczucie: " << wellbeing << endl;
	Sleep(3000);
	tamagotchi();
}

void exit()
{
		ofstream plik("nowy.txt");
		plik << name << endl;
		plik << hunger << endl;
  		plik << bored << endl;
  		plik << wellbeing << endl;
  		//system("PAUSE");
  		exit( 0 );
}
