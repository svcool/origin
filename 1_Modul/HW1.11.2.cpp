#include <iostream>
# include <string> // для string
# include <cstring> // для char
using namespace std;
/*int main(){
	char name[100];
	char word[100] = "watermelon";
  do {
	cout << "Guess the word: ";
  cin >> name;
	if (strcmp(word, name) != 0) cout << "Wrong" << endl;
	} while (strcmp(word, name) != 0);
		cout << "Right! You have won! The hidden word " << name;
		return 0;
} */
int main() {
	string name;
	string word = "watermelon";
	do {
		cout << "Guess the word: ";
		cin >> name;
		if (name != word) cout << "Wrong" << endl;
	} while (name != word);
	cout << "Right! You have won! The hidden word " << name;
	return 0;

}