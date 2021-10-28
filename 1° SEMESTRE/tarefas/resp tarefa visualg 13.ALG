Algoritmo "seq fibonacci"

Var
   n, t1, t2, t3, cont : inteiro
Inicio
   escreva("digite ultimo termo da sequencia: ")
   leia(n)
   escreval()
   
   t1 <- 0 // para inicio funcionar
   t2 <- 1
   cont <- 3
   escreva(t2)
   
   repita
      se t3 < n entao
         t3 <- t1 + t2 // faz a conta
         escreva (t3)// mostra resultado
         t1 <- t2
         t2 <- t3
         cont <- cont + 1
      fimse
   ate t3 = n// repete ate chegar em (n)
   
   escreval()
   
Fimalgoritmo