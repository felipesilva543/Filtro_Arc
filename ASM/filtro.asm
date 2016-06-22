%include "io.inc"
section .data
    Sinal: db '123456', 0ah          ;Vetor X
    Sinallen: equ $ - Sinal          ; Pega o Tamanbho de X
    
    Filtro: db '122', 0ah
    Filtrolen: equ $ - Filtro
section .bss
    Saida: resb Sinallen-Filtrolen+1             ; Vetor Y recebe o tamanho de X

section .text
global CMAIN
CMAIN:
    
    
    
for_1:    
    
    mov ecx, [tamSaida]
    call for_2
    
for_2:
    
    mov
    mul 
    mov    saida