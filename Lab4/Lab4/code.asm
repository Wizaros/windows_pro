 extern g_Val1:dword 
 .code
IntegerLogical_ proc
; Вычисление (((a & b) | c ) ^ d) + g_Val1
 and ecx,edx ;ecx = a & b  
 or ecx,r8d ;ecx = (a & b) | c
 xor ecx,r9d ;ecx = ((a & b) | c) ^ d
 add ecx,[g_Val1] ;ecx = (((a & b) | c) ^ d) + g_Val1 
 mov eax,ecx ;eax = окончательный результат 
 ret 
IntegerLogical_ endp
 end
