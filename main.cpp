#include <iostream>
#include "DNA.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
  if (argc > 1) 
  {

    bool question = true;

    DNA dna = DNA(argv[1]);
    int works = dna.readDNAFile();
    if(works == 0)
    {
    	cout << "Exiting program due to error." << endl;
    	return 0;
    }
    dna.countProb();
    dna.printProb("andrewbauer.txt");
    dna.printProb("andrewbauer.out"); //did it as both since I can't read a .out file

    char answer;

    while(true)
    {
   		while(question)
   		{
   			cout << "Would you like to process another list? (y/n)" << endl;
   			cin >> answer;
	   		if(answer == 'n')
	   		{
	   			cout << "Thanks for using this program!" << endl;
	   			return 0;
	   		}
	   		else if (answer == 'y')
	   		{
	   			question = false;
	   		}   
	   		else
	   		{
	   			cout << "Sorry, please enter a correct response" << endl;
	   		}			
   		}
   		question = true;

   		string filename = "";

   		cout << "What's the name of your new file?" << endl;
   		cin >> filename;

   		dna = DNA(filename);
 	   works = dna.readDNAFile();
 	   if(works == 0)
 	   {
  	  		cout << "Exiting program due to error." << endl;
  	  		return 0;
    	}
  	  dna.countProb();
  	  dna.printProb(filename);
    }


    
  }
  else
  {
    cout << "Please try again and enter a file." << endl;
  }
  return 0;
}