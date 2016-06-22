%include "io.inc"


section .text
global CMAIN
CMAIN:






////////////////////////////////////////////////////
    int n = 0;
    for (i = 0; i < tamSai; i++) {
      for ( j = 0; j < tamFil; j++) {
        s[n] += (f[j]*v[i+j]);
      }
      n++;
    }
