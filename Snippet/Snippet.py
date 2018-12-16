l = []
while 1:
    try:
        s = input()
        s = s.replace("\\n","\\\\\\\\n")
        s = s.replace('"','\"')
        l.append(s)
    except EOFError:
        break
print(*l,sep='\\n')
