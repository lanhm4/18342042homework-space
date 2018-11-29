# 贪吃蛇实验报告

## 实验目标:

* 了解字符游戏的表示            

* 体验自顶向下的设计方法实现问题求解            

* 使用伪代码表示算法            

* 使用函数抽象过程          

## 实验步骤与结果:

思路也很简单，如下：            

1. 定义一个11×11的字符数组，当成贪吃蛇的活动空间，对于这个空间，除了边界赋值'*',其余赋值空格，根据自己的需求可以赋值障碍物与'$'。           

2. 定义一个一维数组body[50]，用来记录贪吃蛇的身体。我们不妨为第一步定义的数组定义编号，用a表示第一步定义的数组，a[i][j]的编号就是i×10+j，这样，我们就可以以纯数字的办法记录贪吃蛇的身体在a中的位置。然后，初始化body，body[0]是'H'，其余是'X'。           

3. 接下来用一个循环，如果蛇的头走到了边界或者碰到障碍物，即退出循环。否则，数组整体后移，即for(i=len;i>0;i--)body[i] = body[i-1],然后body[0]根据方向改变。            

4. 如果遇到食物，那么，为body数组增加一个元素,即len加一，还是for(i=len;i>0;i--)body[i] = body[i-1]，这时数组整体看上去就没有移动，只是开头多了一个元素，这个元素按照方向决定位置。              

然后就没有然后了，可以愉快地玩游戏了。          

![](http://a3.qpic.cn/psb?/V14CiVqW3GWRJY/85w1.Boce8FJNF5dxtqYqRvi.sTcsBd8rIAIF.YMZi8!/b/dLYAAAAAAAAA&ek=1&kp=1&pt=0&bo=cADDAwAAAAADF4I!&tl=1&vuin=2382454583&tm=1543500000&sce=60-1-1&rf=viewer_4)

![](http://m.qpic.cn/psb?/V14CiVqW3GWRJY/Q37J44nz2gZ4xq4uFhgTEC9KNyCyIsw9XXbVfRHvPIE!/b/dFIBAAAAAAAA&bo=dQDjAwAAAAADB7c!&rf=viewer_4)

![](http://m.qpic.cn/psb?/V14CiVqW3GWRJY/jAfPTFxRd3SSer4*gZOWc0k8H8OErQFBoWWm.*T5U0o!/b/dFMBAAAAAAAA&bo=KQJvAQAAAAADB2c!&rf=viewer_4)