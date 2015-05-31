.text
	main:
		addi $a0, $a0, 5	# n = 5
		jal factorial		# call factorial procedure 
		li $v0, 10
		syscall
		
	factorial:
		slti $t0, $a0, 1	# $t0 only equals 0 when $a0 = 1
		beq $t0, $zero, L1
		addi $v0, $zero, 1
		addi $sp, $sp, 8
		jr $ra
		
	L1:				# the loop that handles decrementing n
		addi $sp, $sp, -8
		sw $ra, 4($sp)
		sw $a0, 0($sp)
		addi $a0, $a0, -1
		jal factorial
		lw $a0, 0($sp)
		lw $ra, 4($sp)
		addi $sp, $sp, 8
		mul $v0, $a0, $v0
		jr $ra