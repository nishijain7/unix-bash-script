echo "enter file name"
read file
whoami > $file
echo "enter user name"
read user
grep -o $user $file
if [ $? -eq 0 ]; then
        echo "Exists"
else
        echo "Does not exists"
fi

or

#1/bin/bash
echo "Enter the user name"
read username

if test $username == "codenj"
then
        echo "the user name is correct"
else
        echo "The user name is wrong"
fi
~ 
