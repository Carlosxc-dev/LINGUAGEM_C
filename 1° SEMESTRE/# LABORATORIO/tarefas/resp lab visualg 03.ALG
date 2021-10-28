Algoritmo "lab02-3"

Var
   hini, mini, hter, mter, htotal, mtotal :inteiro
   dia : caractere
Inicio
   escreva("digite hora de inicio: ")
   leia(hini)
   escreva("digite minuto de inicio: ")
   leia(mini)
   escreva("digite hora de termino: ")
   leia(hter)
   escreva("digite minuto de termino: ")
   leia(mter)
   
   se(hter>hini)entao
      htotal <- hter-hini
      dia <-  "sim"
   senao
     htotal <- hini-hter
     htotal <- 24-htotal
     dia <- "nao"
   fimse

   se(mter>=mini)entao
      mtotal <- (mter-mini)
   senao
      mtotal <- (mini-mter)
      htotal <- htotal-1
      mtotal <- 60-mtotal
   fimse

   escreval("--tempo de partida--")
   escreval(htotal," horas", " e ", mtotal, " minutos")
   escreval("partida termino no mesmo dia ? ", dia)
Fimalgoritmo