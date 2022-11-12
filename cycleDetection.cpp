
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

bool cyclicU(vector<int> adj[], vector<bool> visited, int curr){
    if(visited[curr] == true) return true;
    visited[curr] = true;

    bool found = false;

    for(int i=0; i < adj[curr].size(); ++i){

        found = cyclicU(adj,visited,adj[curr][i]);

        if(found == true) return true;
    }

    return false;

}

bool cycleDetection(int nv, vector<int> adj[]){

    vector<bool> visited(nv,false);
    bool found = false;

    for(int i = 0; i< nv; i++)
    {
        visited[i] = true;

        for(int j=0; j<adj[i].size(); j++){

            found = cyclicU(adj,visited,adj[i][j]);

            if(found== true) return true;
        }

        visited[i] = false;
    }

    return false;
}

int main(){


    int v,e;

    int p,r;
    cout<<"Enter the No of Process: ";
    cin>>p;
    cout<<"\nEnter the no of Resource: ";
    cin>>r;
    v = p+r;
    //cout<<"\nEnter the no of connection : ";
    //cin>>e;


    vector<int> adj[v];
    int h,w;
    cout<<"\nEnter hold and want no: ";
    cin>>h>>w;
    e = h+w;
    /*
    for(int i = 0; i<e; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }*/

    int a,b;

    cout<<"\nEnter the process and holding resources:\n";
    for(int i=0;i<h; i++){
        cout<<"P: "; cin>>a;
        cout<<"holds R: "; cin>>b;
        adj[a-1].push_back(b-1+p);
    }

    cout<<"\nEnter the process and wanting resources:\n";
    for(int i=0;i<w; i++){
        cout<<"P: "; cin>>a;
        cout<<"wants R: "; cin>>b;
        adj[b-1+p].push_back(a-1);
    }
    for(int i = 0; i<v; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    bool f = cycleDetection(v,adj);

    if(f) cout<<"Cycle found. Deadlock happened."<<endl;
    else  cout<<"Cycle not found. No deadlock happened"<<endl;
}
