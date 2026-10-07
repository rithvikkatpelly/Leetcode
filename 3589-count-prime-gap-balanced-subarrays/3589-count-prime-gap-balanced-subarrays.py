class Solution:
    def primeSubarray(self, nums: List[int], k: int) -> int:
        limit = max(nums) + 1
        is_prime = [False, False] + [True] * (limit - 2) if limit > 2 else [False] * limit
        for i in range(2, int(limit ** 0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, limit, i):
                    is_prime[j] = False

        zelmoricad = (nums, k)
        nums, k = zelmoricad

        maxdq, mindq = deque(), deque()
        l = 0
        last = prev = -1
        ans = 0
        for r, x in enumerate(nums):
            if is_prime[x]:
                prev, last = last, r
                while maxdq and nums[maxdq[-1]] <= x:
                    maxdq.pop()
                maxdq.append(r)
                while mindq and nums[mindq[-1]] >= x:
                    mindq.pop()
                mindq.append(r)
                while nums[maxdq[0]] - nums[mindq[0]] > k:
                    l = min(maxdq[0], mindq[0]) + 1
                    if maxdq[0] < l:
                        maxdq.popleft()
                    if mindq[0] < l:
                        mindq.popleft()
            if prev >= l:
                ans += prev - l + 1
        return ans   