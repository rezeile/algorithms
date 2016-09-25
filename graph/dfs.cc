#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define DFS_WHITE -1 
#define DFS_BLACK 1

void printThis(char* message) {
  printf("==================================\n");
  printf("%s\n", message);
  printf("==================================\n");
}

/* 
 * the vector<vector<pair<int,int>>> represents an adjacency list. The value
 * at AjacencyList[i] is a list of neighbors to the vertex i. Each neighbor
 * has two associated information, its index and its weight. This particular
 * represention is adopted from Steven and Felix Halim's Competititive 
 * Programming 3 text. 
 */

enum VisitState {VISITED = 1,UNVISITED = -1};

void dfs(int num_of_vertices,int source) {
	
}

void dfs(int source, vector<int> &dfs_num, vector<vector<pair<int,int>>> &AdjList) {
	printf(" %d", u);
	dfs_num[u] = DFS_BLACK;
	for(int j = 0; j < (int) AdjList[u].size(); j++) {
		pair<int,int> node = AdjList[u][j];
		if(dfs_num[node.first] == DFS_WHITE)
			dfs(node.first,dfs_num,AdjList);
	}
}

int main() {
	vector<vector<pair<int,int>>> AdjList;
	vector<int> dfs_num;
	
	int V;
	freopen("in-01.txt","r",stdin);
	scanf("%d",&V);
	AdjList.assign(V,vector<pair<int,int>>());
}
