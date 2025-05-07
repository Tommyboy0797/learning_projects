#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;


vector <int> div_nums = {2,3,5,7,11};

bool prime_number_check(int prime){

    for (int i = 0; i < div_nums.size(); i++){
        if (div_nums[i] < prime){
            if (div_nums[i] * div_nums[i] > prime){
                cout << "Number is prime";
                return true;
            } else if (prime % div_nums[i] == 0) {
                cout << "Number not prime";
                return false;
            }
        } 
    }
}


int main(){

    prime_number_check(8);
}
