#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define N(_) f##_
#define S(a, p, b, c) do { *(a) = *(C *)*(p) - 0x30; for (x(p); *(C *)*(p) != (b) && (c); x(p)) *(a) *= 0xa, *(a) += *(C *)*(p) - 0x30; } W(0)
#define F(_, $, $_) for(I _ = 0; _ <= ($); _++, ($_))
#define W(_) while(_)
#define _(_) typedef _

_(void) v; _(char) C; _(int) I;
I a, b, c[6], i, m, s, t, T;
v x(v **p) { *p = (C *)*p + 1; }
v r(v **p, I *a, I *b) { S(a, p, 0x78, 1); x(p); S(b, p, 0x3a, 1); }
I w(v **p) { t = i = 0; W((-1)[(C *)*p] != 0xa) { S(&m, p, 0x20, *(C *)*p != 0xa); x(p); t += m * (i++)[c]; } return t; }
I main(v) {
  FILE *f = N(open)((C[]){0x69, 0x6e, 0x70, 0x75, 0x74, 0x2e, 0x74, 0x78, 0x74, 0}, (C[]){0x72, 0});
  N(seek)(f, 0, 2); s = N(tell)(f); N(seek)(f, 0, 0); v *p = malloc(s + 1); N(read)(p, 1, s, f); N(close)(f); s[(C *)p] = 0;
  F(i, 5, 1) F(_, 0xF, p = (C *)p + 1) *(C *) p - 0x23 == 0 && ++i[c];
  W(*(C *)p != 0) r(&p, &a, &b), p = (C *)p + 2, T += a * b - 0xc8 > w(&p);
  printf("%d\n", T);
}
