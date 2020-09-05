# Compressed Trie
Um sistema para autocompletar textos que utiliza como base para o armazenamento de strings a estrutura de uma _Trie_ Comprimida. Desenvolvido para a disciplina de Projeto e Análise de Algoritmos da Universidade Federal de Ouro Preto em 2020.

## Descrição
O sistema contém um modo interativo em que o usuário pode procurar por prefixos e receber sugestões de completação com base nas palavras mais recorrentes e um modo de experimentos para testar a eficiência do programa em termos das operações realizadas na estrutura de dados.

## Instalação e Uso
Clone o repositório e acesse o diretório `CompressedTrie`.

```
:~$ git clone https://github.com/carlasanches/CompressedTrie
:~$ cd CompressedTrie
```

Para compilar o código, execute os seguintes comandos e o arquivo "trie" será gerado:

```
:~$ gcc -c .\CompressedTrie.c main.c
:~$ gcc -o trie .\CompressedTrie.o main.o
```

Para a execução, o programa suporta dois comandos: -interactive e -exp. Para executar o modo interativo com o arquivo padrão de teste, execute o comando a seguir:

```
:~$ ./trie baskervilles.txt -interactive
```

Comando para o modo de experimentos:

```
:~$ ./trie baskervilles.txt -exp
```

Dentro do arquivo "txt.rar" existem outros arquivos de texto com diferentes cargas do texto de exemplo para experimentos do código. Para posterior análise, o programa salva o tempo de execução total do código no arquivo "total-time.csv", e o tempo de execução das funções Insert e Search no arquivo "time.csv" quando o modo de experimentos é executado.