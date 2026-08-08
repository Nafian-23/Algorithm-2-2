#include<iostream>
using namespace std;
vector<int> dijkstra(vector<vector<int>>adjList[],int src,int vertex){
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
 p.push({0,src});
 vector<bool>explore(vertex+1,0);
 vector<int>dis(vertex+1,INT_MAX);
 dis[src] = 0;
 while(!p.empty()){
  int node = p.top().second;
  p.pop();
  if(explore[node] == 1) continue;
  explore[node] = 1;
  for (int i = 0; i < adjList[node].size(); i++)
  {
    int neighbour = adjList[node][i][0];
    int weight = adjList[node][i][1];
    if(!explore[neighbour] && dis[node] + weight < dis[neighbour]){
      dis[neighbour] = dis[node] + weight;
      p.push({dis[neighbour],neighbour});
    }
  }
 }
 return dis;
}
int main(){
  int n,m;
  cin >> n >> m;
 vector<vector<int>>adjList[n+1];
  while(m--){
    int u,v,x;
    cin >> u  >> v >> x;
    adjList[u].push_back({v,x});
  }
  vector<int>ans = dijkstra(adjList,1,n);
  for (int i = 1; i < ans.size(); i++)
  {
    /* code */
    cout << ans[i] << " ";
  }
  

}