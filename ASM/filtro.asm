section .data
    
section .bss
;        Saida: resb Sinallen-Filtrolen+1             ; Vetor Y recebe o tamanho de X

section .text
global CMAIN ;RDI, RSI, RDX, RCX, R8
             ;R9, RAX, R10, R11
CMAIN:
    mov ebp, esp; for correct debugging
    mov ecx, [tamSaida]
    mov ebx, 0
    mov edx, 0
    
for_1:    
    cmp edx, tamFil
    jl for_2
    loop for_1 
    
for_2:
     mov eax, vFil[edx]
     mul vEntr[edx+ebx]
     mov  , eax 
     add eax, 0 

    
     inc ebx    