Algoritmo "lab02-2"

Var
   ax, ay, bx, by, cx, cy, coefab, coefbc : real
Inicio
   escreva("digite x no ponta A= ")
   leia(ax)
   escreva("digite y no ponta A= ")
   leia(ay)
   escreva("digite x no ponta B= ")
   leia(bx)
   escreva("digite y no ponta B= ")
   leia(by)
   escreva("digite x no ponta C= ")
   leia(cx)
   escreva("digite y no ponta C= ")
   leia(cy)
   
   se(ax = bx) ou (bx = cx)entao
      escreval("impossivel determinar")
   senao
      se(ax <> bx)entao
          coefab <- (ay - by) / (ax - bx)
          coefbc <- (by - cy) / (bx - cx)
         se(coefab = coefbc)entao
              escreval("sao colineares ")
         senao
              escreval("nao sao colineares ")
         fimse
      fimse
   fimse
Fimalgoritmo