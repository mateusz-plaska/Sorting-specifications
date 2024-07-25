#pragma once

#include <vector>

#include "dataset.h"

class Sort_system
{
public:
	Sort_system();  
	~Sort_system();

	void clear_screen(); 

	void print_headline(); 
	void print_menu();  

	void add_dataset();
	void add_algorithm_to_dataset();
	void print_datasets();
	void print_datasets_with_parameters();
	void print_chosen_dataset_ranking();
	void print_sorted_chosen_dataset();
	void delete_all_datasets();
	void delele_chosen_dataset();

	void load_data();
	void save_data();
	
private:
	std::vector<Dataset> customer_data;
	std::vector<Dataset> default_test_data;
	std::vector<int> convert_from_double_array_to_integer_array(std::vector<double> double_numbers);
	bool check_if_algorithm_is_unique(std::vector<std::string> table, std::string alg_name);
};
