#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Undirected_Graph
{
    public:
        bool** AdjMatrix;
        bool* visited;
        Undirected_Graph(int n)
        {
            AdjMatrix=new bool*[n];
            visited=new bool[n];
            for(int r=0;r<n;r++)
            {
                AdjMatrix[r]=new bool[n];
                for(int c=0;c<n;c++)
                {
                    AdjMatrix[r][c]=0;
                }
                visited[r]=0;
            }
            
        }
        void AddEdge(int src,int dest)
        {
            AdjMatrix[dest][src]=1;
            AdjMatrix[src][dest]=1;
        }
        void BFS(int src,int n)
        {
            bool visited1[n]={0};
            queue<int> gr;
            gr.push(src);
            visited1[src-1]=1; 
            while(!gr.empty())
            {
                for(int i=0;i<n;i++)
                {
                    if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==0)
                    {
                        visited1[i]=1;
                        gr.push(i+1);
                    }
                }
                cout<<gr.front()<<" ";
                gr.pop();
            }
            cout<<"\n";  
        }
        void DFS(int v,int n)
        {   
            cout<<v<<"  ";
            visited[v-1]=1;
            for(int i=0;i<n;i++)
            {
                if(AdjMatrix[v-1][i]==1 & visited[i]==0)
                {
                    DFS(i+1,n);
                }
            }
            cout<<"\n";
        }
        bool Finding_Loops(int n)
        {
            bool visited1[n]={0};
            int parents[n]={0};
            queue<int> gr;
            gr.push(1);
            visited1[1-1]=1; 
            while(!gr.empty())
            {
                for(int i=0;i<n;i++)
                {
                    if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==0)
                    {
                        visited1[i]=1;
                        gr.push(i+1);
                        parents[i]=gr.front();
                    }
                    if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==1 & parents[i]!=gr.front())
                    {
                        return 1;
                    }
                }
                gr.pop();
            }
            return 0;
        }
        void Connected_Components(int n)
        {
            bool visited1[n]={0};
            cout<<"Connected Components are:";
            for(int j=0;j<n;j++)
            {
                if(visited1[j]==0)
                {
                    cout<<"\n";
                    queue<int> gr;
                    gr.push(1);
                    visited1[1-1]=1; 
                    while(!gr.empty())
                    {
                        for(int i=0;i<n;i++)
                        {
                            if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==0)
                            {
                                visited1[i]=1;
                                gr.push(i+1);
                            }
                        }
                        cout<<gr.front()<<" ";
                        gr.pop();
                    }
                }           
            }
            cout<<"\n";  
        }
        void Printing_Edges(int n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(AdjMatrix[i][j]==1)
                    {
                        cout<<i+1<<"->"<<j+1<<"\n";
                    }
                }
            }
            cout<<"\n";
        }
};
class Directed_Graph
{
    public:
        bool** AdjMatrix;
        bool* visited;
        Directed_Graph(int n)
        {
            AdjMatrix=new bool*[n];
            for(int r=0;r<n;r++)
            {
                AdjMatrix[r]=new bool[n];
                for(int c=0;c<n;c++)
                {
                    AdjMatrix[r][c]=0;
                }
                visited[r]={0};
            }
        }
        void AddEdge(int src,int dest)
        {
            AdjMatrix[src][dest]=1;
        }
        void BFS(int src,int n)
        {
            bool visited1[n]={0};
            queue<int> gr;
            gr.push(src);
            visited1[src-1]=1; 
            while(!gr.empty())
            {
                for(int i=0;i<n;i++)
                {
                    if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==0)
                    {
                        visited1[i]=1;
                        gr.push(i+1);
                    }
                }
                cout<<gr.front()<<" ";
                gr.pop();
            }
            cout<<"\n";   
        }  
        void DFS(int v,int n)
        {   
            cout<<v<<"  ";
            visited[v-1]=1;
            for(int i=0;i<n;i++)
            {
                if(AdjMatrix[v-1][i]==1 & visited[i]==0)
                {
                    DFS(i+1,n);
                }
            }
            cout<<"\n";
        }
        bool Finding_Loops(int n)
        {
            bool visited1[n]={0};
            int parents[n]={0};
            queue<int> gr;
            gr.push(1);
            visited1[1-1]=1; 
            while(!gr.empty())
            {
                for(int i=0;i<n;i++)
                {
                    if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==0)
                    {
                        visited1[i]=1;
                        gr.push(i+1);
                        parents[i]=gr.front();
                    }
                    if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==1 & parents[i]!=gr.front())
                    {
                        return 1;
                    }
                }
                gr.pop();
            }
            return 0;
        }
        void Connected_Components(int n)
        {
            bool visited1[n]={0};
            cout<<"Connected Components are:";
            for(int j=0;j<n;j++)
            {
                if(visited1[j]==0)
                {
                    cout<<"\n";
                    queue<int> gr;
                    gr.push(1);
                    visited1[1-1]=1; 
                    while(!gr.empty())
                    {
                        for(int i=0;i<n;i++)
                        {
                            if(AdjMatrix[gr.front()-1][i]==1 & visited1[i]==0)
                            {
                                visited1[i]=1;
                                gr.push(i+1);
                            }
                        }
                        cout<<gr.front()<<" ";
                        gr.pop();
                    }
                }          
            }
            cout<<"\n";   
        }
        void Printing_Edges(int n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(AdjMatrix[i][j]==1)
                    {
                        cout<<i+1<<"->"<<j+1<<"\n";
                    }
                }
            }
            cout<<"\n";
        }
};

int Menu()
{
    int type;
    cout<<"Select One Of Them(TYPE 1/2/3/4)\n\t1.Adding Edge\n\t2.Perform Search\n\t3.Printing Edges\n\t4.Exit\n";
    cin>>type;
    return type;
}

void swap(float* a,float* b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
}

void MaxHeapify(float si[],float fi[],int i,int n)
{
    int parent=i;
    int left=2*i+1;
    int right=2*i+2;
    if(si[left]>si[parent] & left<n)
    {
        parent=left;
    }
    if(si[right]>si[parent] & right<n)
    {
        parent=right;
    }
    if(parent!=i)
    {
        swap(&si[i],&si[parent]);
        swap(&fi[i],&fi[parent]);
        MaxHeapify(si,fi,parent,n);
    }
}

void HeapSort(float si[],float fi[],int n)
{
    for(int j=n/2;j>=0;j--)
    {
        MaxHeapify(si,fi,j,n);
    }
    for(int j=n-1;j>=0;j--)
    {
        swap(&si[j],&si[0]);
        swap(&fi[j],&fi[0]);
        MaxHeapify(si,fi,0,j);
    }
}
int activityselector(float si[],float fi[],int n)
{   
    HeapSort(si,fi,n);
    int k=0;
    int count=1;
    for(int m=1;m<n;m++)
    {
        if(si[m]>=fi[k])
        {
            count++;
            k=m;
        }
    }
    return count;
}
int main()
{ 
    cout<<"\tGRAPH_QUERIES\n";
    int graph_type,nodes,first,second,src,perform_type,SRC,activities;
    bool Cycle_Finder;
    cout<<"a. Select Graph Type(TYPE 1/2)\n\t1.Directed\n\t2.Undirected\n";
    cin>>graph_type;
    cout<<"b. Input number of nodes(n):\n";
    cin>>nodes;
    if(graph_type==1)
    {
        Directed_Graph Graph1(nodes);
        int c=Menu();
        while (c!=4)
        {  
            if(c==1)
            {
                cout<<"c. Add edge (takes input two nodes between which an edge is to be established)\n";
                cout<<"Enter first vertex\n";
                cin>>first;
                cout<<"Enter second vertex\n";
                cin>>second;
                Graph1.AddEdge(first,second);
            }
            else if(c==2)
            {
                cout<<"Select Search Type(TYPE 1/2)\n\t1.BFS\n\t2.DFS\n";
                cin>>perform_type;
                cout<<"Enter the source node from which we need to start tracking the graph.(nodes start from 1)\n";
                cin>>SRC;
                if(perform_type==1)
                {
                    Graph1.BFS(SRC,nodes);
                }
                else if(perform_type==2)
                {
                    Graph1.DFS(SRC,nodes);
                }
            }
            else if(c==3)
            {
                Graph1.Printing_Edges(nodes);
            }
            c=Menu();
        }
        Cycle_Finder=Graph1.Finding_Loops(nodes);
        if(Cycle_Finder)
        {
            cout<<"There is a cycle in this graph.\n";
        }
        else
        {
            cout<<"There is no cycle in this graph.\n";
        }
        Graph1.Connected_Components(nodes);
    }
    else if(graph_type==2)
    {
        Undirected_Graph Graph2(nodes);
        int c=Menu();
        while (c!=4)
        {  
            if(c==1)
            {
                cout<<"c. Add edge (takes input two nodes between which an edge is to be established)\n";
                cout<<"Enter first vertex\n";
                cin>>first;
                cout<<"Enter second vertex\n";
                cin>>second;
                Graph2.AddEdge(first,second);
            }
            else if(c==2)
            {
                cout<<"Select Search Type(TYPE 1/2)\n\t1.BFS\n\t2.DFS\n";
                cin>>perform_type;
                cout<<"Enter the source node from which we need to start tracking the graph.(nodes start from 1)\n";
                cin>>SRC;
                if(perform_type==1)
                {
                    Graph2.BFS(SRC,nodes);
                }
                else if(perform_type==2)
                {
                    Graph2.DFS(SRC,nodes);
                }
            }
            else if(c==3)
            {
                Graph2.Printing_Edges(nodes);
            }
            c=Menu();
        }
        Cycle_Finder=Graph2.Finding_Loops(nodes);
        if(Cycle_Finder)
        {
            cout<<"There is a cycle in this graph.\n";
        }
        else
        {
            cout<<"There is no cycle in this graph.\n";
        }
        Graph2.Connected_Components(nodes);
    }
    cout<<"\t\tACTIVITY_SELECTOR\n";
    cout<<"Type No of activites(n)\n";
    cin>>activities;
    float start_time[activities];
    float finish_time[activities];
    for(int i=0;i<activities;i++)
    {
        int a,b;
        cout<<"Start giving floating point numbers in pairs of two(first start time and second end time).\n\t(9:30->9.30,6:47->6.47,3:18->3.18 etc..)\n";
        scanf("%f %f",&a,&b);
        start_time[i]=a;
        finish_time[i]=b;
    }
    cout<<activityselector(start_time,finish_time,activities)<<"\n";
}
