class Solution {
    public boolean checkInclusion(String s1, String s2) {
       if (s1.isEmpty()) return true;
        Map<Character, Integer> s1Map = new HashMap<>();
        Map<Character, Integer> s2Map = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++) {
            s1Map.put(c, 0);
            s2Map.put(c, 0);
        }
        
        // get the concatenation of s1
        for (char c : s1.toCharArray()) {
            s1Map.put(c, s1Map.get(c) + 1);
        }
        
        // using a window to slide through s2 to get the matching
        for (int i = 0; i < s2.length(); i++) {
            if (i >= s1.length()) {
                s2Map.put(s2.charAt(i - s1.length()), s2Map.get(s2.charAt(i - s1.length())) - 1);
            }
            s2Map.put(s2.charAt(i), s2Map.get(s2.charAt(i)) + 1);
            if (s1Map.equals(s2Map)) {
                return true;
            }
        }
        
        return false;  
    }
}
