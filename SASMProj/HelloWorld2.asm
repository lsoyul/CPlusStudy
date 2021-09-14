%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging

    PRINT_STRING msg
    
    xor rax, rax
    ret
    
section .data
    msg db 0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,0x64,0x0

    a db 0x11, 0x11, 0x11, 0x11       ; [0x11]
    
    b dd 0x12345678
    ; 미묘한 장단점이 있음
    ; - 리틀 엔디언 : 메모리의 첫 주소에 끝값이 있기 때문에 캐스팅에 유리함
    ; - 빅 엔디언 : 숫자 비교에 유리함 (메모리의 첫 주소에 들어있는 값 부터 비교하면 되기 때문에)

section .bss
    e resb 10
    
    