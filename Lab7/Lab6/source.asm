; extern "C" int MinMaxArr_(const int n, const int* arr, int* min, int* max);
; ecx = n, rdx = arr, ebx = min, esi = max

.code
MinMaxArr_ proc

cmp ecx, 0
jz Invalid

mov ebx, 100000
mov esi, -100000

StartCucle:
cmp ebx, [rdx]
;jl CheckMax
cmovge ebx, [rdx]

CheckMax:
cmp esi, [rdx]
jg EndCucle
mov esi, [rdx]

EndCucle:
add rdx, 4
dec ecx
cmp ecx, 0
jne StartCucle

mov [r8], ebx
mov [r9], esi
ret

Invalid:
ret

MinMaxArr_ endp
end