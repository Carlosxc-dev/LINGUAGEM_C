Algoritmo "calculadoraNotas"
Var
   alax, alay, albx, alby, alcx, alcy: real
   aldx, aldy, alex, aley, alfx, alfy: real
   meda, medb, medc, medd, mede, medf: real
   smeda, smedb, smedc, smedd, smede, smedf: caractere
   somapr, somaex, somarep, medclas: real
Inicio
   escreva("informe nota x do aluno A: ")
   leia(alax)
   escreva("informe nota y do aluno A: ")
   leia(alay)
   escreva("informe nota x do aluno B: ")
   leia(albx)
   escreva("informe nota y do aluno B: ")
   leia(alby)
   escreva("informe nota x do aluno C: ")
   leia(alcx)
   escreva("informe nota y do aluno C: ")
   leia(alcy)
   escreva("informe nota x do aluno D: ")
   leia(aldx)
   escreva("informe nota y do aluno D: ")
   leia(aldy)
   escreva("informe nota x do aluno E: ")
   leia(alex)
   escreva("informe nota y do aluno E: ")
   leia(aley)
   escreva("informe nota x do aluno F: ")
   leia(alfx)
   escreva("informe nota y do aluno F: ")
   leia(alfy)

   meda <- (alax+alay)/2
   medb <- (albx+alby)/2
   medc <- (alcx+alcy)/2
   medd <- (aldx+aldy)/2
   mede <- (alex+aley)/2
   medf <- (alfx+alfy)/2
   
   se(meda>=7)entao
         smeda <- "aprovado"
         somapr <- 1
   senao
      se(meda>3)e(meda<7)entao
         smeda <- "exame"
         somaex <- 1
      senao
         smeda <- "reprovado"
         somarep <- 1
      fimse
   fimse
   
   se(medb>=7)entao
         smedb <- "aprovado"
         somapr <- somapr + 1
   senao
      se(medb>3)e(medb<7)entao
         smedb <- "exame"
         somaex <- somaex + 1
      senao
         smedb <- "reprovado"
         somarep <- somarep + 1
      fimse
   fimse
   
   se(medc>=7)entao
         smedc <- "aprovado"
         somapr <- somapr + 1
   senao
      se(medc>3)e(medb<7)entao
         smedc <- "exame"
         somaex <- somaex + 1
      senao
         smedc <- "reprovado"
         somarep <- somarep + 1
      fimse
   fimse
   
   se(medd>=7)entao
         smedd <- "aprovado"
         somapr <- somapr + 1
   senao
      se(medd>3)e(medb<7)entao
         smedd <- "exame"
         somaex <- somaex + 1
      senao
         smedd <- "reprovado"
         somarep <- somarep + 1
      fimse
   fimse
   
   se(mede>=7)entao
         smede <- "aprovado"
         somapr <- somapr + 1
   senao
      se(mede>3)e(medb<7)entao
         smede <- "exame"
         somaex <- somaex + 1
      senao
         smede <- "reprovado"
         somarep <- somarep + 1
      fimse
   fimse
   
   se(medf>=7)entao
         smedf <- "aprovado"
         somapr <- somapr + 1
   senao
      se(medf>3)e(medb<7)entao
         smedf <- "exame"
         somaex <- somaex + 1
      senao
         smedf <- "reprovado"
         somarep <- somarep + 1
      fimse
   fimse
   
   medclas <- (meda+medb+medc+medd+mede+medf)/6
   
   escreval()
   escreval("media do aluno A : ",meda)
   escreval("siuação: ",smeda)
   escreval("media do aluno B : ",medb)
   escreval("siuação: ",smedb)
   escreval("media do aluno C : ",medc)
   escreval("siuação: ",smedc)
   escreval("media do aluno D : ",medd)
   escreval("siuação: ",smedd)
   escreval("media do aluno E : ",mede)
   escreval("siuação: ",smede)
   escreval("media do aluno F : ",medf)
   escreval("siuação: ",smedf)
   escreval()
   escreval("total de aprovados: ", somapr)
   escreval("total de exame: ", somaex)
   escreval("total de reprovados: ", somarep)
   escreval()
   escreval("media da classe: ",medclas:2:2)
Fimalgoritmo