; (row_sums, col_sums, x, nrows, ncols)
; (rcx,rdx,r8d,r9d,r10d)

;rcx - начальный адрес суммы строк
;rdx - начальный адрес суммы столбцов

;r8 - начальный адрес массива
;rsi - индекс элемента массива

;r9d - кол-во строк
;r10d - кол-во столбцов

;rax - индекс i
;rbx - индекс j
;edi - количество байт смещения для подмассива

.code
CalcMatrix proc frame
	mov r10d,[rsp+40]
	
	push rsi
	.pushreg rsi
	push rdi
	.pushreg rdi
	.endprolog

	cmp r9d,0
	jle InvalidCount
	cmp r10d,0
	jle InvalidCount

	mov eax,0
	mov ebx,0

	Lp1:
		mov dword ptr [rcx+rax*4], 0
		mov ebx,0
		mov edi,eax
		imul edi,r10d
		
		Lp2:
			mov esi,edi
			add esi,ebx
			mov r11d,[r8+rsi*4]
			add [rcx+rax*4],r11d
			add [rdx+rbx*4],r11d

			inc rbx
			cmp rbx,r10
			jl Lp2
	
	inc rax
	cmp rax,r9
	jl Lp1
	
	InvalidCount:
		pop rsi
		pop rdi
		ret

CalcMatrix endp
end