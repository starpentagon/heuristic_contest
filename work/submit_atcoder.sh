check=`python3 check_update_time.py`
# echo $check

if echo "$check" | grep -q "up to date"; then
   echo "combined.cpp is up to date"
else
   echo "combined.cpp is not up to date, run 80_Expander.ipynb"
   exit 0   
fi

echo "compile combined.cpp"
g++ -std=c++17 combined.cpp -o main

cat combined.cpp | iconv -t UTF-16LE  | clip.exe

