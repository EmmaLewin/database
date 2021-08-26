/*!
\file operation.cpp
\brief This class handles the combining of tables of molecules, returning the result
*/
#pragma once
#include <algorithm>
#include "molecules.h"

class operation
{
public:
	
	template<typename T> std::vector<T> setUnion(std::vector<T> table,std::vector<T> other) //!< combines the unqiue rows
	{
		return removeDuplicates(add(table, other));
	}

	template<typename T> std::vector<T> setUnionAll(std::vector<T> table, std::vector<T> other) //!< combines the unqiue rows
	{
		return add(table, other);
	}
	
	template<typename T> std::vector<T> intersection(std::vector<T> table, std::vector<T> other) //!< return the only common rows
	{
		return compareTable(table, other, true);
	}

	template<typename T> std::vector<T> differences(std::vector<T> table, std::vector<T> other) //!< return the only different row
	{
		table = removeDuplicates(table);
		other = removeDuplicates(other);
		return add(compareTable(table, other, false), compareTable(other, table, false));
	}

private:

	template <typename T, typename U, typename X>
	bool compareRow(molecule<T, U, X> row, molecule<T, U, X> other) //!< comapare the elements in both modecules and returns if they are the same
	{
		bool match = row.getProperty() == other.getProperty()
			&& row.getProperty2() == other.getProperty2()
			&& row.getProperty3() == other.getProperty3();
		return match;
	}

	template <typename T> std::vector<T> compareTable(std::vector<T> table, std::vector<T> other, bool equal) //!< comapare the elements in both modecules and returns if they are the same
	{
		// create a new vector to store the results
		std::vector<T> result;

		// loop through the first vector
		for (auto d : other) {
			bool matched = false;

			// loop through the second vector to compare each item against the first vector
			for (auto db : table)
				matched = compareRow(d, db) ? true : matched;

			if (matched == equal)
				result.push_back(d);
		}
		return result;
	}
	
	template <typename T> std::vector<T> removeDuplicates(std::vector<T> vec) //!< removes the duplicates in a vector
	{
		// loop through the first vector
		for (size_t i = 0; i < vec.size(); ++i) {

			// loop through the second vector to compare each item against the first vector
			for (size_t j = 0; j < vec.size(); ++j) {

				if (i != j && compareRow(vec.at(i), vec.at(j))) {
					vec.erase(vec.begin() + j);
					--j;
				}
			}
		}
		return vec;
	}
	
	template <typename T> std::vector<T> add(std::vector<T> table, std::vector<T> other) //!< combines the rows of data, other is added to table
	{
		for (auto d : other) {
			table.push_back(d);
		}
		return table;
	}
};
