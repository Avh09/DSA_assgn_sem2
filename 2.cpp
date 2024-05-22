#include<bits/stdc++.h>
using namespace std;

typedef long long int element;

void bfs(vector<vector<pair<element,element>>>& list, vector<element>& distance, vector<element>& ans,element n, element source){
    queue<pair<element,element>>q;
    pair<element,element> p = make_pair(source,1);
    distance[source] = 0;
    q.push(p);

    while(!q.empty()){
        pair<element,element> front_p = q.front();
        q.pop();
        for(pair<element,element> neighbour : list[front_p.first]){
            if(distance[front_p.first] + neighbour.second < distance[neighbour.first]){
                distance[neighbour.first] = neighbour.second + distance[front_p.first];
                pair<element,element> updated_neighbour = make_pair(neighbour.first, distance[neighbour.first]);
                q.push(updated_neighbour);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(distance[i] != 1e9+1){
            ans[i] = distance[i];
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";
}

int main(){
    element n,m,k,u,v,w,c,p;
    cin >> n >> m >> k;
    vector<vector<pair<element,element>>>list(n+1);
    vector<element>distance(n+1,1e9+1);
    vector<element>fibre(n+1,1e9+1);
    vector<element>ans(n+1,-1);

    for(element i=0;i<m;i++){
        cin >> u >> v >> w;
        // if(u == v){
        //     continue;
        // }
        // list[u].push_back(make_pair(v,w));
        // list[v].push_back(make_pair(u,w));
            // Check if the list at index u is empty before inserting
        if(u != v){
            if(list[u].empty()) {
                list[u].push_back(make_pair(v, w));
            } 
            else{
                // Check if the pair with vertex v already exists in the list of u
                bool exists = false;
                for(const auto& pair : list[u]) {
                    if(pair.first == v){
                        exists = true;
                        if(pair.second > w){
                            list[u].push_back(make_pair(v, w));
                        }
                        break;
                    }
                }
                if(!exists){
                    list[u].push_back(make_pair(v, w));
                }
            }
        }
    }
    // for (element i = 1; i <= n; i++) {
    //     cout << "Node " << i << ": ";
    //     for (const auto& pair : list[i]) {
    //         cout << "(" << pair.first << ", " << pair.second << ") ";
    //     }
    //     cout << endl;
    // }
    bfs(list,distance,ans,n,1);
    element count = 0;

    for(element i=0;i<k;i++){
        cin >> c >> p;
        fibre[c] = p;
        if(c == 1){
            count++;
        }
        else{
            if(fibre[c] >= ans[c]){
            // cout << "vertex " << c;
            count++;
            }
        }  
    }
    cout << count;   
}
