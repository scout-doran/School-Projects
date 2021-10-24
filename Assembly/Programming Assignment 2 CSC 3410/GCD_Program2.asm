
.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE io.h    ;For input/output
INCLUDE debug.h

cr      EQU     0dh     ; carriage return character
Lf      EQU     0ah     ; line feed

.STACK 4096
  
.DATA

display         	BYTE    50 DUP (?), 0
prompt1     BYTE   "Enter the first number:  ", 0
prompt2     BYTE   "Enter the second number:  ", 0
m           DWORD   ?
n           DWORD   ?
result	    BYTE   "The greatest common divisor is ", 0

.CODE                
_main PROC 
    whileBadInput1:
        inputD prompt1, m
        cmp m, 0
        jle whileBadInput1

    whileBadInput2:
        inputD prompt2, n
        cmp n, 0
        jle whileBadInput2

    whileRemainderNotZero:
        push m
        push n
        call GCD
        
    done:
        output result
        outputD eax
        output carriage

        INVOKE ExitProcess, 0    

_main ENDP


GCD PROC    
    push ebp     ;Initialize the stack
    mov ebp, esp 
    push ebx    ;push registers
    push edx    
    push ecx   
    mov ecx, [ebp+12]
    cmp ecx,0   ; if n=0 then return m
    je L2

    ; calculate (m%n) recursively
    mov eax, [ebp+8]    ; eax = "m"
    xor edx, edx        ; If edx XOR edx = 0 then the numbers are equal 
    div ecx             ; m%n
    push edx            ; remainder is new "n"
    mov eax, [ebp+12]
    push eax            ; old "n" is new "m"
    call GCD            ; recursive call

L2:
    pop ecx ;Opposite order
    pop edx 
    pop ebx 
    mov esp, ebp
    pop ebp
    ret

GCD ENDP

END