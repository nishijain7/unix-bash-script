echo "Enter the choice: 1. Add 2. Sub 3. Mul 4. Div 5. Modulo"
read choice
echo "Enter two values"
read r1
read r2

case $choice in
    1) echo "Result: $(expr $r1 + $r2)";;
    2) echo "Result: $(expr $r1 - $r2)";;
    3) echo "Result: $(expr $r1 \* $r2)";;
    4) echo "Result: $(expr $r1 / $r2)";;
    5) echo "Result: $(expr $r1 % $r2)";;
    *) echo "Invalid choice";;
esac
