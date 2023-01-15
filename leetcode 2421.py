class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        total=len(vals)
        graph=collections.defaultdict(set)
        for a,b in edges:
            graph[a].add(b)
            graph[b].add(a)
        visit=[0]*total
        self.result=0
        
        def DFS(node):
            visit[node]=1
            self.result+=1
            counter=Counter([vals[node]])
            for nei in graph[node]:
                if not visit[nei]: 
                    for item,freq in DFS(nei).items():
                        if item>=vals[node]:
                            self.result+=counter[item]*freq
                            counter[item]+=freq
            return counter
        
        DFS(total-1)
        return self.result
