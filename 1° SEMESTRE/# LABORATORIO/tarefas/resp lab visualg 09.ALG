algoritmo "lab3-1"
var
   divisor, num, metade, resto : inteiro
inicio
   escreva("digite numero inteiro: ")
   leia(num)
   metade <- num div 2
   divisor <- 2
   resto <- num mod divisor
   enquanto ((divisor <= metade) e (resto > 0)) faca
      divisor <- divisor + 1
      resto <- num mod divisor
   fimenquanto
   se divisor > metade entao
      escreva("e primo")
   senao
      escreva("nao e primo")
   fimse
fimalgoritmo
