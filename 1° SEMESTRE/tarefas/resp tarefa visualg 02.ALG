Algoritmo "anoNasc"
Var
   nasc, anoat, ano, mes, semana, dia : inteiro
Inicio
   escreva("digite o ano de seu nascimento: ")
   leia(nasc)
   escreva("digite o ano atual: ")
   leia(anoat)
   
   ano <- anoat - nasc
   mes <- ano * 12
   dia <- ano * 365
   semana <- ano * (12*4)
   
   escreval("idade em anos =",ano)
   escreval("idade em meses =",mes)
   escreval("idade em dias =",dia)
   escreval("idade em semanas =",semana)
Fimalgoritmo