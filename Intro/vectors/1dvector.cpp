#include<iostream>
#include<vector>
using namespace std;
//Vectors are same as dynamic arrays which can resize itself whenever it wants.
int main()
{
    vector<int> v = {1,2,3,4,5};
    vector<int> v2(4,2);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<"\n";
    v.push_back(6);
    int item = v[v.size()-1];
    cout<<item;
    v.pop_back();
    for(auto i=v2.cbegin();i != v2.cend() ; ++i)
    {
        cout<<*i<<"\n";
    }
    cout<<"\nend-"<<*v.end()<<" begin-"<<*v.begin();
    cout<<"\n --"<<*(v2.end()-1); //point to element after the last
    cout<<"\n max size-"<<v2.capacity()<<"  size-"<<v2.size();
    v2.resize(2);
    cout<<"\n max size-"<<v2.capacity()<<"  size-"<<v2.size();
    v2.push_back(5);
    v2.push_back(5);
    v2.push_back(5);
    v2.push_back(5);
    v2.pop_back();
    cout<<"\n max size-"<<v2.capacity()<<"  size-"<<v2.size();
    v2.shrink_to_fit();
    cout<<"\n max size-"<<v2.capacity()<<"  size-"<<v2.size();
    v2.reserve(15);
    cout<<"\n max size-"<<v2.capacity()<<"  size-"<<v2.size();
    cout<<"\n"<<v2.front()<<v2.back()<<"\n";
    for(auto i=v2.begin() ;i != v2.end() ; i++)
    {
        cout<<*i;
    }
    v2.assign(2,10);
    cout<<"\n max size-"<<v2.capacity()<<"  size-"<<v2.size();
    for(auto i=v2.begin() ;i != v2.end() ; i++)
    {
        cout<<*i;
    }
}