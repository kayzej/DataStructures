// Compute the average and standard deviation of an input set of grades.
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>         // to access the STL vector class
#include <cmath>          // to use standard math library and sqrt

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " grades-file\n";
        return 1;
    }
    
    std::ifstream grades_str(argv[1]);
    if (!grades_str) {
        std::cerr << "Can not open the grades file " << argv[1] << "\n";
        return 1;
    }
    
    std::vector<int> scores;  // Vector to hold the input scores; initially empty.
    int x;                    // Input variable
    
    // Read the scores, appending each to the end of the vector
    while (grades_str >> x) {
        scores.push_back(x);
    }
    
    // Quit with an error message if too few scores.
    if (scores.size() == 0) {
        std::cout << "No scores entered.  Please try again!" << std::endl;
        return 1; }
    
    // Compute and output the average value.
    int sum=0;           // Accumulation of the values
    for (unsigned int i = 0; i < scores.size(); ++ i) {
        sum += scores[i];
    }
    
    double average = double(sum) / scores.size();
    std::cout << "The average of " << scores.size()
    << " grades is " << std::setprecision(3)
    << average << std::endl;
    
    // Exercise:  compute and output the standard deviation.
    double stdev;
    int stdsum = 0;

    for (int i=0; i<scores.size(); ++i){
        stdsum += pow((scores[i] - average), 2);
    }
    
    stdev = sqrt(stdsum / scores.size() -1);
    
    std::cout << "The standard deviation of 10 grades is " << stdev << std::endl;
    
    return 0;
}
