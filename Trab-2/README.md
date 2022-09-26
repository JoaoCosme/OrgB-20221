# Trabalho 2 - Org-B 2022/1
Simulação de processador x86 com características variadas em diferentes tipos de de programas.

---
## Configurações do Processador

### Configuração Fixa
-  parâmetro 1: 
  - Original:
  - Modificado para:
- Δ parâmetro 2: 
  - Original:
  - Modificado para:
- Δ parâmetro 3: 
  - Original:
  - Modificado para:

#### Δ Parâmetro 1
- Config 1:
- Config 2:
- Config 3:

#### Δ Parâmetro 2
- Config 1:
- Config 2:
- Config 3:

#### Δ Parâmetro 3
- Config 1:
- Config 2:
- Config 3:

### 
---
## Algoritmos Escolhidos

### Alg1: Multiplicação de Matrizes
- *Características:*
  - Operações aritméticas paralelizaveis;
  - Acesso a grande quantidade de memória;
  - Alta localidade espacial.
- *Resultados Esperados*:
  - Baixo 'miss-rate';
  - Alta responsividade ao tamanho da cache;
  - Baixa correspondência ao aumento da associatividade. 


### Alg2: Fast Fourier Transform - Cooley-Tukey Algorithm
- *Características:*
  - Baixa localidade espacial;
  - Pouco acesso há memória.
- *Resultados Esperados*:
  - 'Miss-rate' elevado (devido a baixo localidade espacial);
  - Baixa responsividade a aumentos na cache.

<!-- TODO: decidir se vamos usar quick-sort ou outro algoritmo para casos com bastante comparações -->
### Alg3: Quick Sort 
- *Características:*
  - Alta localidade espacial;
  - Grande quantidade de acessos a memória.
- *Resultados Esperados*:
  - Baixo 'miss-rate' devido a alta localidade;
  - Pouco impacto referente ao aumento associativo.


---
## Resultados
