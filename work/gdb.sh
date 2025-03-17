core_dir="/mnt/c/Users/starr/AppData/Local/Temp/wsl-crashes/"
gdb main $core_dir/`ls -t $core_dir | head -n 1`
