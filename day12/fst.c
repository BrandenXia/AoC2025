#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define N(_) f##_
#define S(a, p, b, c) do { *(a) = *(C *)*(p) - 0x30; for (x(p); *(C *)*(p) != (b) && (c); x(p)) *(a) *= 0xa, *(a) += *(C *)*(p) - 0x30; } W(0)
#define F(_, $, $_) for(I _ = 0; _ <= ($); _++, ($_))
#define W(_) while(_)
#define $(_) typedef _
#define _
$(void) v; $(char) C; $(int) I, In;

                             In
                             a,
                            c[6],
                            b  ,
                            i   ,m
                          ,s    ,t
                          ,T      ;
                        v x(v    **
                        p ) {*  p =(
                          C*)*p+1;}v
                          r(v  **p  ,I
                        *a,     I*   b_
                      ){             S(
                      a,               p,
                    120               ,1);
                      x(p);           S(
                      b_, p,_  _  58  ,1
                    ); }I w (v** p){t=i=0
                  ;W(  (-1   )[ (C* )* p]!=
                 10         ){  S(       &m
                ,p,                        32,
                *(C*                  )   * p
                  !=                  0xa);
                  x(  p      )   ;  t   +=m*
                (i ++)[    c];  }; return t;
                  }_; I    main  (v){ FILE  *f
                  =_ N ( open  ) (( C[    ]   ){_
                105, 0x6e,   112,  _           117,
            0x74,            46,                116,
            120,116                               ,0},(
                  C                     []  ){114,0
                })                  ;N (seek)  (f
                ,0                   ,2);s  =_   N(
             tell  )(f    );  N (seek ) (f,      0,0)
            ;v*p=malloc   (s  +1 );N (/* */       read)
              (p,   1,  s,f) ;N( close)              (f)
            ;s    [( C*) p]=  0;F  (i             ,5,1)F
            (u     ,0xf,  p=   (C                  *)
         p+1)*(C                                    *
           ) p -35                                   ==
               00                              &&++i[c];_
              W(    *(                C    *)p  !=  0
           )r(&p,&a,&b           ),   p=(   C*)p+2,
              T+=a   *  b-2e2 >w (&p  );printf
                   ("%d\n",T );};;;;;;;    ;;;;
                   ;;;;   ;;;;;;;;;;; ;;
                            ;;;;;;;;;
                            ;;;;;;;;;
                            ;;;;;;;;;
                            ;;;;;;;;;
