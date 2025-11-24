class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # Sort intervals by end coordinate
        points.sort(key=lambda x: x[1])
        
        arrows = 1
        arrow_pos = points[0][1]  # first arrow at first balloon's end
        
        for start, end in points:
            # If current balloon starts after arrow position → need new arrow
            if start > arrow_pos:
                arrows += 1
                arrow_pos = end  # shoot at this balloon's end
        
        return arrows
