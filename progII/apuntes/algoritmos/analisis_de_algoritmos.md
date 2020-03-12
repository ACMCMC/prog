# Análisis de algoritmos
## Tipos de análisis
### Análisis experimental
Es más inexacto, y aparte no siempre se puede hacer. Un análisis de algoritmos no se puede experimentar con un lanzamiento de un cohete a la luna, por ejemplo.
### Análisis teórico
El análisis teórico nos deja tener resultados más exactos, y eso puede venir bien.
## Qué algoritmo es mejor?
Cuando yo tengo tres algoritmos, por ejemplo uno para hacer una suma:
```C
int a, b;
while (b > 0) {
    a++;
    b--;
}
```
Este algoritmo es mejor en uso de memoria, porque solo usa 2 variables.

En tiempo, puede ser mejor o peor, dependiendo de cuánto cueste hacer un incremento. Si el incremento dura 0,5 s y la suma 10 s, entonces para sumar 2 + 2 este algoritmo tardará  2+*0,5=1 s, y el otro 10 s.
```C
int a, b, c;
c = a + b;
```
Este algoritmo es directamente peor en uso de memoria, porque usa 3 variables en vez de 2.