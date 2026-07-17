class Solution:
    def merge(self, intervals):
        intervals.sort(key=lambda x: x[0])  # sort by start time
        merged = [intervals[0]]

        for start, end in intervals[1:]:
            last_end = merged[-1][1]

            if start <= last_end:
                # Overlapping — extend the current interval if needed
                merged[-1][1] = max(last_end, end)
            else:
                # No overlap — add as new interval
                merged.append([start, end])

        return merged