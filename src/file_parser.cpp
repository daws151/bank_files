#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileOutput;

    ifstream SampleFile("dec2025credit.csv");

    while (getline (SampleFile, fileOutput)) {
        cout << fileOutput << endl;
    }
    
    SampleFile.close();
    return 0;
}
