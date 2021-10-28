Algoritmo "elitor de numeros"
Var
   u, d, c, m, dm, cm, num : inteiro
   resp : caractere
Inicio
   repita
      escreva("escreva um numero: ")
      leia(num)
      escreval()
      
      cm <- num / 100000 mod 10
      dm <- num / 10000 mod 10
      m <- num / 1000 mod 10  //1234 / 1 = 1234
      c <- num / 100 mod 10   //1234 mod 10 = 123 inteiro
      d <- num / 10 mod 10    // o resto do modulo e 4 !!
      u <- num / 1 mod 10     // so almentar casas decimais
      
      escreval("centena de milhar = ",cm)
      escreval("dezena de milhar = ",dm)
      escreval("milhar = ", m)
      escreval("centena = ",c)
      escreval("dezena = ",d)
      escreval("unidade = ",u)
      escreval()
      escreva("deseja continuar(s/n): ")
      leia(resp)
      escreva()
      escreval("----------------------")
   ate resp = "n"

Fimalgoritmo