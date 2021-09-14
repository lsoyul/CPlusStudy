%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging

    ; 쉬프트(Shift)연산, 논리(logical)연산
    
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    
    shl eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    
    shr eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    
    ; 활용
    ; 곱셈, 나눗셈
    ; 게임서버에서 ObjectID를 만들어 줄 때, 오브젝트의 type 구분 개념으로도 사용
    
    
    ; 논리 연산
    ; not and or xor
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0b 0001 0100 = 0x14
    and al, bl ; al = al and b1
    PRINT_HEX 1, al
    NEWLINE
    
    ; 0b 1110 1011 = 0xeb
    NOT al
    PRINT_HEX 1, al
    NEWLINE
    
    ; 활용
    ; bitflag
    ; xor - 암호학 대칭키, 자기자신xor로 0 만들기
    
    xor rax, rax
    ret
    
section .data

section .bss
    num resb 1
    
    