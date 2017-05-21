/////////////////////////////////////////////////////////////////////////
/// \file     HammingToolbox.hpp        
/// \brief    Declaration of functions used for determining the Hamming distance between 2 strings          
/// \author   Dorian Stoica                   
/// \date     May-2017          
/////////////////////////////////////////////////////////////////////////

#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <fstream>

//************************************
// \Method:     readFile 
// \FullName:   bool readFile(const std::string& inString, std::vector<std::pair<std::string,std::string>>& stringsToBeCompared);
// \Access:     public  
// \Returns:    bool
// \brief :     Read pairs of binary strings from a file and outputs a vector of string pairs. The non-binary string
//				found in the file will not be added in the output vector
// \param[in]:  const std::string& path
// \param[out]: std::vector<std::pair<std::string,std::string>>& stringsToBeCompared
//************************************
bool readFile(const std::string& path, std::vector<std::pair<std::string,std::string>>& stringsToBeCompared);



//************************************
// \Method:    isBinary 
// \FullName:  bool isBinary(const std::string& inString);
// \Access:    public  
// \Returns:   bool
// \brief :    Determine if a string is binary
// \param[in]: const std::string& inString
//************************************
bool isBinary(const std::string& inString);



//************************************
// \Method:     computeHammingDistance
// \FullName:   bool computeHammingDistance(const std::string& inStringA, const::std::string& inStringB,int& hammingDistace);
// \Access:     public
// \Returns:    bool
// \brief :     Compute the Hamming distance between two binary strings of equal length. The method returns false if
//				one of the input strings is not binary and/or they don't have the same length
// \param[in]:  const std::string& inStringA, const::std::string& inStringB
// \param[out]: int& hammingDistance
// \param[out]: double& hammingScore
//************************************
bool computeHammingDistance(const std::string& inStringA, const::std::string& inStringB,int& hammingDistance);



//************************************
// \Method:     computeHammingDistance
// \FullName:   bool computeHammingDistance(const std::string& inStringA, const::std::string& inStringB,int& hammingDistace, double& hammingScore);
// \Access:     public
// \Returns:    bool
// \brief :     Compute the Hamming distance and the Hamming score between two binary strings of equal length. The method returns false if
//				one of the input strings is not binary and/or they don't have the same length
// \param[in]:  const std::string& inStringA, const::std::string& inStringB
// \param[out]: int& hammingDistance
// \param[out]: double& hammingScore
//************************************
bool computeHammingDistance(const std::string& inStringA, const::std::string& inStringB,int& hammingDistance, double& hammingScore);




//************************************
// \Method:     computeHammingDistance
// \FullName:   bool computeHammingDistance(const std::vector<std::pair<std::string,std::string>>& inputPairs, std::vector<int>& outDistances);
// \Access:     public
// \Returns:    bool
// \brief :     Compute the Hamming distance for every pair of strings and outputs a vector of distances. The method returns false if
//				one of the input pairs contains strings that are not binary and/or they don't have the same length
// \param[in]:  const std::vector<std::pair<std::string,std::string>>& inputPairs
// \param[out]: std::vector<int>& outDistances
//************************************
bool computeHammingDistance(const std::vector<std::pair<std::string,std::string>>& inputPairs, std::vector<int>& outDistances);