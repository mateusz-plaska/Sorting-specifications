// Specyfikacje sortowań.cpp 
// Nie zaglebialem sie w dokladne sprawdzanie poprawnosci danych wejsciowych i ewentualne w zwiazku z tym 
// komunikaty oraz rzucanie wyjatkow - wystapia bledy przy niepoprwanym podaniu danych (znaki do inta,boola itp)
// 
// Czas wykonania danego algorytmu i zestawu liczb za kazdym razem moze byc inny ze wzgledy ze wzgledu iż mierzac czas korzystajac z 
// biblioteki <chrono> (działa na Linuxie i Windowsie), ktora mierzy czas rzeczywsity (calkowity czas, ktory uplynal podczas pomiaru, 
// mozna probowac zmierzyc go stoperem) dlatego pomiary moga sie roznic ze wzgledu na mozliwe zaklocenia

#include <iostream>
using namespace std;

#include "sort_system.h"

int main()
{
	system("color 3a"); // pokazowo; dziala na Windows, system() nie jest dobra opcja jednak nie zaglebialem sie w zmiane kolorow outputu w konsoli

	Sort_system sorting_sys;

	int selected_action;

	while (1)
	{
		sorting_sys.clear_screen();
		sorting_sys.print_headline();
		sorting_sys.print_menu();

		cin >> selected_action;

		if (!selected_action)
			break;
		
		char temp;
		switch (selected_action)
		{
			case 1:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.add_dataset();

				sorting_sys.save_data();		// po kazdej zmianie zapisujemy dane

				cout << endl << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
			case 2:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.add_algorithm_to_dataset();

				sorting_sys.save_data();		// po kazdej zmianie zapisujemy dane

				cout << endl << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
			case 3:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.print_datasets();

				cout << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
			case 4:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.print_datasets_with_parameters();

				cout << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
			case 5:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.print_chosen_dataset_ranking();

				cout << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
			case 6:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.print_sorted_chosen_dataset();

				cout << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
			case 7:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.delele_chosen_dataset();

				sorting_sys.save_data();		// po kazdej zmianie zapisujemy dane		

				cout << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
			case 8:
			{
				sorting_sys.clear_screen();
				sorting_sys.print_headline();

				sorting_sys.delete_all_datasets();

				sorting_sys.save_data();		// po kazdej zmianie zapisujemy dane

				cout << endl << "\t" << "Wprowadz dowolny klawisz aby wrocic do menu : ";
				cin >> temp;

				break;
			}
		}
	}

    return 0;
}


