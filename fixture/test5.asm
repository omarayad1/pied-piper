addi $1, $0, 15
addi $2, $0, 20
xor $3, $2, $1
sw $1, 2($2)
lw $2, 2($2)
sw $3, 2($2)