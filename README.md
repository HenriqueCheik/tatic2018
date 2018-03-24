# Bem-vindo!

#### Esse repositório possui os arquivos desenvolvidos por Henrique Cheik F. Cabral para o desafio Tatic 2018.

Os programas estão separados em "armazenador" e "buscador"

O programa armazenador recebe entrada de algum arquivo que possui dados em formato data/identificador hexadecimal/identificador de usuario. O algoritmo verifica os registros e os ordena em ordem crescente para o programa buscador.

O programa buscador recebe os dados avaliados pelo programa armazenador e, através do input de algum usuário, retorna os eventos filtrados em ordem crescente de data. Os parametros para input são: data_inicio data_fim e, opcionalmente, identificadores hexadecimais dos eventos.


Os programas foram desenvolvidos na linguagem C utilizando o sistema operacional Linux Ubuntu 16.04 que já possui um compilador C nativo. Caso se deseje compilar os programas na plataforma Windows será necessário a instalação de um compilador para o sistema operacional, como por exemplo o MinGW, disponível em www.mingw.org

Para compilar os programas deve-se utilizar os comandos em um terminal aberto na pasta em que se encontram os arquivos. Foi desenvolvido um Makefile para facilitar o procedimento de compilação, caso se deseje maior praticidade.

- Para compilar os programas utilizando o Makefile: digite o comando **make** no terminal. 
- Para compilar os programas individualmente:
  - armazenador: digitar no terminal **gcc -o armazenador armazenador.c**
  - buscador: digitar no terminal **gcc -o buscador buscador.c**

Após a compilação dos programas, surgirão dois executáveis "armazenador" e "buscador".
Para utilizar os programas, deve-se, em um terminal, utilizar os seguintes comandos:

- armazenador: **./armazenador nome_do_arquivo_com_dados**
  - Exemplo: ./armazenador sample.txt
- buscador: **./buscador data_inicio data_fim (opcionalmente colocar os identificadores hexadecimais)**
  - Exemplo: ./buscador 20170108162233255 20170217173500896
  - Exemplo com tags: ./ buscador 20170101000104313 20170107005603481 BF7D4A40 BF939C5C BFEA4CAB
