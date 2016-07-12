;%include "io64.inc"

global CMAIN
section .bss
	    
    vSai: resb 8
    vFil: resb 8
    vEnt: resb 8 
    
    tSai: resb 4
    tFil: resb 4
    tEnt: resb 4
section .text

CMAIN:

    mov [vFil], rdi
    mov [vSai], rdx
    mov [vEnt], rsi
    mov [tFil], ecx
    mov [tSai], r9d
    mov [tEnt], r8d
    mov rcx, 0
    mov rdx, 0	
    mov ecx, [tSai]
	
for1:

    mov rbx, [vSai]
    mov rax, 0	
    mov [rbx+rdx], rax	
    push rcx		
    push rdx		
    mov rcx, 0
    mov rbx, rdx		
    mov ecx, [tFil]	

    for2:
    
        push rax
        push rbx	
        push rcx
        push rdx
        mov rcx, [vFil]
        mov rcx, [rcx+rax]
        mov rax, [vEnt]
        mov rax, [rax+rbx]
        mul rcx
        pop rdx
        mov rcx, [vSai]
        add [rcx+rdx], rax
        pop rcx
        pop rbx
        pop rax
        add rax, 4
        add rbx, 4
    loop for2
        pop rdx
        pop rcx
        add rdx, 4
loop for1    
        
    ret
