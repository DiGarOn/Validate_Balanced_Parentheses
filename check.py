def check(str):
    s = []
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