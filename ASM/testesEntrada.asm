%include "io.inc"
section .data
    entrada: db '123456'
    filtro: db '122'
    EntradaLen: equ $ - entrada
    FiltroLen: equ $ - filtro
    hex: db '0123456789ABCDEF'
        
section .bss
;    x resb 2
    tamEntr: resb 6
    tamFil: resb 3
    tamSai: resb 4
    saida: resb 4
    aux: resb 8    

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging

;    call receber
 ;   mov al, [x]
  ;  and al, 0xff
   ; mov [tamEntr], al
    
;    call receber
 ;   mov al, [x]
  ;  and al, 0xff
   ; mov [tamFil], al
    ;and al, 0xff
    
;    mov al, [tamEntr]
 ;   mov ah, [tamFil]
  ;  sub al, ah
   ; inc al
    ;mov [tamSai], al
    mov eax, 0
    mov ecx, tamEntr
    mov edx, 0
    mov ebx, 0


for_1:
    push ecx
    mov ecx, 0
    mov [aux], ecx
    call for_2
    pop ecx
    inc edx    
    loop for_1
    
    jmp imprimir
    
for_2:
    
    PUSH ECX
    mov eax, [filtro + ecx]
    add edx, ecx
    mov ebx, [entrada + edx]
    PUSH EDX
    mul ebx
    POP EDX   
    add [aux], eax
    POP Ecx
    inc ecx
    cmp ecx, 3
    jl for_2
    mov eax, [aux]
    mov [saida + edx], eax
    ;call converter
    ret
    
    
    
fim:
    jmp fim
    
    
    
    
;receber:
;    mov eax, 3
;    mov ebx, 0
;    mov ecx, x
;    mov edx, 2
;    int 80h
;    ret

imprimir:                    
    mov	eax, 4
    mov ebx, 1
    mov	ecx, saida
    mov	edx, 4
    int	80h
    jmp fim
    
;converter:
;    mov dl, bl                ; Garda o valor de BL
;    
;    and bl, 0xf0              ; Pega o primeiro digito
;    shr bl, 4                 ; Move para o começo de BL
;    mov bl, [hex + ebx]       ; BL recebe o seu valor em Hex
;    mov [saida + 0], bl      ; Move para o buffer
;    
;    mov bl, dl                ; Recebe o valor original
;    and bl, 0x0f              ; Pega o segundo digito
;    mov bl, [hex + ebx]       ; BL recebe o seu valor em Hex
;    mov [saida + 1], bl      ; Move para o buffer
;    ret