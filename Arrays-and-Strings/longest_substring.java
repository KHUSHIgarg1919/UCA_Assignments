import java.util.HashSet;
import java.util.Set;
class longest_substring {
    public static int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int maxLength = 0;
        int left = 0;
        for(int right=0;right<s.length();right++){
            if(!set.contains(s.charAt(right))){           //if set doesn't contain character then add it in set and right pointer is incremented.Also find maxLength.
                set.add(s.charAt(right));
                maxLength = Math.max(maxLength,right-left+1);    //maxLength can be found by right-left+1
            }
            else{                                         //else means set contains that character
                while(set.contains(s.charAt(right))){     //in this case,move left pointer and remove that characters from set until repeated character is present in set
                    set.remove(s.charAt(left));
                    left++;
                }
                set.add(s.charAt(right));                        //insert current character into the set and continue the iteration
            }
        }
        return maxLength;
    }
    public static void main(String[] args) {
        String s1 = "abcabcbb";
        System.out.println(lengthOfLongestSubstring(s1));

        String s2 = "pwwkew";
        System.out.println(lengthOfLongestSubstring(s2));
    }
}