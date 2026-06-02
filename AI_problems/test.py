dic = {
    'start': [('a',1), ('b',2)]
}


dic.update({'start2':[]})
dic['start2'].append(('d', 1))

for child in dic['start2']:
    print(child)

print(dic)