import math
print('***Formulador de bhaskaralho***\n')
a = float(input('Valor de a:'))
b = float(input('Valor de b:'))
c = float(input('Valor de c:'))
D = b**2 - 4*a*c

if (D) < 0:
    print('não há raizes reais')
else:
    x1 = (-b + math.sqrt(D)) / (2*a)
    x2 = (-b - math.sqrt(D)) / (2*a)
    if (x1) == (x2):
        print(x1)
    else:    
        print('\nValor de x1: {0}'.format(x1))
        print('Valor de x2: {0}'.format(x2))

