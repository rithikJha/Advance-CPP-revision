#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
using std::sort;
//parseline //readfile //cellstring //printboard
//pick up each line and store it in a vector
enum class state
{ kempty, kobstacle, kclosed, kpath,kstart, kfinish };

const int delta[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

bool compare(vector<int> a, vector<int> b)
{
    int f1 = a[2]+a[3];
    int f2 = b[2]+b[3];
    return f1>f2;
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
    case state::kpath:
        return "🚗   ";
    case state::kstart:
        return "🚦   ";
    case state::kfinish:
        return "🏁   ";
    default: return "0    ";
    }
}
int heuristic(int x1,int y1,int x2,int y2)
{
    return std::abs(x2-x1)+std::abs(y2-y1);
}
bool checkvalidcell(int x,int y,vector<vector<state>> grid)
{
    bool x_on_grid = (x>=0 && x<grid.size());
    bool y_on_grid = (y>=0 && y<grid[0].size());
    if(x_on_grid && y_on_grid)
        return grid[x][y] == state::kempty;
    return false;
}
void Addtoopen(int x,int y,int g,int h,vector<vector<int>> &openlist,vector<vector<state>> grid)
{
    vector<int> node = {x,y,g,h};
    openlist.push_back(node);
    grid[x][y]=state::kclosed;
}

void expandneighbours(vector<int> curr,int goal[2],vector<vector<int>> &openlist,vector<vector<state>> grid)
{
    int x = curr[0];
    int y = curr[1];
    int g = curr[3];
    for(int i=0;i<4;i++)
    {
        int x2=x+delta[i][0];
        int y2=y+delta[i][1];
        if(checkvalidcell(x2,y2,grid))
        {
            int g2=g+1;
            int h2 = heuristic(x2,y2,goal[0],goal[1]);
            Addtoopen(x2,y2,g2,h2,openlist,grid);
        }
    }
}
void cellsort(vector<vector<int>> *v)
{
    return sort(v->begin(),v->end(),compare);
}

vector<vector<state>> search(vector<vector<state>> grid,int initial[2],int goal[2])
{
    vector<vector <int>> openlist {};
    int x=initial[0];
    int y=initial[1];
    int g=0;
    int h=heuristic(x,y,goal[0],goal[2]);
    Addtoopen(x,y,g,h,openlist,grid);
    while(openlist.size()>0)
    {
        cellsort(&openlist);
        vector<int> v = openlist.back();
        openlist.pop_back();
        x=v[0];
        y=v[1];
        grid[x][y]= state::kpath;
        if(x==goal[0] && y==goal[1])
        {
            grid[initial[0]][initial[1]]=state::kstart;
            grid[goal[0]][goal[1]]=state::kfinish;
            return grid;
        }
        expandneighbours(v,goal,openlist,grid);

    }
    cout<<"no path found";
    return vector<vector<state>> {};
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
    int initial[2]={0,0};
    int goal[2]={4,5};
    auto board = readfile("C://Users//Rithik Kumar//Documents//Adv CPP//Intro//read from file//1.board");
    printboard(board);
    auto sol = search(board,initial,goal);
    printboard(sol);

}

