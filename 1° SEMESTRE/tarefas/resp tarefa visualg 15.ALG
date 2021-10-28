Algoritmo "tabuada"

Var
   x, t, r : inteiro
   resp : caractere
Inicio
   repita
      escreva("qual a tabuada a ser calculada: ")
      leia(t)

      para x de 1 ate 10 faca
         r <- x * t  // calculo
         escreval (t, " x", x, "  = ", r )
      fimpara
      
      escreva("deseja parar(s/n): ")
      leia(resp)
      escreval("")
   ate resp = "s"
   
Fimalgoritmo