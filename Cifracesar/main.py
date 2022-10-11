def cifraCesar(arqIn, arqOutP, salto):
  arqIn = arqIn
  salto = k
  arqOutP = []

  #convertendo os valores para asci
  res = [] 
  for element in arqIn: 
    res.extend((ord(num) for num in element)) 
  for value in range(len(res)):
    res[value] = res[value]+salto

  
  #convertendo valores para letras
  for element in res: 
    arqOutP.extend(chr(element)) 

  arqOutP = "".join(arqOutP)
  print(arqOutP)
  pass 

arqOut = ''
arqIn = list(input())
k = int(input())
cifraCesar(arqIn, k, arqOut)





