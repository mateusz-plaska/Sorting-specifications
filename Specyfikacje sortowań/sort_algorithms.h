#pragma once

#include <vector>
#include <string>
#include <chrono>

using time_type = std::chrono::time_point<std::chrono::system_clock>;

//mergeSort, quickSort, bucketSort, bubbleSort, insertSort
class Sort_algorithms
{
public:
	std::pair<double, std::string> bubbleSort(std::vector<double> numbers_to_sort, bool if_display = true); //zwraca czas wykonania i jednostke, 
											// wynik sortowania wyswietlany tylko w funkcji potem liczby w kolejnosci takiej jak podczas wczytania
	std::pair<double, std::string> insertSort(std::vector<double> numbers_to_sort, bool if_display = true);
	std::pair<double, std::string> bucketSort(std::vector<int> numbers_to_sort, bool if_display = true);	// Tylko calkowite
	std::pair<double, std::string> mergeSort(std::vector<double> numbers_to_sort, bool if_display = true);
	std::pair<double, std::string> quickSort(std::vector<double> numbers_to_sort, bool if_display = true);

private:
	std::pair<double, std::string> select_time_unit(time_type start_time, time_type finish_time);
	int find_maximal_value_in_array(const std::vector<int> tab);
	int find_minimal_value_in_array(const std::vector<int> tab);
	void merge_sorting(std::vector<double> &tab, int left_index, int right_index, std::vector<double> &help_tab);
	void merge(std::vector<double> &tab, int left_index, int pivot, int right_index, std::vector<double> &help_tab);
	void quick_sorting(std::vector<double>& tab, int left_index, int right_index);
};