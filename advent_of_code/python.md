
### Open/close a file
    import sys

    file_obj = open("file_name", "r") 
    file_data = file_obj.read()
<p>

    with open("input.txt", 'r') as file:
<p>  

    file_obj.close()
<p> 

### Split per line
    for line in file:
        data = line.split()
<p>  

### Split per word
    lines = file_data.splitlines()
<p>  

### Print
    print()
<p>  

