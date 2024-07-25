#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <Windows.h>
#include <algorithm>

#include "sort_system.h"
#include "sort_algorithms.h"

using namespace std;

void Sort_system::clear_screen()   //  pokazowo; dziala na Windows, system() nie jest dobra opcja
{
    system("cls"); // Windows

    // POSIX :  system("clear");
}

void Sort_system::print_headline()
{
    cout << R"(
    ***************************************
    Specyfikacje sortowan
    ***************************************
                                           )" << endl;
}

void Sort_system::print_menu()
{
    cout << R"(
    Wybierz:
    1. Dodaj zestaw liczb
    2. Dodaj algorytm do danego zestawu
    3. Pokaz obecne zestawy liczb
    4. Pokaz dokladna specyfikacje zestawow liczb
    5. Pokaz ranking czasowy wybranego zestawu
    6. Wyswietl sortowanie wybranego zestawu
    7. Usun wybrany zestaw liczb
    8. Usun wszystkie zestawy liczb
    0. Zakoncz dzialanie systemu
        Twoj wybor : )";
}

Sort_system::Sort_system()
{
    Sort_algorithms sort_alg;
    vector<double> test_numbers;
    vector<string> algorithm_names, units;
    vector<double> ex_times;
    pair<double, string> temp;

    test_numbers = { 232.165, 3021.54, 1234.22, 1762.26, 6769.58, 19154.2, 5680.17, 17707.1, 9494.05, 5875.7, 9669.18, 1715.12, 13992.7,
        16869, 11005.3, 3237.61, 18825, 510.603, 7782.77, 19164.5, 19207.3, 5708.83, 19727.3, 8687.68, 16938.5, 2283.87, 15694.7,
        7653.39, 10870.5, 6983.24, 7167.36, 11102.7, 10004.8, 8401.57, 12864.9, 16774.4, 6080.92, 18545.1, 13006.7, 15575,
        232.165, 3021.54, 1234.22, 1762.26, 6769.58, 19154.2, 5680.17, 17707.1, 9494.05, 5875.7, 9669.18, 1715.12, 13992.7,
        16869, 11005.3, 3237.61, 18825, 510.603, 7782.77, 19164.5, 19207.3, 5708.83, 19727.3, 8687.68, 16938.5, 2283.87, 15694.7,
        7653.39, 10870.5, 6983.24, 7167.36, 11102.7, 10004.8, 8401.57, 12864.9, 16774.4, 6080.92, 18545.1, 13006.7, 15575,
        232.165, 3021.54, 1234.22, 1762.26, 6769.58, 19154.2, 5680.17, 17707.1, 9494.05, 5875.7, 9669.18, 1715.12, 13992.7,
        16869, 11005.3, 3237.61, 18825, 510.603, 7782.77, 19164.5, 19207.3, 5708.83, 19727.3, 8687.68, 16938.5, 2283.87, 15694.7,
        7653.39, 10870.5, 6983.24, 7167.36, 11102.7, 10004.8, 8401.57, 12864.9, 16774.4, 6080.92, 18545.1, 13006.7, 15575
    };

    algorithm_names = { "bubble sort", "merge sort" };
    temp = sort_alg.bubbleSort(test_numbers);
    ex_times.push_back(temp.first);
    units.push_back(temp.second);

    temp = sort_alg.mergeSort(test_numbers);
    ex_times.push_back(temp.first);
    units.push_back(temp.second);

    default_test_data.push_back({ test_numbers, algorithm_names, ex_times, units });

    clear_screen();

    test_numbers = { 1212.9, 2128.35, 584.648, 1136.52, 1172.12, 366.52, 925.016, 466.337, 596.237, 717.681, 751.263, 1901.31, 1100.08,
        2067.11, 1431.73, 2067.58, 1090.3, 1354.9, 1049.27, 418.509, 950.614, 1199.06, 953.421, 1077.83, 2041.61, 529.766, 1186.61,
        1268.09, 1942.36, 1115.08, 502.756, 1007.77, 1095.95, 1087.4, 2144.29, 120.592, 1453.92 };

    ex_times.clear();
    units.clear();

    algorithm_names = { "quick sort", "insert sort" };
    temp = sort_alg.quickSort(test_numbers);
    ex_times.push_back(temp.first);
    units.push_back(temp.second);

    temp = sort_alg.insertSort(test_numbers);
    ex_times.push_back(temp.first);
    units.push_back(temp.second);

    default_test_data.push_back({ test_numbers, algorithm_names, ex_times, units });

    clear_screen();

    test_numbers = { 131.242, 204.703, 186.845, 50.8342, 51.9705, 87.1368, 122.615, 117.898, 209.922, 65.1305, 40.4174, 120.515, 121.349,
        60.7652, 189.909, 12.6295, 80.3156, 84.6343, 163.991, 187.169, 105.627, 155.205, 12.3313, 2.31781, 1.55098, 8.68056, 197.051,
        205.825, 35.3027, 6.62915, 177.296, 166.544, 211.332, 149.393, 2.63004,
        232.165, 3021.54, 1234.22, 1762.26, 6769.58, 19154.2, 5680.17, 17707.1, 9494.05, 5875.7, 9669.18, 1715.12, 13992.7,
        16869, 11005.3, 3237.61, 18825, 510.603, 7782.77, 19164.5, 19207.3, 5708.83, 19727.3, 8687.68, 16938.5, 2283.87, 15694.7,
        7653.39, 10870.5, 6983.24, 7167.36, 11102.7, 10004.8, 8401.57, 12864.9, 16774.4, 6080.92, 18545.1, 13006.7, 15575,
        232.165, 3021.54, 1234.22, 1762.26, 6769.58, 19154.2, 5680.17, 17707.1, 9494.05, 5875.7, 9669.18, 1715.12, 13992.7,
        16869, 11005.3, 3237.61, 18825, 510.603, 7782.77, 19164.5, 19207.3, 5708.83, 19727.3, 8687.68, 16938.5, 2283.87, 15694.7,
        7653.39, 10870.5, 6983.24, 7167.36, 11102.7, 10004.8, 8401.57, 12864.9, 16774.4, 6080.92, 18545.1, 13006.7, 15575 };

    ex_times.clear();
    units.clear();

    algorithm_names = { "merge sort" };
    temp = sort_alg.mergeSort(test_numbers);
    ex_times.push_back(temp.first);
    units.push_back(temp.second);

    default_test_data.push_back({ test_numbers, algorithm_names, ex_times, units });

    clear_screen();  
    
    ///////////////////////////////////////////////////////////////////
    
    load_data();
}

Sort_system::~Sort_system()
{
    save_data();
}

void Sort_system::add_dataset()
{
    while (1)
    {
        clear_screen();
        cout << "\t" << "***** DODAWANIE ZESTAWU LICZB *****" << endl << endl;

        int selected_operation;
        cout << endl << "\t" << "Chcesz dodac nowy zestaw liczb ? (0 - nie, pozostale cyfry - tak)  :  ";
        cin >> selected_operation;

        if (!selected_operation)
            return;

        double given_number;
        vector<double> input_numbers;
        cout << endl << endl << "\t" << "Podaj liczby do twojego zestawu (podaj 0.0 by zakonczyc wczytywanie) : " << endl << endl;

        while (1)
        {
            cin >> given_number;
            if (!given_number)
                break;
            input_numbers.push_back(given_number);
        }

        customer_data.push_back(input_numbers);

        cout << endl << endl << "\t" << "Poprawnie dodano nowy zestaw liczb!" << endl << endl;
        system("pause");
    }
}

vector<int> Sort_system::convert_from_double_array_to_integer_array(vector<double> double_numbers)
{
    vector<int> integer_numbers;
    for (auto elem : double_numbers)
        integer_numbers.push_back(int(elem));
    return integer_numbers;
}

bool Sort_system::check_if_algorithm_is_unique(vector<string> table, string alg_name)
{
    for (auto elem : table)
    {
        if (alg_name == elem)
            return false;
    }
    return true;
}

void Sort_system::add_algorithm_to_dataset()
{
    while (1)
    {
        clear_screen();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\t\t" << "***** DODAWANIE ALGORYTMU DO ZESTAWU LICZB *****" << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        print_datasets();

        int selected_dataset;

        cout << endl << "Podaj numer wybranego zestawu (Podaj 0 aby wyjsc z tej opcji) : ";
        cin >> selected_dataset;

        if (!selected_dataset)
            return;

        clear_screen();
        cout << "\t" << "***** DODAWANIE ALGORYTMU DO ZESTAWU LICZB *****" << endl << endl;

        int selected_operation;
        string alg_name;
        pair<double, string> time_and_unit;

        cout << endl << endl
            << R"(
    Algorytmy :

    1. Bubble Sort
    2. Insert Sort
    3. Bucket Sort (tylko liczby calkowite, czes ulamkowa zostanie obcieta)
    4. Merge Sort
    5. Quick Sort

    Wybierz rodzaj algorytmu sortujacego (wpisz cyfre sprzed jego nazwy)  :  )";

        cin >> selected_operation;

        Sort_algorithms sort_alg;
        switch (selected_operation)
        {
            case 1:
            {
                alg_name = "bubble sort";
                time_and_unit = sort_alg.bubbleSort(customer_data[selected_dataset - 1].numbers, false);
                break;
            }
            case 2:
            {
                alg_name = "insert sort";
                time_and_unit = sort_alg.insertSort(customer_data[selected_dataset - 1].numbers, false);
                break;
            }
            case 3:
            {
                alg_name = "bucket sort";
                time_and_unit = sort_alg.bucketSort(convert_from_double_array_to_integer_array(customer_data[selected_dataset - 1].numbers), false);
                break;
            }
            case 4:
            {
                alg_name = "merge sort";
                time_and_unit = sort_alg.mergeSort(customer_data[selected_dataset - 1].numbers, false);
                break;
            }
            case 5:
            {
                alg_name = "quick sort";                
                time_and_unit = sort_alg.quickSort(customer_data[selected_dataset - 1].numbers, false);
                break;
            }
        }

        if (!check_if_algorithm_is_unique(customer_data[selected_dataset - 1].algorithm_names, alg_name))
        {
            cout << endl << "\t" << "Wybrany zestaw posiada juz ten algorytm." << endl << endl;
            system("pause");
            continue;
        }

        customer_data[selected_dataset - 1].algorithm_names.push_back(alg_name);
        customer_data[selected_dataset - 1].execution_times.push_back(time_and_unit.first);
        customer_data[selected_dataset - 1].time_units.push_back(time_and_unit.second);

        cout << endl << endl << "\t" << "Poprawnie dodano nowy algorytm!" << endl << endl;
        system("pause");
    }
}

void Sort_system::print_datasets()
{
    cout << "\t" << "***** TWOJE ZESTAWY LICZB *****" << endl << endl;

    int number_of_dataset = 1;
    for (auto dataset : customer_data)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << number_of_dataset++ << ".   ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        for (auto number_in_dataset : dataset.numbers)
            cout << number_in_dataset << "  ";

        cout << endl << endl;
    }
    cout << endl << endl << endl;
}

void Sort_system::print_datasets_with_parameters()
{
    cout << "\t" << "***** TWOJE ZESTAWY LICZB (SPECYFIKACJA) *****" << endl << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t" << "Lp." << "  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Ilosc liczb   " << "Algorytm   " << "Czas wykonania" << endl;

    int number_of_dataset = 1;
    for (auto dataset : customer_data)
    {
        int element_it = 0;
        for (auto elem : dataset.algorithm_names)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "\t" << number_of_dataset << ".     ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << dataset.numbers.size() << "       " << elem << "      " << dataset.execution_times[element_it] << dataset.time_units[element_it] << endl; // nie dziala mi postinkrementacja
            element_it++;
        }
        number_of_dataset++;
    }
    cout << endl << endl;
}

void Sort_system::print_chosen_dataset_ranking()
{
    print_datasets();

    int selected_dataset;

    cout << endl << "Podaj numer wybranego zestawu (Podaj 0 aby wyjsc z tej opcji) : ";
    cin >> selected_dataset;

    if (!selected_dataset)
        return;

    clear_screen();

    vector<pair<int, double>> datasets_iterator_time {};

    int options_it = 1;
    for (auto time : customer_data[selected_dataset - 1].execution_times)
    {
        double converted_time = time;
        if (customer_data[selected_dataset - 1].time_units[options_it - 1] == "s")   // na ms do sortowania
            converted_time *= 1000.0;
        datasets_iterator_time.push_back(make_pair(options_it++, converted_time));
    }

    sort(datasets_iterator_time.begin(), datasets_iterator_time.end(),          // ilosc liczb nie ma znaczenia - sortowanie tylko 1 zestawu
        [](pair<int, double>& a, pair<int, double>& b)
        {
            return a.second < b.second; // to gdzie mniejszy czas
        });

    cout << "\t" << "***** RANKING CZASOW WYKONANIA WYBRANEGO ZESTAWU *****" << endl << endl;


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t" << "Numer zestawu : " << selected_dataset << "\t" << "Ilosc liczb : " << customer_data[selected_dataset - 1].numbers.size() << endl << endl;

    cout << "\t\t" << "Algorytm       " << "Czas wykonania" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    for (auto elem : datasets_iterator_time)
    {
        cout << "\t\t" << customer_data[selected_dataset - 1].algorithm_names[elem.first - 1] << "         "
            << customer_data[selected_dataset - 1].execution_times[elem.first - 1] << customer_data[selected_dataset - 1].time_units[elem.first - 1] << endl;
    }
    cout << endl << endl;
}

void Sort_system::print_sorted_chosen_dataset()
{
    int selected_dataset;
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\t\t" << "***** ZESTAW LICZB PO SORTOWANIU *****" << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    print_datasets();

    cout << endl << "Podaj numer wybranego zestawu (Podaj 0 aby wyjsc z tej opcji) : ";
    cin >> selected_dataset;

    if (!selected_dataset)
        return;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << endl << "\t" << "Zestaw nr " << selected_dataset << ")" << endl << endl;

    cout << "Liczby posortowane : " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    Sort_algorithms sort_alg;

    sort_alg.quickSort(customer_data[selected_dataset - 1].numbers);  // obojetnie ktory algrytm
}

void Sort_system::delete_all_datasets()
{
    char selected_char;
    cout << "   *** Czy chcesz usunac wszystkie dotychczasowo zapisane zesatwy liczbowe ? ***" << endl << endl
        << "\t" << "*** Zostana wczytane 3 domyslne zestawy testowe ***" << endl << endl
        << "\t" << "| (1 - tak, dowolny klawisz - nie)  :  ";

    cin >> selected_char;

    if (selected_char == '1')
    {
        customer_data.clear();
        for (auto elem : default_test_data)
            customer_data.push_back(elem);
        cout << endl << endl << "\t" << "Usunieto wszystkie zestawy liczbowe, wczytano 3 domyslne zestawy testowe" << endl << endl;
    }
}

void Sort_system::delele_chosen_dataset()
{
    int selected_dataset;

    cout << "\t" << "***** USUWANIE ZESTAWU LICZB *****" << endl << endl;

    print_datasets();

    cout << endl << "Podaj numer zestawu do usuniecia (Podaj 0 aby wyjsc z tej opcji) : ";
    cin >> selected_dataset;

    if (!selected_dataset)
        return;

    int confirmation;
    cout << endl << "Potwierdz chec usuniecia tego zestawu (0 - nie, pozostale cyfry - tak)  :  ";
    cin >> confirmation;

    if (!confirmation)
    {
        cout << endl << endl << "\t" << "Nie dokonano zadnych zmian." << endl << endl;
        return;
    }

    customer_data.erase(customer_data.begin() + selected_dataset - 1);

    cout << endl << endl << "Usunieto zestaw" << endl << endl;
}

void Sort_system::load_data()
{
    ifstream load_data_from_file("database.txt");
    if (!load_data_from_file)                       // nie istnieje taki plik
    {                            // w przypadku pierwszego odpalenia plik nie istnieje tworzymy domyslne zestawy testowe

        cout << "\t" << "Nie istnieje jeszcze plik z danymi, zostaly wczytane 3 domyslne zestawy" << endl
            << "\t" << "testowe, zapisaly sie one w systemie, jesli nie chcesz ich uzywac" << endl
            << "\t" << "wybierz opcje usun zestaw." << endl << endl;

        char temp;
        cout << endl << endl << "\t" << "Wprowadz dowolny klawisz aby otworzyc system : ";
        cin >> temp;

        for (auto elem : default_test_data)
            customer_data.push_back(elem);
        return;
    }    

    while (!load_data_from_file.eof())
    {
        string row;

        getline(load_data_from_file, row);

        if (row == "")          // ostatnia linia z pliku jest wcztywana choc jest pusta
            break;

        string data[4]{};
        vector<double> numbers;
        vector<string> alg_names, units;
        vector<double> ex_times;

        int data_index = 0;

        for (int i = 0; i < row.length(); ++i)
        {
            if (row[i] == '|') // separator danych
            {
                data_index++;
                continue;
            }
            data[data_index] += row[i];
        }
        
        string temp = "";
        for (int i = 0; i < data[0].length(); ++i)
        {
            if (data[0][i] == ' ')
            {
                numbers.push_back(stod(temp));
                temp = "";
                continue;
            }
            temp += data[0][i];
        }

        temp = "";
        for (int i = 0; i < data[1].length(); ++i)
        {
            if (data[1][i] == ',')
            {
                alg_names.push_back(temp);
                temp = "";
                continue;
            }
            temp += data[1][i];
        }

        temp = "";
        for (int i = 0; i < data[2].length(); ++i)
        {
            if (data[2][i] == ' ')
            {
                ex_times.push_back(stod(temp));
                temp = "";
                continue;
            }
            temp += data[2][i];
        }

        temp = "";
        for (int i = 0; i < data[3].length(); ++i)
        {
            if (data[3][i] == ' ')
            {
                units.push_back(temp);
                temp = "";
                continue;
            }
            temp += data[3][i];
        }
       
        customer_data.push_back({ numbers, alg_names, ex_times, units });
    }
}

void Sort_system::save_data()
{
    ofstream save_data_to_file("database.txt", ios::out | ios::trunc);

    for (auto element : customer_data)
    {
        string row;
        ostringstream connect_numbers, algoritm_names, times, time_units;
        for (auto numb : element.numbers)
            connect_numbers << numb << " ";
        for (auto name : element.algorithm_names)
            algoritm_names << name << ",";
        for (auto time : element.execution_times)
            times << time << " ";
        for (auto unit : element.time_units)
            time_units << unit << " ";

        row = connect_numbers.str() + '|' + algoritm_names.str() + '|' + times.str() + '|' + time_units.str();

        save_data_to_file << row << endl;
    }
}