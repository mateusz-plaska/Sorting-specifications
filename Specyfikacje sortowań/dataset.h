#pragma once

#include <vector>
#include <string>

struct Dataset
{
	Dataset();
	Dataset(std::vector<double> input_numbers, std::vector<std::string> alg_name = {}, std::vector<double> input_time = {}, std::vector<std::string> given_time_unit = {});

	std::vector<double> numbers;
	std::vector<std::string> algorithm_names;
	std::vector<double> execution_times;
	std::vector<std::string> time_units;
};