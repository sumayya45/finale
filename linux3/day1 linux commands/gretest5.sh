num1=100
num2=6
num3=91
num4=7
num5=4

if (($num1 >= $num2)  && ($num1 >= $num3) && ($num1 >= $num4) && ($num1 >= $num5)); then
echo "greter among 5 is $num11"
elif (($num2 -gt $num1 && $num2 -gt $num3 && $num2 -gt $num4 && $num2 -gt $num5)); then
echo "greter among 5 is $num2"
elif (($num3 -gt $num1 && $num3 -gt $num2 && $num3 -gt $num4 && $num3 -gt $num5)); then
echo "greter among 5 is $num3"
elif (($num4 -gt $num1 && $num4 -gt $num2 && $num4 -gt $num3 && $num4 -gt $num5)); then
echo "greter among 5 is $num4"
else
echo "greter among 5 is $num5"
fi

