# 使用Construct 2制作一个小游戏

* 下载 Construct 2

到官网去下载。地址是  https://www.scirra.com/construct2  选择free版本即可。

* 安装

不需要什么特别的变动，一直按next即可

* 新建一个文件

打开Construct 2,并在左上角的file中选择**new**--------> **new empty project**         
![](https://www.scirra.com/images/articles/filenew.png)     
选择右下角的 **open**即可。       
![](https://www.scirra.com/images/articles/newprojdialog65.png)

* 添加背景

在空白处双击，会出现这样的图片    

![](https://www.scirra.com/images/articles/insertobject.png)    
选择红圈中的选项，双击以插入一个背景。      

这时你的鼠标会变成十字，随意点击一个空白处   

![](https://www.scirra.com/images/articles/loadtexturefromfile.png)      
点击左上角的load an image from a file按钮，从你的电脑中选择你希望作为背景的图片。   

然后关闭这个对话框。     

在左侧的properties的position中，输入参数0,0。   

size中输入1280,1024。以便背景图片能够覆盖整个编辑面板。     

![](https://www.scirra.com/images/articles/tiledproperties.png)

* 插入一个新的layer

在右侧的属性框中，选择layer。    

![](https://www.scirra.com/images/articles/layerstab.png)     

你应该看见Layer 0在这个列表中，点击铅笔图标重命名它为background，以便区分。    

点击锁头图标以锁定background。    

这样你不会不小心点击到它，而带来麻烦。     

然后你需要点击左上角的加号图标，新增一个layer。       

你可以把它命名为main，表示这是主要的layer。    

做好这一切后，你的界面应该长这样：    

![](https://www.scirra.com/images/articles/layersbar.png)     

最后，确保你选定的是main。     

否则你将不小心将之后的操作插入到错误的层里。     

* 插入输入对象

双击背景图片上的任意一处，在弹出的对话框中插入Mouse。     

因为这个游戏需要鼠标。    

同样的操作，这次插入keyboard。     


* 插入游戏对象

现在，你可以插入游戏中出现的东西了。      

保存以下图片在你的电脑某处     

玩家：![](https://www.scirra.com/images/articles/player.png)       

怪物：![](https://www.scirra.com/images/articles/monster.png)    

子弹：![](https://www.scirra.com/images/articles/Bullet.png)      

爆炸：![](https://www.scirra.com/images/articles/explode.png)     

双击，在对话框中选择sprite。    

然后点击insert。     

鼠标变成十字后，随意点击一处。     

在弹出的对话框中    

像插入背景时那样将四个游戏对象一一插入    

在属性栏中有name这项，你可以在此重命名。    

重命名他们，以便你不会将它们搞混。    





