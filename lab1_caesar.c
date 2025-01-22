#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300
#define SHIFT_MAX 26

struct Message {
  char data[MAX];
  int shift;
};

int main(void) {
  struct Message *input = malloc(sizeof(struct Message));

  printf("enter message: ");
  fgets(input->data, MAX, stdin);

  printf("enter shift: ");
  scanf("%d", &input->shift);

  if (input->shift > SHIFT_MAX) {
    input->shift = input->shift % SHIFT_MAX;
  }

  for (size_t i = 0; i < strlen(input->data) - 1; ++i) {
    // ascii round edge-case
    if (input->data[i] > 121) {
      input->data[i] = 97;
    }

    input->data[i] += input->shift;
  }

  printf("caesar cipher with shift %d: %s", input->shift, input->data);

  free(input);
  return 0;
}
