Algoritmo "lab1c.alg"
Var
   bc, angA, angB, angC, ac, ab : real
Inicio
   escreva("digite reta bc (metros): ")
   leia(bc)
   escreva("digite reta angA (graus): ")
   leia(angA)
   escreva("digite reta angB (graus): ")
   leia(angB)
   escreva("digite reta angC (graus): ")
   leia(angC)
   ab <- (bc*(sen(angC*pi/180)))/(sen(angA*pi/180))
   ac <- (ab*(sen(angB*pi/180)))/(sen(angC*pi/180))
   escreval()
   escreval("A ponte ab mede ", ab, " metros")
   escreval("A ponte ac mede ", ac, " metros")
Fimalgoritmo