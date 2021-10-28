Algoritmo "lab03-3."

Var
   n, c, f : inteiro
Inicio
   escreva("o valor do fatorial: ")
   leia(n)
   
   f <- n
   c <- n
   escreva(n, "! =")
   enquanto c > 1 faca
      escreva(c," .")
      c <- c - 1
      f <- f * c
   fimenquanto
   escreva(" 1 =",f)
Fimalgoritmo