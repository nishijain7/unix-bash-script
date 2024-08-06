echo "enter the file name"
read file
ls -l $file | cut -d ' ' -f 1,2,5,6,7
