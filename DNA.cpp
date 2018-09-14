#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include "DNA.h"
using namespace std;


  DNA::DNA()  //declaring default constructor
  {

  }
  
  DNA::DNA(string filename)
  {
    a = 0;
    c = 0;
    t = 0;
    g = 0;
    aa = 0;
    ac = 0;
    at = 0;
    ag = 0;
    ca = 0;
    cc = 0;
    ct = 0;
    cg = 0;
    ta = 0;
    tc = 0;
    tt = 0;
    tg = 0;
    ga = 0;
    gc = 0;
    gt = 0;
    gg = 0;
    sum = 0;
    mean = 0;
    variance = 0;
    standardDev = 0;
    numStrands = 0;
    dnaString;
    this->filename = filename;
  }

  DNA::~DNA()
  {

  }


  int DNA::readDNAFile()  //reads the dna file then gets the data from it
  {
    ifstream input(filename);


    // used https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c to figure this out
    if(input.peek() == ifstream::traits_type::eof()) //checks if file is empty by checking to see if first index is the end of the file
    {
      cout << "Seems like you chose an empty file!" << endl;
      return 0;
    }

    if(!input) //if there's no filename as input
    {
      cout << "Your file couldn't be accessed. You may want to check what you entered and retry." << endl;
      return 0; //represents failure
    }
    else
    {
      while(getline(input, dnaString))
      {
        numStrands++;
        char lastNucleo = ' ';

        for(int i = 0; i < dnaString.length(); i++)
        {
          dnaString[i] = toupper(dnaString[i]);
          if(dnaString[i] == 'A')
          {
            a++;
            if(lastNucleo == 'A')
              aa++;
            else if(lastNucleo == 'C')
              ca++;
            else if(lastNucleo == 'T')
              ta++;
            else if(lastNucleo == 'G')
              ga++;
          }
          else if(dnaString[i] == 'C')
          {
            c++;
            if(lastNucleo == 'A')
              ac++;
            else if(lastNucleo == 'C')
              cc++;
            else if(lastNucleo == 'T')
              tc++;
            else if(lastNucleo == 'G')
              gc++;
          }
          else if(dnaString[i] == 'T')
          {
            t++;
            if(lastNucleo == 'A')
              at++;
            else if(lastNucleo == 'C')
              ct++;
            else if(lastNucleo == 'T')
              tt++;
            else if(lastNucleo == 'G')
              gt++;
          }
          else if(dnaString[i] == 'G')
          {
            g++;
            if(lastNucleo == 'A')
              ag++;
            else if(lastNucleo == 'C')
              cg++;
            else if(lastNucleo == 'T')
              tg++;
            else if(lastNucleo == 'G')
              gg++;
          }
          else
          {
            cout << "Seems like you entered in a character that wasn't A,T,C, or G." << endl;
            return 0;  //represents failure
          }
          sum++;
          lastNucleo = dnaString[i];
        }
      }
    }
    input.close();
    return 1;
  }

  void DNA::countProb()
  {
    string strand;
    float x;

    mean = sum * 1.0 / numStrands;

    ifstream input(filename);
    while(getline(input, strand))
    {
      x += pow((strand.length() - mean),2);
    }

    variance = x / numStrands;

    standardDev = sqrt(variance);
  }

  void DNA::printProb(string filen)
  {
    ofstream filewriter;
    filewriter.open(filen);



    // Used https://www.geeksforgeeks.org/precision-of-floating-point-numbers-in-c-floor-ceil-trunc-round-and-setprecision/ to figure out setprecision()

    filewriter << "Total number of nucleotides: " << sum << endl;
    filewriter << "Average number of nucleotides per strand: " << fixed << setprecision(2) << mean << endl;
    filewriter << "Variance: " << fixed << setprecision(2) << variance << endl;
    filewriter << "Standard deviation: " << fixed << setprecision(2) << standardDev << endl;
    filewriter << "Strands: " << numStrands << endl;
    filewriter << "A probability: " << fixed << setprecision(2) << (a*100.0)/sum << "%" <<endl;
    filewriter << "C probability: " << fixed << setprecision(2) << (c*100.0)/sum << "%" <<endl;
    filewriter << "T probability: " << fixed << setprecision(2) << (t*100.0)/sum << "%" <<endl;
    filewriter << "G probability: " << fixed << setprecision(2) << (g*100.0)/sum << "%" <<endl;
    filewriter << "AA bigram probability: " << fixed << setprecision(2) << (aa*100.0)/sum << "%" <<endl;
    filewriter << "AC bigram probability: " << fixed << setprecision(2) << (ac*100.0)/sum << "%" <<endl;
    filewriter << "AT bigram probability: " << fixed << setprecision(2) << (at*100.0)/sum << "%" <<endl;
    filewriter << "AG bigram probability: " << fixed << setprecision(2) << (ag*100.0)/sum << "%" <<endl;
    filewriter << "CA bigram probability: " << fixed << setprecision(2) << (ca*100.0)/sum << "%" <<endl;
    filewriter << "CC bigram probability: " << fixed << setprecision(2) << (cc*100.0)/sum << "%" <<endl;
    filewriter << "CT bigram probability: " << fixed << setprecision(2) << (ct*100.0)/sum << "%" <<endl;
    filewriter << "CG bigram probability: " << fixed << setprecision(2) << (cg*100.0)/sum << "%" <<endl;
    filewriter << "TA bigram probability: " << fixed << setprecision(2) << (ta*100.0)/sum << "%" <<endl;
    filewriter << "TC bigram probability: " << fixed << setprecision(2) << (tc*100.0)/sum << "%" <<endl;
    filewriter << "TT bigram probability: " << fixed << setprecision(2) << (tt*100.0)/sum << "%" <<endl;
    filewriter << "TG bigram probability: " << fixed << setprecision(2) << (tg*100.0)/sum << "%" <<endl;
    filewriter << "GA bigram probability: " << fixed << setprecision(2) << (ga*100.0)/sum << "%" <<endl;
    filewriter << "GC bigram probability: " << fixed << setprecision(2) << (gc*100.0)/sum << "%" <<endl;
    filewriter << "GT bigram probability: " << fixed << setprecision(2) << (gt*100.0)/sum << "%" <<endl;
    filewriter << "GG bigram probability: " << fixed << setprecision(2) << (gg*100.0)/sum << "%" <<endl;

    filewriter.close();

    createDNAtoFile(filen);
  }
  

  void DNA::createDNAtoFile(string filen)    //creates the file with DNA created using probability factors 
  {
    ofstream filewriter;
    filewriter.open(filen, std::ios_base::app);

    float varA = 0;
    float varB = 0;
    float varC = 0;
    float varD = 0;
    float randPick = 0;

    string dnaSeq;

    float probA = a * 1.0 / sum * 100;
    float probC = c * 1.0 / sum * 100;
    float probT = t * 1.0 / sum * 100;
    float probG = g * 1.0 / sum * 100;

    for (int i = 0; i < 1000; i++)
    {
      varA = (float)rand() / (float)RAND_MAX;
      varB = (float)rand() / (float)RAND_MAX;
      varC = sqrt((-2 * log(varA))) * (cos(2*M_PI*varB));                             //used http://www.cplusplus.com/reference/cmath/log/ for log() or ln()
      varD = standardDev * varC + mean;


      for(int i = 0; i < (int)(varD+ 0.5); i++)
      {
        randPick = (float)(rand() % 10000) / 100;       //used as a random number picker 1-100 with 2 decimals

        if(randPick < probA)
          dnaSeq += 'A';
        else if(randPick < probA + probC)
          dnaSeq += 'C';
        else if(randPick < probA + probC + probT)
          dnaSeq += 'T';
        else if(randPick < probA + probC + probT + probG)
          dnaSeq += 'G';
      }
      filewriter << dnaSeq << endl;
    dnaSeq = "";
    }
    filewriter.close();
  }
















