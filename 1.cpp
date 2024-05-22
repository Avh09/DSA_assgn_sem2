#include<iostream>
#include<queue>
#include<utility>
using namespace std;

typedef long long int element;

void dfs(vector<vector<element>>& list, vector<element>& visited, vector<element>& result, element source,element flag, element *index){
    visited[source] = 1;
    if(flag == 0){
        flag = 1;
        result[*index] = source;
        // cout << "result[index]" << " " << result[*index] << "index " << *index << endl;
        ++(*index);
    }
    for(element neighbour : list[source]){
        if(!visited[neighbour]){
            visited[neighbour] = 1; 
            dfs(list,visited,result,neighbour,flag,index);
        }
    }
}

int main(){
    element n,m,u,v,count=0,flag=0,index=0;
    cin >> n >> m;

    vector<vector<element>>list(n+1);
    vector<element>visited(n+1,0);
    vector<element>result(2 * n);

    for(element i=1;i<=m;i++){
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    for(element i=1;i<=n;i++){
        if(!visited[i]){
            flag = 0;
            dfs(list,visited,result,i,flag,&index);
            count++;
        }
    }
    // cout << "res" << " " << result[0] << endl;
    // cout << "res" << " " << result[1] << endl;
    cout << count-1 << endl;
    for(element i=0;i<count - 1;i++){
        cout << result[i] << " " << result[i+1] << endl;
    }
}
