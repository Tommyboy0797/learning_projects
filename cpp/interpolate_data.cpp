#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;


float get_uncorrected_ff_endurance(float gwt, float pressure_alt){

    string TOP_FOLDER = "cpp/interp_data/completed-cruise/max-endurance-fuel-flow-4-eng/";
    string FILE_NAME = "uncorrected.dig";

    std::ifstream mainfile(TOP_FOLDER + FILE_NAME);
    cout << TOP_FOLDER + FILE_NAME;

    if (mainfile.is_open() == false){
        cout << "Couldnt open file with path: " << TOP_FOLDER + FILE_NAME;
        return 1;
    }

    // INCOMPLETE !
}






int main(){

}