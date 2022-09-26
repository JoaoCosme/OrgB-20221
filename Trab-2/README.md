# Trabalho 2 - Org-B 2022/1
Simulação de processador x86 com características variadas em diferentes tipos de de programas.

---
## Configurações do Processador

### Configuração Fixa
- Parâmetro 1: Cache L1 size (1kB)
- Parâmetro 2: Cache L1 Associatividade (1)
- Parâmetro 3: MyIntALU.count (8)
  
#### Δ Parâmetro 1 - L1 size
[1kB (base), 2kB, 4kB, 8kB]

#### Δ Parâmetro 2 - MyIntALU.count
[2, 4, 8 (base), 16]

#### Δ Parâmetro 3 - numPhysFloatRegs
[64, 96 (base), 128, 256]

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
## Setup
```bash
git clone https://github.com/JoaoCosme/OrgB-20221.git
cd gem5
```
## Rodando os benchmarks
```bash
./gem5 orgb_configs/simulate.py run-benchmark -c /home/orgb/OrgB-20221/Trab-2/Algorithms/fft.out
```
```bash
./gem5 orgb_configs/simulate.py run-benchmark -c /home/orgb/OrgB-20221/Trab-2/Algorithms/sort.out
```
```bash
./gem5 orgb_configs/simulate.py run-benchmark -c /home/orgb/OrgB-20221/Trab-2/Algorithms/matrix.out
```

No diretório '/home/orgb/gem5/m5out' ver os valores de 'sim_seconds' (tempo) e 'System.cpu.ipc' (IPC) no arquivo de resultados gerados 'stats.txt'.


---
## Resultados