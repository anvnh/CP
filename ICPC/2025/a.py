s=input()
w1=['Rock Scissors','Scissors Paper','Paper Rock']
d=['Rock Rock','Scissors Scissors','Paper Paper']
if s in w1:
    print('Player 1')
elif s in d:
    print('Draw')
else:
    print('Player 2')
