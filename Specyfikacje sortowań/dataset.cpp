#include "dataset.h"

using namespace std;

Dataset::Dataset() : numbers({}), algorithm_names({}), execution_times({}), time_units({})
{}

Dataset::Dataset(vector<double> input_numbers, vector<string> alg_name, vector<double> input_time, vector<string> given_time_unit) :
	numbers(input_numbers), algorithm_names(alg_name), execution_times(input_time), time_units(given_time_unit)
{}
