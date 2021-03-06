; errno=900
;----------------------------------------------
; initkfs, 2018
; procedure "str_2num"
; Params: 
; RDI, memory address of string
; Returns: RAX, numeric string representation
; Calls: extern atoi
; Error: if an error occurred while calling the atoi
; Note: Many registers are preserved for the prevention of side effects
;----------------------------------------------
global str_2num:

extern atoi

str_2num:
	push rcx
	push rsi
	push rdi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

	call atoi WRT ..plt
	test rax, rax
	jl .errAtoiCallError
	xor rdx, rdx
	jmp .end
	
.errAtoiCallError:
	mov rdx, 901

.end:
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rdi    
	pop rsi        
	pop rcx
	ret
