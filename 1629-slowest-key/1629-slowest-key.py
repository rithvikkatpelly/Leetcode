class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        best_dur = releaseTimes[0]
        best_key = keysPressed[0]
        for i in range(1, len(releaseTimes)):
            dur = releaseTimes[i] - releaseTimes[i - 1]
            if dur > best_dur or (dur == best_dur and keysPressed[i] > best_key):
                best_dur = dur
                best_key = keysPressed[i]
        return best_key        