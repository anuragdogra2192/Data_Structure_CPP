#include<iostream>

using namespace std;

int main()
{
    int number = 0;
    char ch = number + 1 + 'A' - 1; //Masking
    cout<<ch<<" "; // A
    cout<<ch++<<" ";//Post increment i.e. A
    cout<<ch<<" ";// B
    cout<<++ch<<" ";// C
    cout<<endl;

    number = 5; //number 0 is masked to --> A
    ch = number + 1 + 'A' - 1; //Masking and printing the 6th Alphabet
    cout<<ch<<" "; // F is the outp ut

    //Lets try with smaller values
    number = 0; //number 0 is masked to --> 'a'
    ch = number + 1 + 'a' - 1; //Masking and printing the 6th Alphabet
    cout<<ch<<" ";

    cout<<endl;
    ch = 'A';
    ch = ch + 32; // to lower
    cout<<ch<<" ";// 'a'

    cout<<endl;
    ch = 'b';
    ch = ch - 32; // to upper
    cout<<ch<<" "; // 'B'

    //Also we can use functions
    cout<<endl;
    ch = 'P';
    ch = tolower(ch);// return int for lower
    cout<<ch<<endl;
    return 0;
}