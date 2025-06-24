#include<iostream>
#include<vector>
#include<stack>

using namespace std;
//Time Complexity: O(n)
//Sapce Complexity: O(n)

void prevSmallerElement(vector<int>& v, vector<int>& ans)
{
    stack<int>st;
    st.push(-1);
    int n = v.size();

    //Left to Right traverse.
    for(int i=0; i<n;i++)
    {
        int element = v[i];
        
        while(st.top() >= element)
        {
            st.pop();
        }
        //Here element >= st.top()
        //Store ans
        ans.push_back(st.top());
        //push the element in stack for next comparisons.
        st.push(element);
    }
}

int main()
{
    vector<int> v;
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    vector<int> ans;
    
    prevSmallerElement(v, ans);
    //Print the ans.
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}