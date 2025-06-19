#include<iostream>
using namespace std;

inline void numberShow(int num)
{
    cout<<num<<endl;
}

int main()
{
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    /**
     * Quick Note:
     * For each numberShow(10) function call there
     * will be an entry in the stack and also occupies memory.
     * And also unwinding of the stack.
     * 
     * It doesnot to make sense to call such a small function
     * so many times and having lot of stck entries. 
     * This creates an overhead too.
     * 
     * Too reduce the function calling overhead.
     * We will make this function inline.
     * Inline Keyword:
     * Instead of calling the function the statements
     * of the function are pasted in the calling function.
     * 
     * Used with small sized functions. 
     * So that executables are small (handled automatically by the compiler optimization levels
     * 
     */
    return 0;
}