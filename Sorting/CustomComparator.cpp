#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> v)
{
    for(auto i : v)
    {
        cout<<i<<endl;
    }
}

void print(vector<vector<int>> v1)
{
    for(auto i : v1)
    {
        cout<<"["<<i[0]<<", "<<i[1]<<"]"<<endl;
    }
}

//Custom comparator 1
bool comp1(int&a, int&b)
{
    return a < b; 
}

//Custom comparator 2, sort w.r.t index 1
bool compForIndex1(vector<int>&a, vector<int>&b)
{
    return a[1]<b[1];
}

int main()
{
    vector<int> v = {20, 10, 55, 40, 50, 70};
    //sort(v.begin(), v.end()); //sorting in increased order
    sort(v.begin(), v.end(), comp1);
    print(v);

    vector<vector<int>> v1 = {{1,55},{3,44},{0,22},{0,11}};
    sort(v1.begin(), v1.end(), compForIndex1);
    print(v1);
    return 0;
}
