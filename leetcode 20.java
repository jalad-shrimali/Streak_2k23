class Solution {
	    public boolean isValid(String s) {        
	        int len = 0;
	        if(s.length() == 0) return true;
	        while(s.length() != len){
	            len = s.length();
	            s = s.replace("{}", "").replace("()", "").replace("[]", "");
	        }

	        return s.length() == 0;
	     }
	}
