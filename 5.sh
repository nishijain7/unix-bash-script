echo "enter the file name"
read file
echo "enter the pattern"
read pattern
grep -o $pattern $file
if [ $? -eq 0 ]; then

        echo "patten  found"
else
        echo "pattern  not found"
fi
~    #exit status is used

