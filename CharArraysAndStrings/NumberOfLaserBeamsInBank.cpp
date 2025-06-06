/* Leet code 2125.
2125. Number of Laser Beams in a Bank
Anti-theft security devices are activated inside a bank.
You are given a 0-indexed binary string array bank 
representing the floor plan of the bank, 
which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.

Example 1:
Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.

Example 2:
Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.
 
Constraints:

m == bank.length
n == bank[i].length
1 <= m, n <= 500
bank[i][j] is either '0' or '1'.
*/

//Time complexity O(N^2)

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
        int countDevices(string binary)
        {
            int c = 0;
            for(auto s : binary)
            {
                c += s - '0'; // string to int '1' - '0' = 1
            }
            return c;
        }
    
        int numberOfBeams(vector<string>& bank) {
            
            vector<int> devices;
            for(auto binary : bank)
            {
                devices.push_back(countDevices(binary));
            }
    
            int beams = 0;
            int i = 0; 
            int j = 1; 
            //In case first row contains no devices
            if(devices[i] == 0)
            {
                    i++;
                    j = i+1;
            }
            while(i<j && j<devices.size())
            {   
                if(devices[j] == 0)
                {
                    j++;
                }
                else
                {
                    beams += devices[i] * devices[j];
                    i = j;
                    j++;
                }
            }
            return beams;
        }
    };
    