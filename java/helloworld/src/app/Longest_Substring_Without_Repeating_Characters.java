package app;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Longest_Substring_Without_Repeating_Characters {
    /**
     * Approach 1: Brute Force Intuition
     * 
     * Check all the substring one by one to see if it has no duplicate character.
     * 
     * Algorithm
     * 
     * Suppose we have a function boolean allUnique(String substring) which will
     * return true if the characters in the substring are all unique, otherwise
     * false. We can iterate through all the possible substrings of the given string
     * s and call the function allUnique. If it turns out to be true, then we update
     * our answer of the maximum length of substring without duplicate characters.
     * 
     * Now let's fill the missing parts:
     * 
     * To enumerate all substrings of a given string, we enumerate the start and end
     * indices of them. Suppose the start and end indices are ii and jj,
     * respectively. Then we have 0 \leq i \lt j \leq n0≤i<j≤n (here end index jj is
     * exclusive by convention). Thus, using two nested loops with ii from 0 to n -
     * 1n−1 and jj from i+1i+1 to nn, we can enumerate all the substrings of s.
     * 
     * To check if one string has duplicate characters, we can use a set. We iterate
     * through all the characters in the string and put them into the set one by
     * one. Before putting one character, we check if the set already contains it.
     * If so, we return false. After the loop, we return true.
     */
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (allUnique(s, i, j))
                    ans = Math.max(ans, j - i);
        return ans;
    }

    public static boolean allUnique(String s, int start, int end) {
        Set<Character> set = new HashSet<>();
        for (int i = start; i < end; i++) {
            Character ch = s.charAt(i);
            if (set.contains(ch))
                return false;
            set.add(ch);
        }
        return true;
    }

    /**
     * To check if a character is already in the substring, we can scan the
     * substring, which leads to an O(n^2) algorithm. But we can do better. By using
     * HashSet as a sliding window, checking if a character in the current can be
     * done in O(1).
     * 
     * A sliding window is an abstract concept commonly used in array/string
     * problems. A window is a range of elements in the array/string which usually
     * defined by the start and end indices, i.e. [i, j)[i,j) (left-closed,
     * right-open). A sliding window is a window "slides" its two boundaries to the
     * certain direction. For example, if we slide [i, j)[i,j) to the right by 11
     * element, then it becomes [i+1, j+1)[i+1,j+1) (left-closed, right-open). Back
     * to our problem. We use HashSet to store the characters in current window [i,
     * j)[i,j) (j = ij=i initially). Then we slide the index jj to the right. If it
     * is not in the HashSet, we slide jj further. Doing so until s[j] is already in
     * the HashSet.
     * 
     * At this point, we found the maximum size of substrings without duplicate
     * characters start with index ii. If we do this for all ii, we get our answer.
     * 
     * Time complexity : O(2n) = O(n)O(2n)=O(n). In the worst case each character
     * will be visited twice by ii and jj. Space complexity : O(min(m,
     * n))O(min(m,n)). Same as the previous approach. We need O(k)O(k) space for the
     * sliding window, where kk is the size of the Set. The size of the Set is upper
     * bounded by the size of the string nn and the size of the charset/alphabet mm.
     * 
     * @param s
     * @return
     */
    public static int lengthOfLongestSubstring_2(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))) {
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            } else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }

    /**
     * use map can skip the characters immediately when we found a repeated character.
     * @param s
     * @return
     */
    public int lengthOfLongestSubstring_3(String s) {
        int n = s.length(), ans = 0;
        //current index of character 
        Map<Character, Integer> map = new HashMap<>(); 
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i);
            }
            ans = Math.max(ans, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        return ans;
    }

    /**
     * 
     * @param args
     */
    public static void main(String[] args) {
        String[] testStr = { "abcabcbb", "bbbbb", "pwwkew", "", " " };
        for (String str : testStr) {
            System.out.println(str + ": " + lengthOfLongestSubstring(str));
        }
    }
}
