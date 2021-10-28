Algoritmo "ladostriangulo"

Var
   a,b,c,radA,radB,angA,angB,angC,cosA,cosB: real

Inicio
// calculo lado C
   escreva("digite o lado a do triangulo: ")
   leia(a)
   escreva("digite o lado b do triangulo: ")
   leia(b)
   escreva("digite o angulo C do triangulo: ")
   leia(angC)
   escreval()
   c <- raizq((a^2)+(b^2)-(2*a*b*(cos(angC*pi/180))))
   escreval("o lado c do triangulo mede ",c)
//calculo angulo A
    cosA<- ((b^2)+(c^2)-(a^2))/(2*b*c)
    radA<- arccos( cosA )
    angA<- radA*180/pi
    escreval("o angulo A do triangulo mede ",angA:5:2," graus")
//calculo angulo B
    cosB<- ((a^2)+(c^2)-(b^2))/(2*a*c)
    radB<- arccos( cosB )
    angB<- radB*180/pi
    escreval("o angulo B do triangulo mede ",angB:5:2," graus")
Fimalgoritmo
