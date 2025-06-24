//Next smallest element
//Time Complexity: O(N)
//Space Complexity: O(N)

#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

void solve(vector<int>&v, vector<int>& ans)
{
    stack<int>st;
    st.push(-1);
    //Right to Left traverse on v.
    int n = v.size();
    for(int i = n-1; i>=0; i--)
    {
        int element = v[i];

        while(st.top() >= element)
        {
            st.pop();
        }
        //Here st.top() is smaller than element.
        //Lets store in the ans
        ans.push_back(st.top());
        //Add the current element in the stack fot next comparisions
        st.push(element);
    }
    //To get the correct sequence., reverse the ans;
    reverse(ans.begin(), ans.end());
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
    
    solve(v, ans);
    
    //Print the ans.
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}