l = []
while 1:
    try:
        s = input()
        s.replace('"','\"')
        l.append(s)
    except EOFError:
        break
print(*l,sep='\\n')
