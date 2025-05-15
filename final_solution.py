from collections import deque

class Solution:
    def bfs(self, adj):
        result = []
        if not adj:
            return result

        V = len(adj)
        visited = [False] * V
        q = deque()

        q.append(0)
        visited[0] = True

        while q:
            current = q.popleft()
            result.append(current)

            for neighbor in adj[current]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    q.append(neighbor)

        return result

def main():
    tc = int(input())
    for _ in range(tc):
        V = int(input())
        adj = []

        for _ in range(V):
            line = input().strip()
            if line:
                node = list(map(int, line.split()))
            else:
                node = []
            adj.append(node)

        obj = Solution()
        ans = obj.bfs(adj)
        print(" ".join(map(str, ans)))
        print("~")

if __name__ == "__main__":
    main()
