#include <iostream>
#include <vector>
#include <chrono>

#include "sort_algorithms.h"

using namespace std;

pair<double, string> Sort_algorithms::select_time_unit(time_type start_time, time_type finish_time)
{
	std::chrono::duration<double> duration_s = finish_time - start_time; // sekundy

	if (duration_s.count() >= 0.01)
		return make_pair(duration_s.count(), "s");
	
	std::chrono::duration<double, milli> duration_ms = finish_time - start_time;  // milisekundy

	return make_pair(duration_ms.count(), "ms");
}

pair<double, string> Sort_algorithms::bubbleSort(vector<double> numbers_to_sort, bool if_display)
{
	time_type start = std::chrono::system_clock::now();
	for (int i = 0; i < numbers_to_sort.size() - 1; ++i)
	{
		for (int j = 0; j < numbers_to_sort.size() - 1; ++j)
		{
			if (numbers_to_sort[j] > numbers_to_sort[j + 1])
				swap(numbers_to_sort[j], numbers_to_sort[j + 1]);
		}
	}
	time_type end = std::chrono::system_clock::now();

	pair<double, string> time_and_unit = select_time_unit(start, end);
	double duration_time = time_and_unit.first;
	string unit = time_and_unit.second;

	if (if_display)
	{
		cout << "Wynik : " << endl << endl;

		for (int i = 0; i < numbers_to_sort.size(); ++i)
			cout << numbers_to_sort[i] << " ";
		cout << endl << endl;
	}
	
	return make_pair(duration_time, unit); 
}

pair<double, string> Sort_algorithms::insertSort(vector<double> numbers_to_sort, bool if_display)
{
	time_type start = std::chrono::system_clock::now();
	for (int i = 1; i < numbers_to_sort.size(); ++i)
	{
		int j = i;
		while (j > 0 && numbers_to_sort[j] < numbers_to_sort[j - 1])
		{
			swap(numbers_to_sort[j], numbers_to_sort[j - 1]);
			j--;
		}
	}

	time_type end = std::chrono::system_clock::now();

	pair<double, string> time_and_unit = select_time_unit(start, end);
	double duration_time = time_and_unit.first;
	string unit = time_and_unit.second;

	if (if_display)
	{
		cout << "Wynik : " << endl << endl;

		for (int i = 0; i < numbers_to_sort.size(); ++i)
			cout << numbers_to_sort[i] << " ";
		cout << endl << endl;
	}

	return make_pair(duration_time, unit);
}

int Sort_algorithms::find_maximal_value_in_array(const vector<int> tab)
{
	int max_value = tab[0];
	for (int i = 1; i < tab.size(); ++i)
		max_value = max(max_value, tab[i]);
	return max_value;
}

int Sort_algorithms::find_minimal_value_in_array(const vector<int> tab)
{
	int min_value = tab[0];
	for (int i = 1; i < tab.size(); ++i)
		min_value = min(min_value, tab[i]);
	return min_value;
}

pair<double, string> Sort_algorithms::bucketSort(vector<int> numbers_to_sort, bool if_display)
{
	time_type start = std::chrono::system_clock::now();
	int max_value = find_maximal_value_in_array(numbers_to_sort);
	int min_value = find_minimal_value_in_array(numbers_to_sort);
	int difference_which_is_added = 0;

	if (min_value < 0)
		difference_which_is_added = -min_value;

	int *buckets = new int[max_value + 1 + difference_which_is_added] {};

	for (int i = 0; i < numbers_to_sort.size(); ++i)
		buckets[numbers_to_sort[i] + difference_which_is_added]++;

	int current_index_in_tab = 0;
	for (int i = 0; i <= max_value + difference_which_is_added; ++i)
	{
		for (int j = 0; j < buckets[i]; ++j)
			numbers_to_sort[current_index_in_tab++] = i - difference_which_is_added;
	}

	time_type end = std::chrono::system_clock::now();

	pair<double, string> time_and_unit = select_time_unit(start, end);
	double duration_time = time_and_unit.first;
	string unit = time_and_unit.second;

	if (if_display)
	{
		cout << "Wynik : " << endl << endl;

		for (int i = 0; i < numbers_to_sort.size(); ++i)
			cout << numbers_to_sort[i] << " ";
		cout << endl << endl;
	}

	return make_pair(duration_time, unit);
}

void Sort_algorithms::merge(vector<double> &tab, int left_index, int pivot, int right_index, vector<double> &help_tab)
{
	for (int i = left_index; i <= right_index; ++i)
		help_tab[i] = tab[i];

	int current_index_in_left_table = left_index;
	int current_index_in_right_index = pivot + 1;
	int index_in_sorted_table = left_index;

	while (current_index_in_left_table <= pivot && current_index_in_right_index <= right_index)
	{
		if (help_tab[current_index_in_left_table] <= help_tab[current_index_in_right_index])
			tab[index_in_sorted_table++] = help_tab[current_index_in_left_table++];
		else
			tab[index_in_sorted_table++] = help_tab[current_index_in_right_index++];
	}

	while (current_index_in_left_table <= pivot)
		tab[index_in_sorted_table++] = help_tab[current_index_in_left_table++];
}

void Sort_algorithms::merge_sorting(vector<double> &tab, int left_index, int right_index, vector<double> &help_tab)
{
	if (left_index != right_index)
	{
		int pivot = (left_index + right_index) / 2;
		merge_sorting(tab, left_index, pivot, help_tab);
		merge_sorting(tab, pivot + 1, right_index, help_tab);
		merge(tab, left_index, pivot, right_index, help_tab);
	}
}

pair<double, string> Sort_algorithms::mergeSort(vector<double> numbers_to_sort, bool if_display)
{
	time_type start = std::chrono::system_clock::now();
	
	vector<double> help_tab;
	help_tab.resize(numbers_to_sort.size());

	merge_sorting(numbers_to_sort, 0, numbers_to_sort.size() - 1, help_tab);

	time_type end = std::chrono::system_clock::now();

	pair<double, string> time_and_unit = select_time_unit(start, end);
	double duration_time = time_and_unit.first;
	string unit = time_and_unit.second;

	if (if_display)
	{
		cout << "Wynik : " << endl << endl;

		for (int i = 0; i < numbers_to_sort.size(); ++i)
			cout << numbers_to_sort[i] << " ";
		cout << endl << endl;
	}

	return make_pair(duration_time, unit);
}

void Sort_algorithms::quick_sorting(vector<double>& tab, int left_index, int right_index)
{
	if (left_index >= right_index)
		return;

	int pivot = tab[right_index];
	int index_of_limit = left_index;
	int current_index_of_checked_value = left_index;

	while (current_index_of_checked_value < right_index)
	{
		if (tab[current_index_of_checked_value] < pivot)
		{
			swap(tab[current_index_of_checked_value], tab[index_of_limit]);
			index_of_limit++;
		}
		current_index_of_checked_value++;
	}

	swap(tab[index_of_limit], tab[right_index]);

	quick_sorting(tab, left_index, index_of_limit - 1);
	quick_sorting(tab, index_of_limit + 1, right_index);
}

pair<double, string> Sort_algorithms::quickSort(vector<double> numbers_to_sort, bool if_display)
{
	time_type start = std::chrono::system_clock::now();

	quick_sorting(numbers_to_sort, 0, numbers_to_sort.size() - 1);

	time_type end = std::chrono::system_clock::now();

	pair<double, string> time_and_unit = select_time_unit(start, end);
	double duration_time = time_and_unit.first;
	string unit = time_and_unit.second;

	if (if_display)
	{
		cout << "Wynik : " << endl << endl;

		for (int i = 0; i < numbers_to_sort.size(); ++i)
			cout << numbers_to_sort[i] << " ";
		cout << endl << endl;
	}

	return make_pair(duration_time, unit);
}
