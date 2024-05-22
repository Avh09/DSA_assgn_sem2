#include<bits/stdc++.h>
#include<climits>

using namespace std;
typedef long long int element;

void dijkstra(element n,vector<element>& distance,vector<vector<pair<element,element>>>& list,vector<element>& fibre,element *count, vector<element>& arr){
    element source = 1;
    distance[source] = 0;
    // wt, vertex
    set<pair<element,element>>s;
    s.insert({0,source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : list[x.second]){
            // cout << "***" << x.second << " " << it.first << " " << "\n";
            
            if(distance[it.first] > distance[x.second] + it.second){
                // if(fibre[it.first] == 1){
                //     fibre[it.first] = 0;
                //     cout << x.second << " " << it.first << " " << it.second <<" " << distance[it.first] <<" " << distance[x.second] << "\n";
                //     // (*count)--;
                // }
                s.erase({distance[it.first],it.first});
                distance[it.first] = distance[x.second] + it.second;
                s.insert({distance[it.first],it.first});
            }
            if(arr[it.first] >= distance[x.second] + it.second  && fibre[it.first] == 1 && x.second != 1){
                // cout << "^^\n";
                fibre[it.first] = 0;
                (*count)--;
                // cout << "blahh " << it.first << " " << distance[it.first] << " " << x.second << "\n";

            }
        }
    }
    // for(element i=1;i<=n;i++){
    //     if(distance[i] < LLONG_MAX){
    //         cout << distance[i] << " ";
    //     }
    //     else{
    //         cout << -1 << " ";
    //     }
    // }
    // cout << "\n";
}

int main(){
    element n,m,k,u,v,w,c,p;
    element count = 0;
    cin >> n >> m >> k;
    vector<element>distance(n+1,LLONG_MAX);
    vector<vector<pair<element,element>>>list(n+1);
    vector<element>arr(n+1,0);
    vector<element>fibre(n+1,0);

    for(element i=0;i<m;i++){
        cin >> u >> v >> w;
        if(u != v){
            if(list[u].empty()){
                list[u].push_back(make_pair(v, w));
                list[v].push_back(make_pair(u, w));
            }
            else{
                // Check if the pair with vertex v already exists in the list of u
                bool exists = false;
                for(const auto& pair : list[u]){
                    if(pair.first == v){
                        exists = true;
                        if(pair.second > w){
                            list[u].push_back(make_pair(v, w));
                            list[v].push_back(make_pair(u, w));
                            break;
                        }
                    }
                }
                if(!exists){
                    list[u].push_back(make_pair(v, w));
                    list[v].push_back(make_pair(u, w));
                }
            }
        }
    }

    // for (element i = 1; i <= n; i++) {
    //     cout << "Vertex " << i << ": ";
    //     for (const auto& pair : list[i]) {
    //         cout << "(" << pair.first << ", " << pair.second << ") ";
    //     }
    //     cout << endl;
    // }

    dijkstra(n,distance,list,fibre,&count,arr);

    element j = 1;

    for(element i=0;i<k;i++){
        cin >> c >> p;
        if(arr[c] == 0 && c != 1){
            arr[c] = p;
        }
        else{
            if(p < arr[c]){
                arr[c] = p;
            }
        }
    }
    for(element i=2;i<=n;i++){
        if(arr[i] < distance[i] && arr[i] != 0){
            // distance[i] = arr[i];
            list[i].push_back(make_pair(1,arr[i]));
            list[1].push_back(make_pair(i,arr[i]));
            fibre[i] = 1;
            count++;
            // printf("fibre : %lld -> %lld , count : %lld\n",i, arr[i],count);
        }
    }
    dijkstra(n,distance,list,fibre,&count,arr);
    // cout << "count : " << count << "\n";
    cout << k-count << "\n";

}
