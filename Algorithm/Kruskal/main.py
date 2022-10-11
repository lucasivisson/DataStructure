# %%
import networkx as nx

# %%
#importando o arquivo para leitura do grafo
file = open('grafo_W_1_1.txt', 'r')
print(file.readlines())

file.close()

# %%
G1 = nx.Graph()

# %%
# edges = [('A', 'B', 1100),('A', 'F', 1200), ('A', 'C', 1800), ('B', 'C', 900), ('B', 'E', 750), ('B', 'D', 800), 
# ('C', 'F', 850), ('C', 'D', 700), ('E', 'F', 500), ('E', 'D', 1000), ('A', 'D', 2000)]
edges = [(1, 2, 3), (1, 3, 5), (1, 4, 1), (2, 5, 4), (3, 4, 4), (3, 5, 8), (4, 6, 3), (5, 6, 7)]

# %%
G1.add_weighted_edges_from(edges)

# %%
#funcao para encontrar a quebra do vetor
def partition(edges, left, right):
    pivot = edges[right][2] #escolhendo como pivo o  mais a direita do array
    index = left - 1 #indicador para o maior elemento

    #comparando elementos com o pivo
    for jIndex in range(left, right):
        if edges[jIndex][2] <= pivot: #se o peso da aresta for menor, entao 
            index += 1                #iremos trocar com o maior elemento apontado por index

            #trocando o valor de index com o elemento jIndex
            (edges[index], edges[jIndex]) = (edges[jIndex], edges[index])
    
    #trocando o pivo com o maior elemento representado pelo index
    (edges[index + 1], edges[right]) = (edges[right], edges[index + 1])

    #retornando a posicao em que a particao aconteceu
    return index + 1

# %%
#realizando o ordenamento de maneira
def quickSort(edges, left, right):
    if left < right:
        #encontrando o elemento da quebra para que um elemento menor esteja a esquerda
        #e o maior a direita
        breakPoint = partition(edges, left, right)

        #chamada recursiva da funcao para a esquerda 
        quickSort(edges, left, breakPoint - 1)

        #chamada recursiva da funcao para a direita
        quickSort(edges, breakPoint + 1, right)
    
    return edges

# %%
#chamada da funcao de maneira mais facil para o usuario
#implementando abstracao
def sortWeightEdges(edges):
       return quickSort(edges, 0, len(edges) - 1)

# %%
#funcao para encontrar um vertice em uma classe e retornar em qual classe ele foi encontrado
def findNodeBelongs(node, nodesList):
    for key, nodeInList in nodesList.items():
        if node in nodeInList:
            return key
    return False

# %%
#classe para gerar a arvore geradora minima
class AGM:
    def __init__(self, edge = [], node = []):
        self.edges = edge
        self.nodes = node

    # metodo para adicao de arestas na arvore geradora minima
    def unionEdge(self, edge): 
        self.edges.append(edge)

# %%

#implementacao do algoritmo de kruskal
def kruskalAlgorithm(G1):
    sortedEdges = sortWeightEdges(list(G1.edges.data("weight", default=1))) #ordenando as arestas com quicksort
    AGMObject = AGM() #instanciando a arvore AGM pela a classe criada acima

    nodesList = {} #instanciando uma lista de vertices para utilizarmos como classe
    for node in list(G1.nodes):
        nodesList[node] = [node] #instanciando uma classe para cada no

    for edge in sortedEdges: #realizando as verificacoes para cada aresta ordenada
        
        #descobrindo em qual classe se encontra o primeiro vertice de cada aresta
        indexNodeOne = findNodeBelongs(edge[0], nodesList) 

        #descobrindo em qual classe se encontra o segundo vertice de cada aresta
        indexNodeTwo = findNodeBelongs(edge[1], nodesList)
        
        #verificando se o conteudo de cada no é diferente,
        #se sim, significa que não teremos um ciclo e a aresta
        #pode ser adicionado normalmente
        if nodesList[indexNodeOne] != nodesList[indexNodeTwo]:
            if edge[0] not in nodesList[indexNodeOne]: #verificando se o vertice ja se encontra na classe
                nodesList[indexNodeOne] += edge[0]     #para nao duplicarmos os valores

            nodesList[indexNodeOne] += nodesList[indexNodeTwo] #unindo as classes no primeiro vertice
            
            #aqui nos deletamos o resquicio do vertice unido, pois ele nao sera mais utilizado.
            #para evitar problemas de compilacao, é feita uma tentativa de deleção com o try.
            try:
                del nodesList[indexNodeTwo]
            except:
                pass
            AGMObject.unionEdge(edge) #adicionando as arestas na arvore geradora minima
        
    return AGMObject #retornando a arvore geradora minima


kruskalAlgorithm(G1).edges

# %%



