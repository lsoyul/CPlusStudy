%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging

    ; 8bit = 1byte
    ; 16bit = 2byte = 1word
    ; 32bit = 4byte = 2word = 1dword (double-word)
    ; 64bit = 8byte = 4word = 1qword (quad-word)
    
    ; mov reg1, cst     (cst값을 reg1으로)
    ; mov reg1, reg2    (reg2값을 reg1으로)
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    
    ;mov al, 0x00
    ;mov rax, rdx
    
    ; 메모리 <-> 레지스터
    ; mov rax, a    ; a라는 바구니의 메모리 주소값을 rax에 복사
    ; mov rax, [a]    ; a라는 바구니 안에 있는 값을 rax에 복사
    mov al, [a]
    
    mov [a], byte 0x55
    mov [a], word 0x6666
    mov [a], cl
    
    xor rax, rax
    ret
    
    ; 변수의 선언 및 사용
    ; - 처음 변수 사용 선언 (이름과 크기 지정)
    
    ; section .data 
    ;-> 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] => db(1) dw(2) dd(4) dq(8)
section .data
    a db 0x11       ; [0x11]
    b dw 0x2222 
    c dd 0x33333333
    d dq 0x4444444444444444

    ; section .bss 
    ;-> 초기화 되지 않은 데이터
    ;-> 모든 값들이 0으로 초기화
    ;-> .data에 비해 실행파일[바이너리]의 크기가 커지지 않음 (값이 들어있지 않기 때문에)
    ; [변수이름] [크기] [갯수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    e resb 10
    
    