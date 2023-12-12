#include<iostream>

using namespace std;

double circleArea(double r)
{
    return (3.14*r*r);
}
int main()
{
    int r;
    cin>>r;
    cout<<"Area of circle: "<<circleArea(r)<<'\n';
    return 0;
}