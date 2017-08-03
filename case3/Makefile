##################   变量   ###################
# objects = main.o kbd.o command.o display.o /
# case : $(objects)
# g++ -o case1 $(objects)
###############################################

################ 自动推导 ######################
# 只要make看到一个[.o]文件，它就会自动的把[.c]文件加在
# 依赖关系中，如果make找到一个whatever.o，那么whatever.c，
# 就会是whatever.o的依赖文件。并且 cc -c whatever.c 也会
# 被推导出来
# case : $(objects)
# g++ -o case $(objects)
# main.o : sub_case.h
##############################################
objects = main.o intset.o

case3 : $(objects)
	g++ -o case3 $(objects)

main.o : intset.h
intset.o : intset.h

.PHONY : clean
clean : 
	-rm case3 $(objects) 


