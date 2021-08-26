/*!
\file main.cpp
\brief This file contains the 'main' function. Program execution begins and ends there.
*/
#pragma once
#include "operation.h"

int main()
{
	molecules<molecule<std::string, float, float>> benzazepines;
	benzazepines.add({ "Lorazepam", 0.0176, 321.158 });
	benzazepines.add({ "Temazepam", 0.0534, 300.74 });
	benzazepines.add({ "Olanzapine", 0.0942, 312.432 });
	benzazepines.add({ "Diltiazem", 0.0, 414.518 });
	benzazepines.add({ "Clobazam", 0.164, 300.74 });
	benzazepines.add({ "Clobazam", 0.164, 300.74 });
	benzazepines.add({ "Alprazolam", 0.0324, 308.765 });
	benzazepines.add({ "Chlordiazepoxide", 0.0199, 299.755 });

	molecules<molecule<std::string, float, float>> alcohols;
	alcohols.add({ "Choline", 3.61, 104.1708 });
	alcohols.add({ "Esmolol", 0.144, 295.374 });
	alcohols.add({ "Ethchlorvynol", 0.143, 144.6 });
	alcohols.add({ "Tramadol", 0.75, 263.3752 });
	alcohols.add({ "Betaxolol", 0.0298, 307.4278 });
	alcohols.add({ "Midodrine", 4.45, 254.2823 });
	alcohols.add({ "Isoetharine", 3.18, 239.3107 });

	molecules<molecule<std::string, float, float>> depressants;
	depressants.add({ "Lorazepam", 0.0176, 321.158 });
	depressants.add({ "Tramadol", 0.75, 263.3752 });
	depressants.add({ "Temazepam", 0.0534, 300.74 });
	depressants.add({ "Butabarbital", 1.39, 212.2456 });
	depressants.add({ "Morphine", 10.2, 285.3377 });
	
	molecules<molecule<std::string, float, float>> uBenDep;
	molecules<molecule<std::string, float, float>> uABenAlc;
	molecules<molecule<std::string, float, float>> iAlcDep;
	molecules<molecule<std::string, float, float>> dBenAlcDep; 

	operation control;

	uBenDep.setTable(control.setUnion(benzazepines.getTable(), depressants.getTable()));
	uABenAlc.setTable(control.setUnionAll(benzazepines.getTable(), alcohols.getTable()));
	iAlcDep.setTable(control.intersection(alcohols.getTable(), depressants.getTable()));
	dBenAlcDep.setTable(control.differences(benzazepines.getTable(), alcohols.getTable()));
	dBenAlcDep.setTable(control.differences(dBenAlcDep.getTable(), depressants.getTable()));
}
