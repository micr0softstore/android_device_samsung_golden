if [ $(pidof recovery | wc -w) -eq 1 ]; 
then
    echo "1" 
fi
#setsid /sbin/recovery &
