import heapq

class MedianFinder:

    def __init__(self):
        # Stores the smaller half (Max-Heap, inverted for Python's min-heap)
        self.small = [] 
        # Stores the larger half (Min-Heap)
        self.large = [] 

    def addNum(self, num: int) -> None:
        # Step 1: Push to max-heap, then move the largest element to min-heap
        heapq.heappush(self.small, -num)
        heapq.heappush(self.large, -heapq.heappop(self.small))
        
        # Step 2: Maintain size property (small can have at most 1 more element)
        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        # If total elements are odd, small heap has the median
        if len(self.small) > len(self.large):
            return float(-self.small[0])
        # If even, average the tops of both heaps
        return (-self.small[0] + self.large[0]) / 2.0

        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()