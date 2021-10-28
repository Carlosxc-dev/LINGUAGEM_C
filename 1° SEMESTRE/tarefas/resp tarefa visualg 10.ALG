Algoritmo "vetores"

Var
   v1, v2, vmed : vetor[1..100] de real
   i : inteiro
Inicio
   para i de 1 ate 100 faca
      v1[i] <- randi(9)+1
      v2[i] <- randi(9)+1
      vmed[i] <- (v1[i] + v2[i]) / 2
   fimpara

   i <- 1
   enquanto (i<=9) faca
      escreva("v1[", i," ]=", v1[i],"   v2[", i," ]=", v2[i])
      escreval("   media = ", vmed[i])
      i <- i + 1
   fimenquanto


Fimalgoritmo