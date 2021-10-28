algoritmo "lab02-1"

var
   a, b, c, alfa, beta: real
   // a = 3; c = 5 ; b = 4
inicio
   escreva("digite cateto a: ")
   leia(a)
   escreva("digite hipotenusa c: ")
   leia(c)
   b <- raizq(c*c - a*a)
   escreval("cateto b = ", b:5:2)


   //calculo angulo alfa
   alfa <- arcsen(b / c) / pi * 180
   escreval("angulo alfa = ",alfa:5:2)

   //calculo angulo beta
   beta <- 180 - 90 - alfa
   escreval("angulo beta = ",beta:5:2)

fimalgoritmo