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

# 公式Visualizerで実行
echo "run test seed=1"
java -jar tester.jar -exec "./main" -novis -seed 1

# ソースをコピー
contest_no="mmXXX"
contest_name="Contest Name"

echo "copy to /mnt/c/test/$contest_no/tester/"
cp combined.cpp /mnt/c/test/$contest_no/submit/$contest_name.cpp

