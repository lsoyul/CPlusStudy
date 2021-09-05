%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    
    ; 2진수 (0 1)
    ; 0 1 10
    ; 0b0 0b1 0b10 0b11 0b100
    
    ; 16진수 (0 1 2 3 4 5 6 7 8 9 A B C D E F)
    ; ~ F 10 11 12 ~
    ; 0x00 
    
    ; 0b 1001 0101 = 0x95 (2진수 <-> 16진수 변환 쉬움)
    
    PRINT_STRING msg
    
    xor rax, rax
    ret
    
section .data
    msg db 'Hello World', 0x00
    