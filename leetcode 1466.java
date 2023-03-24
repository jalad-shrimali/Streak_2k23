class Solution
{
    public int minReorder(int n, int[][] connections) 
    {
        HashMap<Integer, HashSet<Integer>> IN_DEG = new HashMap<Integer, HashSet<Integer>>();
        HashMap<Integer, HashSet<Integer>> OUT_DEG = new HashMap<Integer, HashSet<Integer>>();
        HashSet<Integer> visited = new HashSet<Integer>();
        for(int key = 0; key < n; ++key)
        {
            IN_DEG.put(key,new HashSet<Integer>());
            OUT_DEG.put(key,new HashSet<Integer>());
        }
        // conns = [1,0] means 1 (src) has an outdegree to 0 ( dst)
        for(int i = 0; i < connections.length; ++i)
        {
            int[] conns = connections[i];
            int src = conns[0];
            int dst = conns[1];
            IN_DEG.get(dst).add(src);
            OUT_DEG.get(src).add(dst);
        }
        int start_node = 0;
        int numEdges = dfs(start_node,IN_DEG,OUT_DEG, visited);
        return numEdges;
    }
    
    public int dfs(int nodeID, HashMap<Integer, HashSet<Integer>> IN_DEG, HashMap<Integer, HashSet<Integer>> OUT_DEG, HashSet<Integer> visited)
    {
        if(visited.contains(nodeID))
            return 0;
        visited.add(nodeID);
        int count = 0;
        HashSet<Integer> outDeg = OUT_DEG.get(nodeID); 
        HashSet<Integer> inDeg = IN_DEG.get(nodeID);
        if(outDeg != null && outDeg.size() > 0)
        {
            for(int outChild : outDeg)
                if(!visited.contains(outChild))
                    count += (1 + dfs(outChild, IN_DEG, OUT_DEG, visited));                
        }
        if(inDeg != null && inDeg.size() > 0)
        {
            for(int inChild : inDeg)
                if(!visited.contains(inChild))
                    count += dfs(inChild, IN_DEG, OUT_DEG, visited);
        }
        return count;
    }
}
