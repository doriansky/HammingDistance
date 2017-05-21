/////////////////////////////////////////////////////////////////////////
/// \file     HammingTest.cpp         
/// \brief        
/// \author   Dorian Stoica                   
/// \date     May-2017          
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

#include "HammingToolbox.hpp"

int main(int argc, char **argv)
{
	//Input via configuration file
	if(argc == 2)
	{
		std::vector<std::pair<std::string,std::string>> stringsToBeCompared;
		if (!readFile(argv[1],stringsToBeCompared))
		{
			std::cout<<"Failed to parse the file "<<argv[1]<<std::endl;
			return -1;
		}
		std::vector<int> distances;
		computeHammingDistance(stringsToBeCompared, distances);
		for (size_t i=0;i<stringsToBeCompared.size();i++)
		{
			int hammingDistance;
			computeHammingDistance(stringsToBeCompared[i].first, stringsToBeCompared[i].second,hammingDistance);
			std::cout<<hammingDistance<<std::endl;
		}
		return 0;
 	}
	//User input
	else
	{
		std::string s1="";
		std::string s2="";
		do 
		{
			std::cout<<"Enter the first binary string"<<std::endl;
			std::cin>>s1;
			if (!isBinary(s1))
				std::cout<<"Not a binary string!"<<std::endl;

		} while (!isBinary(s1));

		do 
		{
			std::cout<<"Enter the second binary string"<<std::endl;
			std::cin>>s2;
			if (!isBinary(s2))
				std::cout<<"Not a binary string!"<<std::endl;

		} while (!isBinary(s2));

		int hammingDistance;
		double hammingScore;
		if (!computeHammingDistance(s1,s2,hammingDistance,hammingScore))
			return -1;
	
		std::cout<<hammingDistance<<"  "<<hammingScore<<std::endl;
	}



  return 0;
}
