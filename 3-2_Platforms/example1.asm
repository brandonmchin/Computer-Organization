.data
	a: .word 2
	b: .word 4

.text
	lw $t0, a
	lw $t1, b
	add $t2, $t0, $t1	# t2 = t0 + t1