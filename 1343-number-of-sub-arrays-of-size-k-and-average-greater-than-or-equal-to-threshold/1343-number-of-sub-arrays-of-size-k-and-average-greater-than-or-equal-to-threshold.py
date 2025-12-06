class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        
        maxT = k * threshold
        cnt = 0
        current_sum = 0

        for i in range(k):
            current_sum += arr[i]
        if current_sum >= maxT:
            cnt += 1
        
        for i in range(k,len(arr)):
            current_sum += arr[i]
            current_sum -= arr[i-k]
            if current_sum >= maxT:
                cnt += 1
        
        return cnt
        