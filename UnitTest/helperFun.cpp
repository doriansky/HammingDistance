/////////////////////////////////////////////////////////////////////////
/// \file     helperFun.hpp          
/// \brief    Helper functions used by the unit tests            
/// \author   Dorian Stoica                   
/// \date     May-2017                 
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <time.h>
#include <sstream>
#include "HammingToolbox.hpp"


bool runRobustnessTest(const std::string& inputData, const::std::string& refData)
{
	std::vector<std::pair<std::string,std::string>> stringsToBeCompared;
	if (!readFile(inputData, stringsToBeCompared))
	{
		std::cout<<"Failed to parse the file "<<inputData<<std::endl;
		return false;
	}
	std::vector<int> distances;
	computeHammingDistance(stringsToBeCompared, distances);

	//Read reference data

	std::vector<int> refDistances;
	if (refData.empty())
	{
		std::cout<<"Not a valid path!"<<std::endl;
		return false;
	}

	std::ifstream inFile (refData.c_str());
	std::string line;
	if (inFile.is_open())
	{
		while ( getline (inFile,line) )
		{
			refDistances.push_back(std::stoi(line));
		}
		inFile.close();
	}

	if (distances != refDistances)
	{
		std::cout<<"The compute distances and the reference distances are not equal!"<<std::endl;
		return false;
	}

	return true;
}

bool runMetricTest()
{
	const int length = 20;
	srand ((unsigned int) time(NULL));
	std::string inStringA="";
	std::string inStringB="";
	std::string inStringC="";

	//Generate 3 random binary strings
	for (int i=0;i<length;i++)
	{		
		int bit = rand() % 2;//continuous random variable between 0 and 1
		std::ostringstream ss;
		ss << bit;

		inStringA.append(ss.str());
	}
	for (int i=0;i<length;i++)
	{		
		int bit = rand() % 2;
		std::ostringstream ss;
		ss << bit;
		inStringB.append(ss.str());
	}
	for (int i=0;i<length;i++)
	{		
		int bit = rand() % 2;
		std::ostringstream ss;
		ss << bit;
		inStringC.append(ss.str());
	}

	int hammingDistanceAB;
	int hammingDistanceBA;
	
	int hammingDistanceAC;
	int hammingDistanceBC;

	if (computeHammingDistance(inStringA,inStringB,hammingDistanceAB) && computeHammingDistance(inStringB,inStringA,hammingDistanceBA))
	{
		if (hammingDistanceAB < 0)
		{
			std::cout<<"Non-negativity test failed !"<<std::endl;
			return false;
		}

		if (hammingDistanceAB != hammingDistanceBA)
		{
			std::cout<<"Symmetry test failed !"<<std::endl;
			return false;
		}

		computeHammingDistance(inStringA,inStringC,hammingDistanceAC);
		computeHammingDistance(inStringB,inStringC,hammingDistanceBC);
		if (hammingDistanceAC > hammingDistanceAB+hammingDistanceBC)
		{
			std::cout<<"Trianlgle-inequality test failed !"<<std::endl;
			return false;
		}

	}


	return true;

}