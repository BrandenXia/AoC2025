#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void mv(void **p) { *p = (char *)*p + 1; }
#define lnb(a, p, b) do { *(a) = *(char *)*(p) - 0x30; mv(p); for (; *(char *)*(p) != (b); mv(p)) { *(a) *= 0xa; *(a) += *(char *)*(p) - 0x30; } } while(0)
#define lnbb(a, p, b1, b2) do { *(a) = *(char *)*(p) - 0x30; mv(p); for (; *(char *)*(p) != (b1) && *(char *)*(p) != (b2); mv(p)) { *(a) *= 0xa; *(a) += *(char *)*(p) - 0x30; } } while(0)
void rd(void **p, int *a, int *b) { lnb(a, p, 0x78); mv(p); lnb(b, p, 0x3a); }
int ct(void **p, int *c) { int t = 0, i = 0, m; while (1) { lnbb(&m, p, 0x20, 0xa); mv(p); t += m * i[c]; if (*((char *)*p - 1) == 0xa) break; } return t; }

int main(void) {
  FILE *f = fopen((char[]){0x69, 0x6e, 0x70, 0x75, 0x74, 0x2e, 0x74, 0x78, 0x74, 0}, (char[]){0x72, 0});
  fseek(f, 0, 0b10); size_t s = ftell(f); fseek(f, 0, 0b0); void *p = malloc(s + 1); fread(p, 1, s, f);
  int c[6] = {0}; for (int i = 0; i <= 5; i++) for (int _ = 0; _ <= 15; _++, p = (char *)p + 1) { *(char*) p - 0x23 == 0 && ++(*(c + i)); }
  int t = 0; while (*(char *)p != 0) { int a, b; rd(&p, &a, &b); p = (char *)p + 2; t += a * b - 220 > ct(&p, c); }
  printf("%d\n", t);
}
