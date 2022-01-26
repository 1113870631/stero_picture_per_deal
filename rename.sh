#!/bin/bash

#重命名 IMG_00xx.jpg 图像
#
i=0
for FILE in ./*.jpg
	do 
    rename  's/IMG_//' *
    done


for file in `ls`;do
        #echo $file
        tmp1=${file##*.}
        tmp2="jpg"
        #echo $tmp1
        #echo $tmp2
       if [ $tmp1 = $tmp2 ] #判断后缀名是否为图片
        then 
        echo ${file##*.}
        mv ${file} "${i}.jpg"  #重命名
        echo ${i}
       i=`expr $i + 1`
        fi 
        
done

