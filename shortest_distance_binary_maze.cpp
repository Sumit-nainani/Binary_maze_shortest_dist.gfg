/*
Given a n * m matrix grid where each element can either be 0 or 1. 
You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. 
Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing.
*/

/*
approach;
  we will use dijekstra algorithm and do bfs 
*/
#define vt vector
#include<bits/stdc++.h>

class Solution {
  public:

    vector<pair<int,int>> v={{0,1},{1,0},{-1,0},{0,-1}};
    
    // validate function
    bool valid(int i,int j,int n,int m){
         return i>=0 && j>=0 && i<n && j<m;
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        
        vt<vt<int>> dist(n,vt<int>(m,INT_MAX));
        
        set<pair<int,pair<int,int>>> q;
        q.insert({0,{source.first,source.second}});
        dist[source.first][source.second]=0;
        int ans(0);
        
        while(!q.empty()){
            auto p=q.begin();
            int x=p->second.first;
            int y=p->second.second;
            q.erase(p);
            for(auto&it:v){
                int X=it.first+x;
                int Y=it.second+y;
                if(!valid(X,Y,n,m)) continue;
                if(grid[X][Y]==0) continue;
                if(dist[X][Y]>1+dist[x][y]){
                     dist[X][Y]=1+dist[x][y];
                     q.insert({dist[X][Y],{X,Y}});
                }
            }
        }
        return dist[destination.first][destination.second]==INT_MAX?-1:dist[destination.first][destination.second];
    }
};