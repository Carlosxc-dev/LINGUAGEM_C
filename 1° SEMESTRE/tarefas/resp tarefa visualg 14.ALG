Algoritmo "soma matrizes"

Var
   a, b, c : vetor[1..5,1..3] de inteiro
   i, j : inteiro
Inicio
   escreval("-----A-----")
   para i de 1 ate 5 faca
      para j de 1 ate 3 faca
         a[i,j] <- randi(9)+1
         b[i,j] <- randi(9)+1
         c[i,j] <- (a[i,j] + b[i,j])

         escreva(a[i,j],"  ")
      fimpara
      escreval()
   fimpara
   escreval()

   escreval("-----B-----")
   para i de 1 ate 5 faca
      para j de 1 ate 3 faca
         escreva(b[i,j],"  ")
      fimpara
      escreval()
   fimpara
   escreval()

   escreval("------C------")
   para i de 1 ate 5 faca
      para j de 1 ate 3 faca
         escreva(c[i,j]:2,"   ")
      fimpara
      escreval()
   fimpara

Fimalgoritmo