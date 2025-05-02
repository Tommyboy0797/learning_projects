#include <iostream> //  is a header file library that lets us work with input and output objects, such as cout. These header things add stuff
#include <vector> // this apparently does something
using namespace std; // means i dont need to do stuff like std::cout << "hello" and just cout << "hello"

void better_method(vector<int>&nums, int tgt) { // the better way to do this
    int size = nums.size();

    for (int j = 0; j < size; j++) {
        for (int i = j+1; i < size; i++){
            if (nums[i] + nums[j] == tgt) {
                cout << i << " " << j;
            }
        }

    }   
}

int main() { // this is the shit way to do it

   vector<int> nums = {2,7,11,15}; // in cpp you can specify the number of things in the array with [x], can be ommitted with just []   

   int target = 18;

   int index = 1;
   int indextwo = 0;
   bool found = false;


   while (found == false) {
        if (nums[index] + nums[indextwo] == target) {
            cout << index << " " << indextwo;
            found = true;
        } else {
            index += 1;
            indextwo += 1;
        }
   }
   cout << "\n";
   cout << "better method result: ";
   better_method(nums, target);
}


