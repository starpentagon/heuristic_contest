# 引数がない場合はexit
if [ $# -ne 1 ]; then
  echo "Usage: $0 <testcase>"
  exit 1
fi

make clean > /dev/null
make -j > /dev/null

# 引数で指定されたseedを使ってテストケースを実行する
echo "run test $1"
# echo 01_testset/in/$1.txt | ./main | iconv -t UTF-16LE  | clip.exe
echo 01_testset/in/$1.txt | ./main | iconv -t UTF-16LE
