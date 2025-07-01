/*
NStack in array

Time Complexity (push/pop/getTop): O(1) each
Summary Table:
Operation	Time Complexity
push	O(1)
pop	O(1)
getTop	O(1)

Space Complexity: O(n + s)

Don't worry if you didn't get the intuition the first time.
Dry Run to get it.
*/

#include<iostream>
using namespace std;

class NStack
{
    int* m_a;
    int* m_top;
    int* m_next;
    int m_n; //# of stacks
    int m_size; // size of mian array
    int m_freeSpot; // denotes free space index in main array.

    public:
    NStack(int n, int s) : m_n(n), m_size(s)
    {
        m_freeSpot = 0;
        m_a = new int[m_size];
        m_top = new int[m_n];
        m_next = new int[m_size];

        for(int i=0; i<m_n; i++)
        {
            m_top[i] = -1;
        }
        for(int i=0; i<m_size; i++)
        {
            m_next[i] = i+1;
        }
        m_next[m_size - 1] = -1;
    }

    bool push(int value, int m)//mth stack
    {
        if(m_freeSpot == -1)
        {
            cout<<"This Stack: "<<m<<" has overflow";
            return false;
        }
        //1. Find index
        int index = m_freeSpot;
        //2. Update the freeSpot
        m_freeSpot = m_next[index];
        //3. Insert
        m_a[index] = value;
        //4. Update next
        m_next[index] = m_top[m-1];
        //5. Update Top with the index
        m_top[m-1] = index;
        return true;//Successful
    }

    int pop(int m)//mth stack
    {
        if(m_top[m-1] == -1)
        { 
            cout<<"This Stack: "<<m<<" has underflow(empty)";
            return -1;
        }
        //1. Get Index from Top
        int index = m_top[m-1];
        //2. Update the Top wiht next element index;
        m_top[m-1] = m_next[index];
        //3. Pop the element
        int poppedElement = m_a[index];
        //2. Update the next wiht freeSpot
        m_next[index] = m_freeSpot;
        //1. Update the freeSpot
        m_freeSpot = index;
        return poppedElement; 
    }

    int getTop(int m)
    {
        if(m_top[m-1] == -1)
        {
            cout<<"Stack: "<<m<<" is empty"<<endl;
            return -1;
        }
        return m_top[m-1];
    }
    
    ~NStack()
    {
        delete[] m_a;
        delete[] m_top;
        delete[] m_next;
    }
};  

int main()
{
    NStack st(3, 6);
    cout<< st.push(10,1) <<endl;
    cout<< st.push(10,1) <<endl;
    cout<< st.push(10,1) <<endl;
    cout<< st.push(10,1) <<endl;
    cout<< st.push(14,2) <<endl;
    cout<< st.push(15,3) <<endl;
    
    cout<< st.pop(1) <<endl;
    cout<< st.pop(2) <<endl;

    return 0;
}
