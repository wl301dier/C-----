;将字符'A'显示在屏幕上

assume cs:code, ds:data
data segment
;var1 db '将字符A显示在屏幕上:$'
var1 db 'print A on the scream:$'
data ends

code segment
main: mov ax,data          ;将数据段的起始地址送到ax寄存器
	  mov ds,ax            ;将ax寄存器中的值送到ds数据段基址寄存器中。ds不能被直接赋值，需要借助其他寄存器
	  
	  mov dx, offset var1  ;将变量var1的偏移地址送到dx寄存器
	  mov ah,9             ;将系统调用命令9放入ah寄存器中用于向屏幕显示字符串
	  int 21h              ;int表示触发系统中断，21h表示进行系统调用中断
	  
	  mov ah,2             ;将系统调用命令2放入ah寄存器中用于向屏幕显示字符
	  mov dx,41h           ;将待显示的41h('A'的十六进制ASCII码)放入到dx寄存器中
	  int 21h              ;int表示触发系统中断，21h表示进行系统调用中断
	  
	  mov ah,4ch           ;将系统调用命令4ch放入ah寄存器中用于终止进程返回DOS系统
	  int 21h              ;int表示触发系统中断，21h表示进行系统调用中断
code ends
end main 
