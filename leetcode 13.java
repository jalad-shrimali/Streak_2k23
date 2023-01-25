class Solution {
    public int romanToInt(String s) {
        Map<Character,Integer> map = new HashMap<>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);
        int ans=0;
        char curr,next;
        for(int i=0;i<s.length()-1;i++){
            curr =s.charAt(i);
            next = s.charAt(i+1);
            if(map.get(next)>map.get(curr))ans -= map.get(curr);
            else ans += map.get(curr);
        }
        return ans+map.get(s.charAt(s.length()-1));
    }
}
