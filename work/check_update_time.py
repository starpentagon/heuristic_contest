# combined.cppとそれ以外のcpp, hppの更新時間を比較して、combined.cppが最新でなければwarningを出す
import os
import time

def get_latest_file_time(directory):
   latest_time = 0
   
   for root, dirs, files in os.walk(directory):
      for file in files:
         if file.endswith('.cpp') or file.endswith('.hpp'):
            file_path = os.path.join(root, file)
            file_time = os.path.getmtime(file_path)
            
            if file_time > latest_time:
               latest_time = file_time
   
   return latest_time

def check_combined_file_time(directory):
   combined_file_path = os.path.join(directory, 'combined.cpp')
   
   if not os.path.exists(combined_file_path):
      print(f"Error: {combined_file_path} does not exist.")
      return
   
   combined_file_time = os.path.getmtime(combined_file_path)
   latest_file_time = get_latest_file_time(directory)
   
   if latest_file_time > combined_file_time:
      print(f"Warning: {combined_file_path} is older than other cpp/hpp files.")
   else:
      print(f"{combined_file_path} is up to date.")

if __name__ == "__main__":
   directory = os.path.dirname(os.path.abspath(__file__))
   check_combined_file_time(directory)