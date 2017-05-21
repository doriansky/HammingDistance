# Prerequisities
 - Visual Studio 2008 or newer
 - CMake version 3.2 or newer
# Includes
This package contains:
 - HammingToolbox : included in this folder are the sources where the main functionality is implemented and the 
   cmake file associated to the library.
 - A command-line application where the HammingToolbox.lib is integrated.
 - UnitTest : sources and cmake file required to build the application used as unit test for the above library. 
   This folder also contains an example of test data used by the unit test.
# HammingToolbox interface
The library consists several methods described below:
- readFile : Read pairs of binary strings from a file and outputs a vector of binary pairs. The non-binary pairs
found in the file are ignored
- isBinary : boolean method used for determining if a string is binary or not
 - computeHammingDistance : 
 There are three overloads for this method. The first version accepts two strings as input parameters and outputs the Hamming distance 
 between them. The second version also outputs the Hamming score. The last version takes as input a vector of string pairs and outputs a 
 vector of integers containing the Hamming distance associated to every pair. All the three overloads require binary strings of 
 equal length as inputs.
# Building the solution
- Open CMake version 3.2
- Set source code to e.g. %LOCAL_PATH\HammingDistance
- Set build folder to %BUILD_PATH%
-	Configure and generate
- Open HammingTest.sln from %BUILD_PATH%
- Set HammingTest as startup project. The application will start asking the user to enter the two binary strings and will
output the Hamming distance between them.
- Alternatively the application can be used by providing as command-line argument a path to text file which contains pairs of strings. An example of such input
file can be found in the root directory of the package ("input.txt").

# Running the unit tests

- Set UnitTest as startup project.
- Provide two paths as command line arguments: first path should point to the file which contains the input pairs. The second path should
point to the file containing reference data (i.e.  the Hamming distances between the pairs). An example of test data can be found in
the UnitTest folder.
- The unit tests will first run a robustness check, making sure that the Hamming distances provided by computeHammingDistance are the same with the ones
loaded from the reference data. The second tests consists in verifying that the Hamming distance implemented in computeHammingDistance satisfies
the metric axioms (non-negativity, symmetry and triangle-inequality).

