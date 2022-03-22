# Python program to format C/C++ files using clang-format
import os

# File Extension filter. You can add new extension
c_extensions = (".c", ".h")

# Set the current working directory for scanning c sources (including
# header files) and apply the clang formatting
# Please note "-style" is for standard style options
# and "-i" is in-place editing
for root, dirs, files in os.walk(os.getcwd()):
    for file in files:
        if file.endswith(c_extensions):
            print(root + "/" + file)
            os.system("clang-format -i --style=WebKit " + root + "/" + file)
