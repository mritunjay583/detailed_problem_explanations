// https://leetcode.com/problems/flood-fill/submissions/
#include<bits/stdc++.h> 

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////
// //impl 1
/////////////////////////////////////////////////////////////////////////////////////
// void helper(vector<vector<int>> &image,int x,int y,int c,int r_c,int m,int n,vector<vector<int> > &dir,vector<vector<bool>> &vis){
//         if(x<0 || y<0 || x>=m||y>= n||image[x][y]!=c||vis[x][y]==true){
//             return;
//         }
//         vis[x][y]=true;
//         image[x][y]=r_c;
//         for(int i=0;i<dir.size();i++){
//             helper(image,x+dir[i][0],y+dir[i][1],c,r_c,m,n,dir,vis);
//         }
//     }
// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//     vector<vector<int> > dir{{0,1},{0,-1},{1,0},{-1,0}};
//     int m=image.size();
//     int n = image[0].size();
//     vector<vector<bool> > vis(m+1,vector<bool>(n+1,false));
//     helper(image,sr,sc,image[sr][sc],newColor,m,n,dir,vis);
//     return image;
// }

// int main(){
//     vector<vector<int> > v{{1,1,1},{1,1,0},{1,0,1}};
//     vector<vector<int> > res = floodFill(v,1,1,2);
//     for(auto x: res){
//         for(auto y:x){
//             cout<<y<<" ";
//         }
//         cout<<endl;
//     }
// }


/////////////////////////////////////////////////////////////////////////////////
// impl 2
//input:
// 9
// LLLLLLLLL
// LLWWLLWLL
// LWWLLLLLL
// LWWWLWWLL
// LLLWWWLLL
// LLLLLLLLL
// LLLWWLLWL
// LLWLWLLLL
// LLLLLLLLL
///////////////////////////////////////////////////////////////////////////////////
int dr[] = {1,1,0,-1,-1,-1, 0, 1};// S,SE,E,NE,N,NW,W,SW neighbors
int dc[] = {0,1,1, 1, 0,-1,-1,-1}; // trick to explore an implicit 2D grid graph

int floodfill(vector<vector<char>> &v,int row,int col,int old_c,int new_c,int n){
    if(row<0 || row>=n || col<0 || col>=n || v[row][col]!=old_c){
        return 0;
    }
    v[row][col]=new_c;
    int ans=1;
    for(int i=0;i<8;i++){
        ans+=floodfill(v,row+dr[i],col+dc[i],old_c,new_c,n);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    int size = floodfill(v,1,2,'W','.',n);

    cout<<"size : "<<size<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}