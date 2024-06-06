.code
ArraySum proc

    movups xmm0, xmmword ptr [rcx]
    movups xmm1, xmmword ptr [rdx]
    addps xmm1, xmm0
    movups xmmword ptr [r8], xmm1

    ret 

ArraySum endp

ArraySub proc
    
    movups xmm0, xmmword ptr [rcx]
    movups xmm1, xmmword ptr [rdx]
    subps xmm1, xmm0
    movups xmmword ptr [r8], xmm1


    ret 
ArraySub endp

ArrayMnozh proc
    
    movups xmm0, xmmword ptr [rcx]
    movups xmm1, xmmword ptr [rdx]
    mulps xmm1, xmm0
    movups xmmword ptr [r8], xmm1


    ret 
ArrayMnozh endp

ArrayDiv proc

    movups xmm0, xmmword ptr [rcx]
    movups xmm1, xmmword ptr [rdx]
    divps xmm1, xmm0
    movups xmmword ptr [r8], xmm1


    ret 
    
ArrayDiv endp

end