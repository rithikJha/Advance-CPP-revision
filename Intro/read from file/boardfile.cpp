#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
//parseline //readfile //cellstring //printboard
//pick up each line and store it in a vector
enum class state
{ kempty, kobstacle };
void writefile(string path)
{
    ofstream fout(path,ios::app);
    vector<int> v;
    fout<<endl;
    for(int i=0;i<5;i++)
    {
        v.push_back(i);
        fout<<v[i]<<",";
    }
    
    fout.close();

}
vector<state> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c;
    vector<state> row;
    while(sline>>n>>c && c==',')
    {
        if(n==0)
        row.push_back(state::kempty);
        else
        {
            row.push_back(state::kobstacle);
        }  
    }
    return row;
}
vector<vector<state>> readfile(string path)
{
    vector<vector<state>> board{};
    ifstream myfile;
    myfile.open(path);
    if(myfile)
    {
        string line;
        while(getline(myfile,line))
        {
            vector<state> row=ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}
string cellstring(state cell)
{
    switch(cell)
    {
    case state::kobstacle: return "⛰️   ";
    default: return "0    ";
    }
}
void printboard(const vector<vector<state>> board)
{
    for(auto i: board)
    {
        for(auto j: i)
        {
            cout<<cellstring(j);
        }
        cout<<"\n";
    }
}
int main()
{
    auto board = readfile("C://Users//Rithik Kumar//Documents//Adv CPP//Intro//read from file//1.board");
    printboard(board);
    writefile("C://Users//Rithik Kumar//Documents//Adv CPP//Intro//read from file//1.board");
    //auto board = readfile("C://Users//Rithik Kumar//Documents//Adv CPP//Intro//read from file//1.board");
    ifstream s("C://Users//Rithik Kumar//Documents//Adv CPP//Intro//read from file//1.board");
    string k;
    while(getline(s,k))
    {
        cout<<k<<endl;
    }

}

