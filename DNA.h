#include <iostream>
using namespace std;

class DNA
{
  public:
    DNA();
    DNA(string filename);
    ~DNA();
    int readDNAFile();
    void countProb();
    void printProb(string filen);
    void createDNAtoFile(string filen);
    

  private:
    int a;
    int c;
    int t;
    int g;
    int aa;
    int ac;
    int at;
    int ag;
    int ca;
    int cc;
    int ct;
    int cg;
    int ta;
    int tc;
    int tt;
    int tg;
    int ga;
    int gc;
    int gt;
    int gg;
    int sum;
    float mean;
    float variance;
    float standardDev;
    int numStrands;
    string dnaString;
    string filename;
};