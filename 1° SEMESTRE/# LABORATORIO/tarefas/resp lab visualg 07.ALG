Algoritmo "lab03-2."

Var
  an, a1, n, r, i, c: inteiro
Inicio
   escreva("escreva primeiro termo: ")
   leia(a1)
   escreva("escreva razao da pg: ")
   leia(r)
   escreva("escreva numero de termos: ")
   leia(n)
   
   an <- a1
   para i de a1 ate n faca
      escreva(an)
      an <- an + r
   fimpara
Fimalgoritmo