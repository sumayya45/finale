echo "enter 5 number"
read n1 n2 n3 n4 n5
smallest=$(echo "$n1 $n2 $n3 $n4 $n5" | tr ' ' '\n' | sort -n | head -1)
echo "the smallest of all is : $smallest"
