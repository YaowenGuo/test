    section .data
msg:
    db "hello, world", 10
len equ $-msg

    section .text
    global _start
_start:
    push eax
    pop eax
    mov edx, len
    mov ecx, msg
    mov ebx, 1
    mov eax, 4 ;直接使用sys_write系统调用
    int 0x80

    mov ebx, 0
    mov eax, 1
    int 0x80
