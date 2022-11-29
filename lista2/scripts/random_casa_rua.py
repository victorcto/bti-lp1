#gera entradas aleatorias para o problema casa_rua

#Osvaldo Montenegro
#59-513-491
import random

nomes=[
'Osvaldo Montenegro',
'Rua Chico Reis',
'Rua Otávio Pires da Silva',
'Rua Cerejeira',
'Rua Santa Terezinha',
'Rua Projetada',
'Rua do Comércio 126',
'José Vidal 91',
'Misael Mendonça'
]
ceps=[
'59-513-491',
'76-821-344',
'78-721-055',
'57-309-634',
'29-114-002',
'65-058-756',
'57-515-970',
'58-748-970',
'85-803-230'
]

n_casas = int(input("Numero de casas :"))

rua = random.randint(0,8)
print(nomes[rua])
print(ceps[rua])
for i in range(n_casas):
    lado = random.choice(['A','B'])
    area_total = 0.8*random.randint(200, 400)
    area_ocupada = random.randint(70, 100)/100 * area_total
    ocupada = random.choice(['ocupada','desocupada'])
    print(lado)
    print('{:.2f} {:.2f}'.format(area_ocupada, area_total))
    print(ocupada)
