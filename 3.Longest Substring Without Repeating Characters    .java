class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] begin = new  int[s.length()];
        int[] a = new  int[s.length()];
        
        Map<Character, Integer> map = new HashMap();
        int l = 0;
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if(map.containsKey(c)) {
                c = s.charAt(i);
                if (map.get(c) < begin[i - 1 ]) {
                    a[i] = a[i - 1] + 1;
                    begin[i] = begin[i - 1];
                }
                else
                {
                    a[i] = a[i - 1] - (map.get(c)-begin[i-1]);
                    begin[i] = map.get(c) + 1;
                }
                
            }
            else
            {
                if (i == 0) {
                    a[i] = 1;
                    begin[i] = 0;
                }
                else {
                    a[i] = a[i - 1] + 1;
                    begin[i] = begin[i - 1];
                }
                
            }
            if (a[i] > l) {
                l = a[i];
            }
            c = s.charAt(i);
            map.put(c, i);
        }
        return l;
    }
}