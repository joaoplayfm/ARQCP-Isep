
#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma pilha
struct stack {
  // Ponteiro para o vetor que armazena os elementos da pilha
  long *values;

  // Tamanho atual da pilha
  int size;

  // Tamanho máximo da pilha
  int capacity;
};

// Cria uma nova pilha
struct stack *stack_create() {
  // Aloca dinamicamente a estrutura que representa a pilha
  struct stack *s = (struct stack *)malloc(sizeof(struct stack));

  // Inicializa o tamanho atual e o tamanho máximo da pilha
  s->size = 0;
  s->capacity = 10;

  // Aloca dinamicamente o vetor que armazena os elementos da pilha
  s->values = (long *)malloc(s->capacity * sizeof(long));

  // Retorna a pilha criada
  return s;
}

// Libera a memória alocada dinamicamente para a pilha
void stack_free(struct stack *s) {
  // Desaloca a memória alocada para o vetor que armazena os elementos da pilha
  free(s->values);

  // Desaloca a memória alocada para a estrutura que representa a pilha
  free(s);
}

// Empilha um elemento na pilha
void stack_push(struct stack *s, long value) {
  // Se o tamanho atual da pilha é igual ao seu tamanho máximo, aumenta o tamanho máximo
  if (s->size == s->capacity) {
    s->capacity *= 2;
    s->values = (long *)realloc(s->values, s->capacity * sizeof(long));
  }

  // Adiciona o elemento ao topo da pilha e aumenta o tamanho atual da pilha
  s->values[s->size++] = value;
}

// Desempilha um elemento da pilha
long stack_pop(struct stack *s) {
  // Se a pilha está vazia, retorna 0
  if (s->size == 0) {
    return 0;
  }

  // Decrementa o tamanho atual da pilha e retorna o elemento no topo da pilha
  return s->values[--s->size];
}
int main() {
  // Cria uma nova pilha
  struct stack *s = stack_create();

  // Empilha alguns elementos na pilha
  stack_push(s, 1);
  stack_push(s, 2);
  stack_push(s, 3);

  // Desempilha e imprime alguns elementos da pilha
  printf("\n|----|\n");
  printf("| %ld  |", stack_pop(s));
   printf("\n|----|\n");
  printf("| %ld  |", stack_pop(s));

  // Empilha alguns elementos na pilha
  stack_push(s, 4);
  stack_push(s, 5);

  // Desempilha e imprime todos os elementos da pilha
  while (s->size > 0) {
     printf("\n|----|\n");
    printf("| %ld  |", stack_pop(s));
  }
  printf("\n|----|\n");
  // Libera a memória alocada dinamicamente para a pilha
  stack_free(s);

  return 0;
}