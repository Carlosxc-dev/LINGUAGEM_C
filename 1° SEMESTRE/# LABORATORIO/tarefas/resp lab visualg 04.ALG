Algoritmo "tamanhoestrada"
Var
   ad, dc, angB, estrada : real
Inicio
   escreva("escreva valor da reta ad: ")
   leia(ad)
   escreva("escreva valor da reta dc: ")
   leia(dc)
   escreva("escreva valor do angulo angB: ")
   leia(angB)
   estrada <- raizq(ad^2 + dc^2 - 2*ad*dc*cos(angB*pi/180))
   escreval("A estrada ac mede ", estrada, " km")
Fimalgoritmo