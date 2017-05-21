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



//************************************
// \Method:     runRobustnessTest
// \FullName:   bool runRobustnessTest(const std::string& inputData, const::std::string& refData);
// \Access:     public
// \Returns:    bool
// \brief :     Compute the Hamming distance for each pair from input data and compares the distances with the
//				values found in refData file
// \param[in]:  const std::string& inputData
// \param[in]:  const::std::string& refData
//************************************
bool runRobustnessTest(const std::string& inputData, const::std::string& refData);



//************************************
// \Method:     runMetricTest
// \FullName:   bool runMetricTest();
// \Access:     public
// \Returns:    bool
// \brief :     Compute the Hamming distance between 2 random binary strings and verify the
//				metric axioms: non-negativity, symmetry and triangle-inequality
//************************************
bool runMetricTest();