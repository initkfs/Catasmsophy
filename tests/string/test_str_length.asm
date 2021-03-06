; initkfs, 2018
; ---------------------

; include last
%include "tests/string/base_test_string.inc"

section .data
file: dq __FILE__

section .text
global main

main:

testStringLength:

	mov rdi, string1
	call str_length
	test rdx, rdx
	jne .fail
	
	mov r8, [string1Size]
	cmp r8, rax
	jne .fail
	
	call testSuccess
	
.fail:
	call assertNumeric
	mov rdi, __LINE__
	mov rsi, file
	call printFailInfo
