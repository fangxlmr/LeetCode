class Solution:
    def isValid(self, s: str) -> bool:
        left = set("([{")
        right = set(")]}")
        d = {'(': ')', '[': ']', '{': '}'}
        stack = []
        for c in s:
            if not stack:
                # Bottom of stack cannot be right paren
                if c in right:
                    return False
                else:
                    stack.append(c)

                # Verify current paren by stack top
            elif d.get(stack[-1], None) == c:
                stack.pop()

                # Still left paren
            else:
                stack.append(c)
        return not stack
