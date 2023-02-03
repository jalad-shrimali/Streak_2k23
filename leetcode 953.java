class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] index = new int[26];
        
        for (int i = 0; i < order.length(); ++i) {
            index[order.charAt(i) - 'a'] = i;
        }
        
        search: for (int j = 0; j < words.length - 1; ++j) {
            String word1 = words[j];
            String word2 = words[j+1];
            
            for (int k = 0; k < Math.min(word1.length(), word2.length()); ++k) {
                if (word1.charAt(k) != word2.charAt(k)) {
                    if (index[word1.charAt(k) - 'a'] > index[word2.charAt(k) - 'a']) {
                        return false;
                    }
                    continue search;
                }
            }
            
            if (word1.length() > word2.length()) {
                return false;
            }    
        }
        return true;   
    }
}
