.code
AddFloats proc
    mov eax, 0
    movss xmm0, dword ptr [rcx] 
    addss xmm0, dword ptr [rdx]

    movss xmm1, dword ptr [rcx]
    mulss xmm1, dword ptr [rdx]

    movss xmm2, dword ptr [rcx]
    divss xmm2, dword ptr [rdx]

    movss dword ptr [rdx], xmm0
    movss dword ptr [r8], xmm1
    movss dword ptr [r9], xmm2
    ret
AddFloats endp
end