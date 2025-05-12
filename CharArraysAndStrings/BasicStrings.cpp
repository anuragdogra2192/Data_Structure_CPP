#include<iostream>
#include<string>

using namespace std;

int main()
{
    //string name;
    //cin>>name; //Rememeber whitespace is a delimiter
    //cout<<name<<endl;
    /*
    If you uncomment above cin and provide input and press Enter
    Then the program print the line 21 and exits.
    Because the ENTER key would be the delimiter in the getline(), line 20
    */
    //We use getline for sentences
    //string sentence;
    //getline(cin, sentence, '@');// Set the delimter to @ to terminate cin 
    //cout<<"Sentence: "<<sentence<<endl;
    //getline(cin, sentence, '\n');//The delimiter is \n
    /*Remember cin.getline() is only for chara array.*/
    //cout<<"Sentence: "<<sentence<<endl;

    //Access
    string name = "Anurag Dogra";
    cout<<name[0]<<endl;
    cout<<name.at(0)<<endl;
    cout<<name.front()<<endl;
    cout<<name.back()<<endl;
    cout<<name.length()<<endl;

    //Check if string empty.
    if(name.empty())
    {
        cout<<"String is empty\n";
    }
    else
    {
        cout<<"String is not empty\n";
    }

    //Traverse using iterator
    auto it = name.begin();
    while(it != name.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    //Append
    string fName = "Anurag";
    string lName = "Dogra";
    cout<<fName + " " + lName<<endl;

    //Substring
    string ex = "Hello Jee kaise ho";
    cout<<ex.substr(0)<<endl;//Starts from 0th index.
    cout<<ex.substr(5)<<endl;//Starts from 5th index.
    string w = "kaise";
    //Find function
    int pos = ex.find(w); //return start pos
    cout<<"Pos: "<<pos<<endl;
    string w2 = "Kapa";
    int pos2 = ex.find(w2);
    if(pos2 == -1)
    {
        cout<<"Not found"<<endl;
    }
    //Another way
    if(ex.find(w) != string::npos)
    {
        cout<<"Found the word"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }

    //Comparsion
    string a = "Anurag";
    string b = "Dogra";
    if(a.compare(b) == 0)
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Diff"<<endl;
    }
    int num = a.compare(b);
    cout<<num<<endl;//<0 -3 means string a is smaller than b, lexicographically
    return 0;
}