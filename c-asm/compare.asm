; 汇编和ｃ语言相互调用
; 
; complite use 
; yasm -f elf compate.asm -o compare.o
; gcc chose.c -o chose.o
; ld compare.o choose.o -o choose
; ./chose
;

extern choose                   ; 应用外界函数 int choose(int a, int b)
[section .data]                 ; 数据段
    num1st     dd       3
    num2nd     dd       4

[section .text]                 ; 代码段
global _start                   ; 声明程序入口
global myprint                  ; 将函数声明为全局的，方便其他文件引用

_start:
    push    dword [num2nd]      ;
    push    dword [num1st]      ;
    call    choose
    add     esp, 8
    
    mov     ebx, 0
    mov     eax, 1
    int     0x80

;----------------------------------------------------
; 字符串打印函数
; 

myprint:
    mov     edx, [esp + 8]      ; len
    mov     ecx, [esp + 4]      ; msg
    mov     ebx, 1
    mov     eax, 4
    int     0x80
    ret

