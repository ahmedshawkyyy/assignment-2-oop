//ahmed shawky abdelhalim
//20210023
//assignment 2 problem no. 1
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	char input_sentence[100];
	char output_sentence[100];

	cout << "enter the sentence: ";
	cin.getline(input_sentence, 100); // get the input
	
	size_t len = strlen(input_sentence);
	bool previousSpace=false; //to check if the previouse char is space 
	int oPut = 0; //output index tracking 


	for (int i = 0; i < len; i++) {

		if (input_sentence[i] != ' ' || !previousSpace) { //check if the current char is not space or the previouse char isnt space
			output_sentence[oPut] = input_sentence[i]; //assign the input to output properly
			oPut++;
			previousSpace = (input_sentence[i] == ' '); 
		}
			
		
	}

	//size_t outlen = strlen(output_sentence);
	//output_sentence[oPut] = NULL;

	output_sentence[0] = toupper(output_sentence[0]);
	cout << "the corrected sentence: " << endl;
	for (int j = 0; j < oPut; j++) {
		cout << output_sentence[j];
}




}
