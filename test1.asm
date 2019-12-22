;汇编代码模板
;assume cs:code
;
;code segment
;main:	
;		
;		mov ax,4c00h
;		int 21h
;code ends
;
;end main

assume cs:code        ;将code段关联到基址寄存器

code segment          ;定义code段
main:   mov ax,2      ;将数字2放置到ax通用寄存器
		mov cx,11     ;将数字11放置到cx循环计数寄存器
lab1: 	add ax, ax    ;将ax加到ax自身，相当于翻倍
		loop lab1     ;先执行(cx)=(cx)-1再判断(cx)是否为零，如果不为零则跳转到lab1继续执行 ，如果为零则停止循环，类似高级编程语言中的 do...while 循环。
		
		mov ax ,4c00H ;将4c00h(终止进程并返回dos)，放入到ax寄存器
		int 21h       ;触发21h(系统调用)中断，从ax寄存器取命令码。即，执行4c00h(终止进程并返回dos)命令
code ends

end main
