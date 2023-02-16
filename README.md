[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/abouhlel/push_swap)](https://github.com/JaeSeoKim/badge42)

RUN THE PROGRAM 
- make
- ./push_swap <list of nbrs>

Max for a list of 500   ---> 11500
  
Max for a list of 100   ---> 1100
  
Max for a list of 5     ---> 12

Max for a list of 3     ---> 3

RUN THE TEST
./test.sh 1 500 
./test.sh 1 500 | wc -l  

RUN THE VISUALISER
- put the executable in the folder first
- ```python3 pyviz.py \`ruby -e "puts (-200..200).to_a.shuffle.join(' ')"\` ```  

RUN THE TESTER
- rename Checker_Mac to checker & give it ALL the POWERS !!!!
- ./terter.sh .. 500 100     // runs 100 tests with lists of 500 nbrs
