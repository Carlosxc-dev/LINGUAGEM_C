Algoritmo "divisaoPremio"

Var
   prim, seg, terc, premio : real
Inicio
   premio <- 780000
   
   prim <- premio * 0.46
   seg <- premio * 0.32
   terc <- premio * (1-(0.46+0.32))
   
   escreval("primerio recebeu: ", prim)
   escreval("segundo recebeu: ", seg)
   escreval("terceiro recebeu: ", terc)
Fimalgoritmo