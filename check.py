#Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. 
#An input string is valid if:
#- Open brackets are closed by the same type of brackets.
#- Open brackets are closed in the correct order.
#- Note that an empty string is also considered valid.

def check(str):
    s = []
    if(len(str) == 0):
        return True
    if(str[0] == ')' or str[0] == ']' or str[0] == '}'):
        return False
    for i in range(len(str)):
        s.append(str[i])
        if(str[i] == ')' or str[i] == ']' or str[i] == '}'):
            if(len(s) == 1):
                return False
            if not((s[len(s)-2] == '(' and s[len(s)-1] == ')') or (s[len(s)-2] == '[' and s[len(s)-1] == ']') or s[len(s)-2] == '{' and s[len(s)-1] == '}'):
                return False
            else:
                s.pop()
                s.pop()

    if(len(s) > 0):
        print("here")
        return False
    return True

if __name__ == '__main__':
    str = input()

    if(check(str)):
        print("True")
    else:
        print("False")