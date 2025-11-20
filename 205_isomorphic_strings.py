#205
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map_st = {}
        map_ts = {}

        for c1, c2 in zip(s, t):

            # If mapping exists in s→t but mismatch → not isomorphic
            if c1 in map_st and map_st[c1] != c2:
                return False

            # If mapping exists in t→s but mismatch → not isomorphic
            if c2 in map_ts and map_ts[c2] != c1:
                return False

            # Create the mapping
            map_st[c1] = c2
            map_ts[c2] = c1

        return True
