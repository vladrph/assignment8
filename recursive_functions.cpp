#include <iostream>
#include <string>
using namespace std;

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
string  printReversel(const string& s) {
    string word = s;
    int length = s.length();

    if(length<= 1) {
        return s;
    }else{

        return  (printReversel(word.substr(1,word.length()))+word.at(0));

    }


};
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
