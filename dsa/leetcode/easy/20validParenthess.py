
def isValid1(s):
        stack = []
        bracket_map = {')': '(', ']': '[', '}': '{'}
        
        for char in s:
            if char in bracket_map.values():
                stack.append(char)
            elif char in bracket_map.keys():
                if not stack or stack[-1] != bracket_map[char]:
                    return False
                stack.pop()
        
        return not stack
# ()[]{} all brakets
a = isValid1("(])")
print(a)