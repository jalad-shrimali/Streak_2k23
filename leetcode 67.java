class Solution {
    public String addBinary(String a, String b) {
        if(a == null || b == null) return "";
        int aLen = a.length();
        int bLen = b.length();
        int[] result = new int[Math.max(aLen, bLen) + 1];
        int len = result.length;
        int carry = 0;
        int aVal = 0;
        int bVal = 0;
        while(aLen > 0 || bLen > 0){
            aVal = aLen > 0 ? (int)(a.charAt(--aLen)) - 48 : 0;
            bVal = bLen > 0 ? (int)(b.charAt(--bLen)) - 48 : 0;
            result[--len] = (aVal + bVal + carry) % 2;
            carry = (aVal + bVal + carry) / 2;
        }
        StringBuilder sb = new StringBuilder();
        if(carry == 0){
            for(int i = 1; i < result.length; i++)
                sb.append(result[i]);

        }else{
            result[0] = 1;
            for(int i = 0; i < result.length; i++)
                sb.append(result[i]);
        }
        return sb.toString();
    }
}
