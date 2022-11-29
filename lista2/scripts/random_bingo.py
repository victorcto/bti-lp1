#gera entradas aleatorias para o problema casa_rua

#Osvaldo Montenegro
#59-513-491
import random
import numpy as np

nomes=[
'Gael Jorge Pietro Porto',
'Otávio Geraldo Carlos Eduardo da Cruz',
'Brenda Daiane Camila Gonçalves',
'Carolina Mariane Porto',
'Raquel Ana Marli Moreira',
'Evelyn Cecília Silva',
'Fátima Bianca Fernanda da Conceição',
'Natália Daiane Elza das Neves',
'Brenda Sueli Campos',
'Larissa Isabel Stella Drumond',
'Giovanna Mirella Amanda Aragão',
'Elisa Sabrina Larissa Nunes',
'Larissa Regina Campos',
'Giovana Alícia dos Santos',
'Ryan Marcos Vinicius Almeida'
]

n_jogadores = int(input("Numero de jogadores :"))
seed = np.random.randint(low=np.iinfo('u8').min, high=np.iinfo('u8').max, dtype=np.dtype('u8'))
print(seed)

print(n_jogadores)
random.shuffle(nomes)
for i in range (n_jogadores):
    print (nomes[i])
