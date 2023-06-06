# Estrutura de Dados em C

Este repositório contém códigos-fonte em C que implementam diversas estruturas de dados, tais como listas, pilhas, filas, deques, tanto estáticos quanto dinâmicos e estrutura de árvores binárias. O objetivo é fornecer exemplos práticos de como essas estruturas podem ser implementadas em C e como elas podem ser usadas em diferentes tipos de aplicações, como encontradas neste repositório.

## Estruturas de Dados Disponíveis

Aqui está uma lista das estruturas de dados atualmente disponíveis neste repositório:

- Lista (Estática e Dinâmica)
- Pilha (Estática e Dinâmica)
- Fila (Estática e Dinâmica)
- Deque (Estático e Dinâmico)
- Árvore binária (Pesquisa)

## Como Usar

Todos os códigos foram criados no ambiente Windows e, caso sejam executados em um ambiente Linux, alguns comandos devem ser alterados. Abaixo estão listados os comandos que precisam ser alterados:

- `fflush(stdin)` deve ser substituído por `fpurge(stdin)` ou por uma leitura adicional de `getchar()`;
- `system("pause")` deve ser substituído por `system("read -p 'Pressione Enter para continuar...'")`;
- `system("cls")` deve ser substituído por `system("clear")`;
- `#include <conio.h>` não é uma biblioteca padrão em sistemas Linux, portanto, para usar a função `rand()`, é necessário incluir a biblioteca `stdlib.h` e utilizar a função `srand()` para gerar uma semente para o gerador de números aleatórios.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request com melhorias, correções de bugs ou novos recursos.

---

Espero que este projeto seja útil para o seu aprendizado. Se tiver alguma dúvida ou sugestão, fique à vontade para entrar em contato.

Divirta-se codificando! 🚀





