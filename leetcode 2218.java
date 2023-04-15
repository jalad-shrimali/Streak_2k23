class Solution {
    Map<Pair<Integer, Integer>, Integer> answers;
    ArrayList<Integer> sizes;
    public int maxValueOfCoins(List<List<Integer>> piles, int endPile, int k) {
        if(sizes.get(endPile) < k) return Integer.MIN_VALUE;

        if(answers.containsKey(new Pair(endPile, k))){
            return answers.get(new Pair(endPile, k));
        }
        
        if(endPile == 0) {
            if(piles.get(0).size() >= k) {
                int answer = 0;
                for(int i = 0; i < k; i++) {
                    answer += piles.get(0).get(i);
                }
                answers.put(new Pair(endPile, k), answer);
                return answer;
            }
            
            return Integer.MIN_VALUE;
        }
        
        int answer = maxValueOfCoins(piles, endPile - 1, k);
        int currentSum = 0;
        
        for(int i = 0; i < Math.min(piles.get(endPile).size(), k); i++) {
            currentSum += piles.get(endPile).get(i);
            
            answer = Math.max(answer, currentSum + maxValueOfCoins(piles, endPile - 1, k - i - 1));
        }
        
        answers.put(new Pair(endPile, k), answer);
        
        return answer;
    }
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        answers = new HashMap<Pair<Integer, Integer>, Integer>();
        sizes = new ArrayList();
        for(List<Integer> pile: piles) {
            sizes.add(pile.size());
        }
        for(int i = 1; i < sizes.size(); i++) {
            int current = sizes.get(i);
            sizes.set(i, current + sizes.get(i - 1));
        }
        return maxValueOfCoins(piles, piles.size() - 1, k);
    }
}
