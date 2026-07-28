class Solution:
    # 7. Isomorphic Strings (LeetCode 205)
    def isIsomorphic(self, s: str, t: str) -> bool:
        # Use two dictionaries to map characters from s to t and t to s respectively
        map_s_t, map_t_s = {}, {}
        
        for c1, c2 in zip(s, t):
            if (c1 in map_s_t and map_s_t[c1] != c2) or (c2 in map_t_s and map_t_s[c2] != c1):
                return False
            map_s_t[c1] = c2
            map_t_s[c2] = c1
            
        return True