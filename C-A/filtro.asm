;%include "io64.inc"

section .data
section .bss
    aux: resb 8
section .text

global CMAIN

CMAIN:
    MOV rcx, rdx
    MOV rbx, 0
    MOV R9, 0
    
	for_2:
		MOV rax, 0
		MOV rdx, 0 
		MOV rax, [RDI + R9]
		MOV rdx, [RSI + R9] 
		MUL rdx
		ADD rbx, rax
		ADD R9, 4
		LOOP for_2
		MOV rax,rbx
	RET
