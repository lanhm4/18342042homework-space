#实验名称：机器指令编程
##18342042

#目录

###program1------------------18
###program2------------------38

#实验目标：
* 理解冯·诺伊曼计算机的结构         

* 理解机器指令的构成           

* 理解机器指令执行周期            

* 用汇编编写简单程序              

# program1
1) 
PC用来储存当前指令的地址，并且在当前指令执行完毕后自动指向下一个指令的地址。        

IR用来存储当前指令。        

2)
ACC全称为accumulator,用来存储中间结果。       

3)
LOD # 3:        
首先，IR收到指令，并且Decode解码，然后MUX读取指令里的3，并通过bus将3存入ACC中。     

4)
ADD W:      
首先，IR收到指令，并且Decode解码，然后MUX读取指令里的地址，在通过地址读取地址里的内容，最后，通过bus将W里的内容传到ALU，ALU将ACC里的值与传过来的值相加，所得结果存入ACC。       

5)
前者指令里的数字被直接使用，后者指令里的数字是一个地址，地址里的内容才是想要操作的数字。        

# program2
1)
每次x减1，直到x等于0为止。      

2)
 #include<stdio.h>

int main() {
    int x = 3;
    while(x) {
        x--;
    }
    return 0;
}

3)
定义变量sum=0,i=1。用for语句，sum+=i(i<=10)。       

4)
机器语言则是将i存储到寄存器里，每次sum都加上i，然后i加上1，判断i是否大于10，不大于则用JMP跳回sum加i那条指令，每次都将结果储存在地址Y里。        

5)
高级语言是机器语言的抽象使用，编程者可以用更类似与人类的自然语言编程，而机器语言则是机器使用，机器只能执行由机器语言组成的指令。        


#小结：
这次实验让我了解了机器到底是如何执行我们下达的指令的，对于计算机的原理我有了更充分的了解。          

步骤：
![](http://a4.qpic.cn/psb?/V14CiVqW3GWRJY/EYEAsHSgBoLYMGUzxjWbFspRMgolcTMDR8oD3JINwAA!/c/dDMBAAAAAAAA&ek=1&kp=1&pt=0&bo=4wJxAQAAAAARF7E!&tl=3&vuin=2382454583&tm=1541685600&sce=60-2-2&rf=0-0)

![](http://a4.qpic.cn/psb?/V14CiVqW3GWRJY/589odwPIZQ3iAIXF33dXP9NZX17YFdv5FghVYOffpr0!/c/dC8BAAAAAAAA&ek=1&kp=1&pt=0&bo=6QJ0AQAAAAARF74!&tl=3&vuin=2382454583&tm=1541685600&sce=60-2-2&rf=0-0)