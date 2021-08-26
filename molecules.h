/*!
\file molecules.h
\brief wrapper class around molecule, storing object molecule in a vector. This vector access is limited
*/
#pragma once

#include "molecule.h"
#include <vector>
#include <iostream>

template<typename T>
class molecules
{
public:

	// Initialise the object
	molecules() {} //!< initialize a null object, resulting in an empty data table
	molecules(std::vector<T> dataTable) { table = dataTable; } //!< initialize the object using a data set

	// Limited modification to the table of data
	std::vector<T> getTable() { return table; } //!< return the table to data, to be viewed, not modified 
	void clearTable() { table.clear(); } //!< empty the table of data
	void setTable(std::vector<T> other) { table = other; } //!< replace the table with a new table

	// Append the table of data
	void add(std::vector<T> other) {
		for (auto t : other) {
			table.push_back(t);
		}
	}
	void add(T row) { table.push_back(row); } //!< add a single row of data to the table
private:
	std::vector<T> table;  //!< table of data
};

