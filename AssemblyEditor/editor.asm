# Lab 5, Assignment 3
.data
	x: .space 32		# destination string x, empty
	y: .space 32		# source string y
.text
input:
	li a7, 8 		#read string service number
	la a0, y		#a0 = address of y
	li a1, 32		#a1 = buffer (32)
	ecall			#system call
load_string:
	mv a3, a0		#move address of y from input (a0) to a3
	la a4, x		#load the address of x to a4
strcpy:
	add s0, zero, zero 	# s0 = i = 0
L1:
	add t1, s0, a3		# t1 = s0 + a1 = i + y[0] = address of y[i]
	lb t2, 0(t1)		# t2 = value at t1 = y[i]
	add t3, s0, a4		# t3 = s0 + a0 = i + x[0] = address of x[i]
	sb t2, 0(t3)		# x[i] = t2 = y[i]
	beq t2, zero, end_of_strcpy # if y[i]==0, exit
	addi s0, s0, 1		# s0 = s0 + 1 <-> i = i + 1
	j L1 			# next character
end_of_strcpy:
