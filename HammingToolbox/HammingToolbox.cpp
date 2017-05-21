/////////////////////////////////////////////////////////////////////////
/// \file     HammingToolbox.hpp        
/// \brief    Implementation of functions used for determining the Hamming distance between 2 strings          
/// \author   Dorian Stoica                   
/// \date     May-2017          
/////////////////////////////////////////////////////////////////////////

#include "HammingToolbox.hpp"

bool readFile(const std::string& path, std::vector<std::pair<std::string,std::string>>& stringsToBeCompared)
{

	std::string line;
	if (path.empty())
	{
		std::cout<<"Not a valid path!"<<std::endl;
		return false;
	}

	stringsToBeCompared.clear();

	std::ifstream inFile (path.c_str());
	if (inFile.is_open())
	{
		while ( getline (inFile,line) )
		{
			std::string s1="";
			std::string s2="";

			std::size_t index = line.find(" ");
			if (index!=std::string::npos)
			{
				s1 = line.substr(0,index);
				s2 = line.substr(index+1,line.size()-index);
				if (isBinary(s1) && isBinary(s2))
					stringsToBeCompared.push_back(std::make_pair(s1,s2));
				else
					std::cout<<"The pair "<<s1<<" and "<<s2<<" is not binary!"<<std::endl;
			}
		}
		inFile.close();
		return true;
	}
	else 
	{
		std::cout << "Unable to open file";
		return false;
	}
}

bool isBinary(const std::string& inString)
{
	if (inString.empty())
		return false;

	return inString.find_first_not_of("01") == std::string::npos;
}

bool computeHammingDistance(const std::string& inStringA, const::std::string& inStringB, int& hammingDistance)
{
	hammingDistance = 0;
	if (!isBinary(inStringA) || !isBinary(inStringB))
	{
		std::cout<<"Failed to compute the Hamming distance : the 2 input strings are not binary !"<<std::endl;
		return false;
	}

	if (inStringA.size() != inStringB.size())
	{
		std::cout<<"Failed to compute the Hamming distance : the 2 input strings must have equal size !"<<std::endl;
		return false;
	}
	std::vector<char> inVecA(inStringA.begin(), inStringA.end());
	std::vector<char> inVecB(inStringB.begin(), inStringB.end());

	const int size = (int)inVecA.size();
	for (int i = 0;i<size;i++)
		if (inVecA[i] != inVecB[i])
			hammingDistance++;

	return true;
}


bool computeHammingDistance(const std::string& inStringA, const::std::string& inStringB, int& hammingDistance, double& hammingScore)
{

	if (computeHammingDistance(inStringA,inStringB,hammingDistance))
	{
		hammingScore = (double)hammingDistance/inStringA.size();
		return true;
	}
	else
		return false;
}


bool computeHammingDistance(const std::vector<std::pair<std::string,std::string>>& inputPairs, std::vector<int>& outDistances)
{
	outDistances.clear();
	
	const int pairCount = (int)inputPairs.size();
	outDistances.resize(pairCount);

	for (size_t i=0;i<pairCount;i++)
	{
		int currentDist = 0;
		if (computeHammingDistance(inputPairs[i].first, inputPairs[i].second, currentDist))
			outDistances[i] = currentDist;
		else
		{
			std::cout<<"Error while computing the Hamming distance for pair #"<<i<<std::endl;
			return false;
		}
	}
	return true;
}