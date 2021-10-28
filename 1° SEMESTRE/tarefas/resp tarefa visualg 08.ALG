Algoritmo "matriz M"

Var
   m : vetor[1..5,1..5] de inteiro
   i, j, sb, sc: inteiro
Inicio
   escreval()
   para i de 1 ate 5 faca
      escreva("  ")
      para j de 1 ate 5 faca
         se (i=j) entao
            m[i,j] <- 0
         senao
            m[i,j] <- randi(9)+1
         fimse
         escreva(m[i,j])
      fimpara
      escreval()
   fimpara

   para i de 1 ate 5 faca
      para j de 1 ate 5 faca
         se (i<j) entao
            sc <- sc + m[i,j]
         senao
            se (i>j) entao
               sb <- sb + m[i,j]
            fimse
         fimse
      fimpara
   fimpara

   escreval()
   escreval("  abaixo = ",sb)
   escreval("  acima  = ",sc)
Fimalgoritmo