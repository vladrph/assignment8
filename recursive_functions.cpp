//*****************************************************************************
//P R O G R A M	H E A D E R
//
//	Name:	Vladimir Petit-Homme

//	Z#:	Z15346795
//	Instructor:	Dr. Bullard
//	Class:	Data Structures
//	Term:	Fall 2021
//	Assignment #10a (Recursion)
//	Due Date:	November 21, 2021
//	Due Time:	11:59PM
//	Points:	25
//
//
//******************************************************************************


#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: palindrome
//Precondition:  none
//Postcondition: String word is passed the initial parameter.
//Description: This function constructs a recursive palindrome that returns true if the user inputs a palindrome
///////////////////////////////////////////////////////////////////////////////////////////////
bool palindrome(const string& s) {
    string word = s;
    string firstWord = word.substr(0,1);
    string lastWord = word.substr(word.length()-1);

 int length = s.length();

 if(length == 1) {
     return true;
 }
 if(length == 2 && firstWord == lastWord ){
     return true;
 }
 else if(firstWord!=lastWord){
     return false;
 }
if(firstWord==lastWord) {
    word = word.substr(1, word.size() - 2);

    return palindrome(word);
} else {
    return false;
}



};
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printReversel
//Precondition:  none
//Postcondition: String word is passed the initial parameter.
//Description: This function takes a users input and recursively prints the word in reverse
///////////////////////////////////////////////////////////////////////////////////////////////
string  printReversel(const string& s) {
    string word = s;
    int length = s.length();

    if(length<= 1) {
        return s;
    }else{

        return  (printReversel(word.substr(1,word.length()))+word.at(0));

    }


};
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printIterReverse
//Precondition:  none
//Postcondition: String word is passed the initial parameter. Empty string temp is created.
//Description: This function takes a users input and iteratively prints the word in reverse
///////////////////////////////////////////////////////////////////////////////////////////////
string printIterReverse(const string& s) {

    string word =s;
    string temp= "";

    for(int i = word.length()-1; i >= 0; i--){
     temp = temp + word[i];

    }
    return temp;
};



int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << " please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " is a palindrome \n";
		}
		else
		{
			cout << s << " is a not palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue (y or Y for yes; n or N for no ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}
