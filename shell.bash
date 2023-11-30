# echo "enter"
# read a b
# a=`expr $a + $b`
# b=`expr $a - $b`
# a=`expr $a - $b`
# echo $a $b

# echo "enter"
# read a
# if (( a % 2 == 0 ))
# then echo "even"
# else echo "odd"
# fi

# echo "enter"
# read a b c
# if (( a > b ))
# then
#     if (( a > c ))
#     then echo "a"
#     else echo "c"
#     fi
# else
#     if (( b > c ))
#     then echo "b"
#     else echo "c"
#     fi
# fi

# echo "enter"
# read a
# f=1
# for (( i=1 ; i <= a ; i++ ))
# do
#     (( f=( f * i ) ))
# done
# echo $f

# echo "enter"
# read n
# r=0
# while (( n > 0 ))
# do
#     (( r=( ( r * 10 ) + ( n % 10 ) ) ))
#     (( n=( n / 10 ) ))
# done
# echo $r

# echo "enter"
# read a
# f=0
# for (( i=2 ; i < a ; i++))
# do
#     if (( a % i == 0 ))
#     then
#         f=1
#         break
#     else continue
#     fi
# done
# if (( f == 0 ))
# then echo "prime"
# else echo "not prime"
# fi

# echo "enter"
# read y
# if (( ( y % 100 != 0 && y % 4 == 0 ) || y % 400 == 0 ))
# then echo "leap year"
# else echo "not leap year"
# fi