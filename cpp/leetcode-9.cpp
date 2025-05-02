#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;


/* for the params here, I am using const because it stops "value" from being changes
which we dont want. string& just means rather than making a copy, we work with the value
directly from memory.
*/

void is_palidrome(const string& value){ 
    string rev_string = value; // initally set to value
    reverse(rev_string.begin(), rev_string.end()); // reverse the string
    if (value == rev_string){
        cout << "Its a palindrome!!" << endl;
    } else {
        cout << "Its not a palindrome!" << endl;
    }
}

int main(){
    string user_value;
    cout << "Enter a string!: ";
    cin >> user_value;

    is_palidrome(user_value);

    return 0;
}

