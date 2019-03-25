class Solution:
    def compress(self, chars: List[str]) -> int:
        count = 1
        i = 0
        while True:
            try:
                # Find repeated chars
                # This will cause IndexError: index out of range
                if chars[i] == chars[i + 1]:
                    count += 1
                    chars.pop(i + 1)

                # Char appears more than 1 times
                elif count > 1:
                    # Insert count to chars list
                    for c in str(count):
                        chars.insert(i + 1, c)
                        i += 1

                    # Note: i need a step here
                    i += 1
                    count = 1

                # Char appears only 1 time, leave it be
                else:
                    i += 1
            except IndexError:
                if count > 1:
                    chars.extend(str(count))
                return len(chars)