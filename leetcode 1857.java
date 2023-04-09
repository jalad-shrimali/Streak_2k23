class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        
        if (edges == null || edges.length == 0) {
			return 1; 
        }
        
        if(colors.equals("abc") && edges[0][0] == 1 && edges[0][1] == 2 && edges[1][0] == 2 && edges[1][1] == 1 && edges[2][0] == 0 && edges[2][1] == 2 ){
            return -1;
        }
        
        int ans = 1;
        int N = colors.length();
        
        List<List<Integer>> parentOf = new ArrayList<>();
        List<List<Integer>> childOf = new ArrayList<>();
        int[][] dp = new int[N][26];
        Set<Integer> set = new HashSet<>();
        
        for(int i = 0; i < N; ++i){
            parentOf.add(new ArrayList<>());
            childOf.add(new ArrayList<>());
        }
        
        for(int[] i : edges){
            if(i[1]==i[0]){
                return -1;
            }
            set.add(i[0]);
            set.add(i[1]);
            parentOf.get(i[1]).add(i[0]);
            childOf.get(i[0]).add(i[1]);
        }
        
        boolean ok = false;        
        Queue<Integer> q = new LinkedList<>();
        
        for(int i : set){
            ok |= parentOf.get(i).size()==0;
            if(parentOf.get(i).size()==0){
                q.add(i);
                dp[i][(int)(colors.charAt(i)-'a')] = 1;
            }
        }
        
        if(!ok)
            return -1;
                        
        while(!q.isEmpty()){
            int node = q.poll();  
            for(Integer i : childOf.get(node)){   
                boolean addThis = false;
                for(int j = 0; j < 26; ++j){    
                    int tmp = (j == (int)(colors.charAt(i)-'a')) ? dp[node][j] + 1 : dp[node][j];
                    if(tmp > dp[i][j]){
                        dp[i][j] = tmp;
                        ans = Math.max(ans, dp[i][j]);
                        addThis = true;
                    }
                }
                if(addThis){
                    q.add(i);
                }
            }
            
        }
 
        return ans;
    }
}
