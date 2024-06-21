suma=() 
read -p "enter the number of students : " stud
for((i=0;i<stud;i++)); do
	read -p "enter the rool no of the students : " roll
	suma+=("$roll")
done
len=${#suma[@]}
for((i=0;i<$len-1;i++))
do 
	for((j=0;j<$len-$i-1;j++))
	do
		if [[ ${suma[$j]} -lt ${suma[(($j+1))]} ]];
	then
		temp=${suma[$j]}
		suma[$j]=${suma[(($j+1))]}
		suma[(($j+1))]=$temp
	fi
	done
done
echo "array in descending is : "
for ((i=0 ; i<len ; i++))
do 
	echo ${suma[$i]}
done
#srting=($(for i in "${#suma[@]}"; do echo $i; done | sort -n))

#echo "the student rool no are : ${suma[@]}"
#echo "the no of students are :${#suma[@]}"
#echo "the sorted elements in the array are : ${srting[@]}"

