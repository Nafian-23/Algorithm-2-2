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
  int n,m,s,d,a,b;
  cin >> n >> m >> s >> d >> a >> b;
 vector<vector<int>>adjList[n+1];
  while(m--){
    int u,v,x;
    cin >> u  >> v >> x;
    adjList[u].push_back({v,x});
    adjList[v].push_back({u,x});
  }
  int total_1 = 0;
  int total_2 = 0;
  vector<int>temp1 = dijkstra(adjList,s,n);
  int disS_A = temp1[a];
  int disS_B = temp1[b];
  vector<int>temp2 = dijkstra(adjList,a,n);
  int disA_B = temp2[b];
  vector<int>temp3 = dijkstra(adjList,b,n);
  int disB_A = temp3[a];
  int disB_D = temp3[d];
  int disA_D = temp2[d];

  total_1 = disS_A + disA_B + disB_D;
  total_2 = disS_B + disB_A + disA_D;

  cout << min(total_1,total_2) << endl;

}