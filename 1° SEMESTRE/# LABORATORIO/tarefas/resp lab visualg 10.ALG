algoritmo "minado"
// Disciplina   : [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
var
   visual,gabarito:vetor[1..10,1..10] de caracter
   i, j, lin, col, sorlin, sorcol, jogadas : inteiro
   temBomba : logico
inicio
   jogadas <- 0
   temBomba <- falso;
   // preenche matriz
   para i de 1 ate 10 faca
      para j de 1 ate 10 faca
         visual[i,j] <- "?"
         gabarito[i,j] <- " "
      fimpara
   fimpara

   // sorteio
   enquanto (i <= 10) faca
      sorlin <- randi(10)+1
      sorcol <- randi(10)+1
      se (gabarito[sorlin,sorcol] = " ")entao
         gabarito[sorlin,sorcol] <- "*"
         i <- i + 1
      fimse
   fimenquanto

   enquanto (temBomba = falso) e (jogadas < 90) faca
      //imprime matriz
      escreval("    1  2  3  4  5  6  7  8  9  10")
      para i de 1 ate 10 faca
         se (i>0)e(i<10) entao
            escreva(i,"  ")
         senao
            escreva(i," ")
         fimse
         para j de 1 ate 10 faca
            escreva("[",visual[i,j],"]")
         fimpara
         escreval("")
      fimpara

      escreval("")
      escreval("jogadas=", jogadas)
      escreva("digite linha: ")
      leia(lin)
      escreva("digite coluna: ")
      leia(col)

      //troca de dados
      se (lin>0) e (lin<11) entao
         se (col>0) e (col<11) entao
            se (visual[lin,col] = "?") entao
               visual[lin,col] <- gabarito[lin,col]
               jogadas <- jogadas + 1
            fimse
            se gabarito[lin,col] = "*" entao

               tembomba <- verdadeiro
            fimse
         fimse
      fimse
      escreval("")
   fimenquanto
   
   // condição de parada
   se (jogadas = 90) entao
      escreval("ganhou")
   senao
      escreval("perdeu")
   fimse
fimalgoritmo