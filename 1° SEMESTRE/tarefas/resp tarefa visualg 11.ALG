Algoritmo "VLtriagulo"

Var
   a, b, c, soma : real
   resp : caractere
Inicio
   repita
      escreva("digite angulo a: ")
      leia(a)
      escreva("digite angulo b: ")
      leia(b)
      escreva("digite angulo c: ")
      leia(c)
      escreval()

      soma <- a + b + c

      se soma = 180 entao // condicao para triangulo
         se (a = 60) e (b = 60) entao
            escreval("triangulo equilatero")
         senao
            se (a = b) ou (b = c) ou (c = a) entao
               escreval("triangulo isosceles")
            senao
               escreval("triangulo escaleno")
            fimse
         fimse
      senao
         escreval("nao e triangulo")
      fimse
      
      escreval()
      escreva ("deseja continuar(s/n): ")
      leia (resp)
      enquanto (resp <> "s") e (resp <> "n") faca
         escreval("resposta invalida !!")
         escreva ("deseja continuar(s/n): ")
         leia(resp)
      fimenquanto
      escreval()
      
   ate resp = "n"
Fimalgoritmo