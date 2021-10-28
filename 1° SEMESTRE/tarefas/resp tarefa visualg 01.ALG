Algoritmo "alturapredio"

Var
   ca, co, ang: real
Inicio
   escreva("escreva o cateto adjacente: ")
   leia(ca)
   escreva("digite o angulo: ")
   leia(ang)
   co <- tan(ang*PI/180)*ca
   escreva("A altura do predio equilave a ",co," metros")
Fimalgoritmo