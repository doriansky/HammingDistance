/////////////////////////////////////////////////////////////////////////
/// \file               
/// \brief              
/// \author                      
/// \date               
/////////////////////////////////////////////////////////////////////////
#include <iostream>


#include "HammingToolbox.hpp"
#include "helperFun.hpp"

int main(int argc, char **argv)
{


	if (argc != 3)
	{
		std::cout<<"The following command line arguments have to be provided:"<<std::endl;
		std::cout<<"1 - path to input data"<<std::endl;
		std::cout<<"2 - path to reference data"<<std::endl;
		return -1;
	}
	else
	{
	
		if (!runRobustnessTest(argv[1],argv[2]))
		{
			std::cout<<"Robustness test failed!"<<std::endl;
			return -1;
		}

		if (!runMetricTest())
		{
			std::cout<<"Metric test failed!"<<std::endl;
			return -1;
		}
		return 0;
	}

}


