def solution(new_id):
    answer = ''
    new_id1 = ''.join(chr(ord(i)+32) if 'A' <= i <= 'Z' else i for i in new_id )
    new_id2 = ''.join(i for i in new_id1 if 'a' <= i <= 'z' or '0' <= i <= '9' or i == '.' or i == '_' or i == '-')
    new_id3 = new_id2[0] + ''.join('' if new_id2[i] == '.' and new_id2[i-1] == '.' else new_id2[i] for i in range(1,len(new_id2)))
    new_id4 = new_id3.strip('.')
    new_id5 = 'a' if new_id4 == '' else new_id4
    new_id6 = new_id5[:15].strip('.') if len(new_id5) >= 16 else new_id5
    new_id7 = new_id6[:]
    l_new_id6 = len(new_id6)
    for i in range(0,3-l_new_id6,1):
        new_id7 += new_id7[-1]
    return new_id7