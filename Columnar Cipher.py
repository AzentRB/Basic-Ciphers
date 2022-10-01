ip = input('Enter Plain Text to be ciphered: ')
key = input('Enter the key: ')
l = len(key)
textLength = len(ip)
rows = 0

if textLength % l != 0:
    ip += (l - (textLength % l)) * 'x'

key = [int(letter) for letter in key]

if textLength % l == 0:
    rows = int(textLength / l)
else:
    rows = int(textLength / l) + 1

matrix = [[0 for x in range(l)] for y in range(rows)]
i = 0
for x in range(rows):
    for y in range(l):
        if i < textLength:
            matrix[x][y] = ip[i]
            i += 1
        else:
            matrix[x][y] = 'x'

for d in matrix:
    print(d)
print('\n')

cipheredText = ''
for x in range(1,len(key)+1):
    for i in range(rows):
        cipheredText += str(matrix[i][key.index(x)])

print(f'Ciphered Text: {cipheredText}')