class Solution:
    def compress(self, chars: List[str]) -> int:
        write = read = 0
        n = len(chars)
        while read < n:
            ch = chars[read]
            start = read
            while read < n and chars[read] == ch:
                read += 1
            chars[write] = ch
            write += 1
            count = read - start
            if count > 1:
                for d in str(count):
                    chars[write] = d
                    write += 1
        return write