/* Implementation of breadth first search
 */
 #include <algorithm>
 #include <cstdio>
 #include <vector>
 #include <queue>
 using namespace std;
 
 int main() {
  	vector<vector<pair<int,int>>> AdjList;  
 	freopen("in_04.txt","r",stdin);
	int V,E;
	scanf("%d %d",&V,&E);
	
	AdjList.assign(V,vector<vector<pair<int,int>>>());
	int a,b;
	for(int i = 0; i < E; i++) {
		scanf("%d %d",&a,&b);
		AdjList[a].push_back(pair(b,0));
		AdjList[b].push_back(pair(a,0));
	}
 }

