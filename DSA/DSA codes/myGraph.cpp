#include<bits/stdc++.h>
using namespace std;
vector<list<int> > graph;  //adjacency list of graph
vector<bool> visited;
void bfs(int s)
{
    //T(n) = O(V+E)
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    while(!queue.empty())
    {
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(auto adjacent : graph[s])
        {
            if(!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}
/*
void bfs(vector<int> &bfstrav, vector<int> adj[], vector<bool> &visited, int s)
    {
        //vector<int> bfstrav;
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        while(!queue.empty())
        {
            s = queue.front();
            bfstrav.push_back(s);
            queue.pop_front();
            for(auto adjacent : adj[s])
            {
                if(!visited[adjacent])
                {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> bfstrav;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                bfs(bfstrav, adj, visited, i);
            }
        }
        //bfs(bfstrav, adj, visited, 0);
        return bfstrav;
    }
*/
void dfs(int s)
{
    //T(n) = O(V+E)
    visited[s] = true;
    cout<<s<<" ";
    list<int> :: iterator it;
    for(it = graph[s].begin(); it!= graph[s].end(); it++)
    {
        if(!visited[*it])
            dfs(*it);
    }
}
void dijkstra(vector<vector<pair<int, int>>> &wgraph, int v, int s, vector<int> &dist)
{
    dist[s] = 0;
    set<pair<int, int>> st;  //{wt, vertex}
    st.insert({0, s});
    while(!st.empty())
    {
        pair x = *(st.begin());
        st.erase(x);
        for(auto it : wgraph[x.second])
        {
            if(dist[it.first] > dist[x.second] + it.second)
            {
                st.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                st.insert({dist[it.first], it.first});
            }
        }
    }
}

vector<int> prim(vector<vector<pair<int, int>>> &wgraph, int v, int s, vector<int> &mst)
{
    mst[s] = 0;
    vector<int> mstnode;
    set<pair<int, int>> st;  //{wt, vertex}
    st.insert({0, s});
    mstnode[s] = -1;
    while(!st.empty())
    {
        pair x = *(st.begin());
        //mstnode.push_back(x.second);
        st.erase(x);
        for(auto it : wgraph[x.second])
        {
            if(mst[it.first] > it.second)
            {
                st.erase({mst[it.first], it.first});
                mst[it.first] = it.second;
                mstnode[it.first] = x.second;
                st.insert({mst[it.first], it.first});
            }
        }
    }
}

int main()
{
    int v, e; //n-number of nodes, m-number of edges
    cin>>v>>e;
    /*graph.resize(v);
    for(int i=0; i<e; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }
    visited.resize(v, false);
    int s;  //source node for graph traversal
    cin>>s;
    //bfs(s);
    dfs(s);*/
    vector<int> dist(v+1, INT_MAX), mst(v+1, INT_MAX);
    vector<vector<pair<int, int>>> wgraph(v+1);//{vertex, wt}
    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        wgraph[u].push_back({v, w});
        wgraph[v].push_back({u, w});
    }
    int s;  //source node for graph traversal
    cin>>s;
    dijkstra(wgraph, v, s, dist);
    for(int i=1; i<=v; i++)
    {
        if(dist[i] < INT_MAX)
            cout<<i<<" "<<dist[i];
        else
            cout<<i<<" "<<-1;
        cout<<endl;   
    }
    vector<int> mstnode;
    mstnode = prim(wgraph, v, s, mst);
    for(int i=0; i<v; i++)
        cout<<mstnode[i];
    for(int i=1; i<=v; i++)
    {
        if(mst[i] < INT_MAX)
            cout<<i<<" "<<mst[i];
        else
            cout<<i<<" "<<-1;
        cout<<endl;   
    }
    return 0;
}