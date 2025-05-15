# Graph BFS Traversal - Panduan Lengkap

## � Metadata
- **Topik**: Algoritma Graph
- **Subtopik**: BFS Traversal
- **Level**: Medium
- **Bahasa**: C++
- **Platform**: geeksforgeeks

## 🧠 Konsep Dasar
### Definisi BFS
Algoritma Breadth-First Search (BFS) menjelajahi graf level demi level dari node awal.

## AI yang Digunakan
Dalam menyelesaikan tantangan ini, saya menggunakan bantuan Deepseek AI untuk mendapatkan wawasan dan penjelasan tentang cara kerja algoritma Graph

### Komponen Penting:
1. **Queue**: Menyimpan node yang akan dikunjungi
2. **Visited Marker**: Mencegah pengulangan
3. **Adjacency List**: Representasi graf

## 💻 Implementasi Kode
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(vector<vector<int>> adj) {
    vector<int> result;
    if(adj.empty()) return result;
    
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;
    
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);
        
        for(int neighbor : adj[current]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}