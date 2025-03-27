#include <iostream>
#include <vector>

using namespace std;
//Column wise in wave form.
void wavePrintMatrix(vector<vector<int>> v)
{
    for(int col=0; col<v[0].size(); col++)
    {
        //if(col % 2 == 0)//even no of columns
        if((col & 1) == 0) // bitwise for even, TOP -> BOTTOM
        {
            for(int row=0; row<v.size(); row++)
            {
                cout<<v[row][col] << " ";
            }
        }
        else // odd, BOTTOM -> TOP
        {
            for(int row=v.size()-1; row>=0; row--)
            {
                cout<<v[row][col] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> v{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16},
    {17,18,19,20}};
    
    wavePrintMatrix(v);
    
    return 0;
}