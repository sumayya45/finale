echo "enter 5 number"
read n1 n2 n3 n4 n5
greatest=$(echo "$n1 $n2 $n3 $n4 $n5" | tr ' ' '\n' | sort -rn | head -1)
echo "the greatest of all is : $greatest"
