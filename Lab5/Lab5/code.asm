; extern "C" int IntegerShift_(unsigned int a, unsigned int count, unsigned int* a_shl, unsigned int* a_shr);
; Возвращает: 0 = ошибка (count >= 32), 1 = успешное выполнение
;
 .code
IntegerShift_ proc
 xor eax,eax 
 cmp edx,31 
 ja InvalidCount 
 xchg ecx,edx 
 mov eax,edx 
 shl eax,cl 
 mov [r8],eax 
 shr edx,cl 
 mov [r9],edx 
 mov eax,1 
InvalidCount:
 ret 
IntegerShift_ endp
 end
