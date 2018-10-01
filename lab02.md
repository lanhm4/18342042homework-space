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

* 为游戏对象添加行为

点击玩家，看向左侧的属性栏     

在behaviors一栏中，点击Add/edit。如下图      

![](https://www.scirra.com/images/articles/openbehaviors.png)      

点击左上角的加号图标，插入8 direction movement。     

![](https://www.scirra.com/images/articles/add8dir.png)     

类似的，插入以下几个behivors。      

![](https://www.scirra.com/images/articles/playerbehaviors_2.png)    

再往后，为子弹插入Bullet movement和Destroy outside layout。     

为怪兽插入Bullet movement。    

为爆炸插入fade。   

最后，修改属性栏中Bullet movement的速度。     
单击界面中的玩家图标，看向左侧的属性栏。如图：     

![](https://www.scirra.com/images/articles/bulletproperties.png)

将子弹的Speed改成600，怪物的Speed改成80。     

同样，单击爆炸图标，在左侧将爆炸的fade out time改为0.5。    

* 添加多个怪兽   

按下ctrl键，然后拖动怪物，这样就可以复制很多怪物对象。     

添加7到8个即可，且怪兽别离玩家太近。     

不然一开始游戏玩家会很快死掉。     

* 添加事件

在编辑面板的最上方，你会看见下图：    

![](https://www.scirra.com/images/articles/eventsheettab.png)     

点击红圈中的event以添加新事件。     

在空白处双击，出现以下对话框：    

![](https://www.scirra.com/images/articles/newevent_2.png)     

点击system中的every tick:     

![](https://www.scirra.com/images/articles/everytickcnd.png)    

然后你的界面应该长这样：    

![](https://www.scirra.com/images/articles/everytickempty.png)     

现在点击右侧的add action。     

![](https://www.scirra.com/images/articles/addactiondlg.png)     

双击玩家。     

在此双击以加入set angle toward position。     

![](https://www.scirra.com/images/articles/playersetanglepos.png)     

然后软件会要求你输入参数。    

![](https://www.scirra.com/images/articles/setangleposparams.png)      

在X处输入Mouse.X，Y处输入Mouse.Y。     

大功告成，你的页面看起来应该是这样的：     

![](https://www.scirra.com/images/articles/alwayslookatmouse.png)     

现在你已经掌握了插入事件的基本套路。    

你之前的操作可以总结为：   

Add condition System -> Every tick       
Add action Player -> Set angle towards position -> X: Mouse.X, Y: Mouse.Y        

你需要熟悉这个格式，因为此后的操作会用这种格式来说明。     

然后你需要再次插入以下事件：     

![](https://www.scirra.com/images/articles/spawnbullet1.png)     

Condition: Mouse -> On click -> Left clicked (the default)      
Action: Player -> Spawn another object -> For Object      

然后，在弹出的对话框中双击子弹。     

对于layer,输入1，对于image point,让他保留0。    

为了让子弹从枪口射出而不是从玩家的中心射出，你需要进行一点修改。    

右键单击玩家，选择Edit animation。     

![](https://www.scirra.com/images/articles/editanimations.png)     

图像编辑器重新出现，在左下角选择：    

![](https://www.scirra.com/images/articles/imagepointstool.png)    

然后弹出一个这样的对话框:    

![](https://www.scirra.com/images/articles/imagepointsdlg.png)     

点击左上角的加号，然后点击玩家图标的枪口：   

![](https://www.scirra.com/images/articles/placingimagepoint.png)       

关闭对话框，然后回到此前的编译框（双击swpan another object）      

将image的参数由0改为1。     

为了让子弹可以杀死怪兽，进行以下操作：    

Condition: Bullet -> On collision with another object -> pick Monster.       
Action: Monster -> Destroy      
Action: Bullet -> Spawn another object -> Explosion, layer 1       
Action: Bullet -> Destroy      

* 让爆炸图片的黑框消失   

单击爆炸图标     

在左侧的属性栏中，看向最底部。     

将Blend mode的状态由normal改为Additive。    

* 让怪兽更聪明

此时运行游戏，怪兽只是单纯的向右走。   

为了让他更“聪明”，你需要修改一些东西。     

进行以下操作：      

Condition: System -> On start of Layout      
Action: Monster -> Set angle -> random(360)       

![](https://www.scirra.com/images/articles/ghostshooterevent4.png)      

但是这时怪物会跑出界面，然后乱撞。     

为了让它们老实的待在界面内    

也为了让它们在玩家静止不动时冲向玩家     

添加以下事件：     

Condition: Monster -> Is outside layout       
Action: Monster -> Set angle toward position -> For X, Player.X - for Y, Player.Y.       

* 为怪兽设置血条

点击怪兽图标，找到instance variable,如下图：   

![](https://www.scirra.com/images/articles/instvars.png)     

按照红色箭头指示的那样依次点击。      

将instance variable的名字改为health，以便表示他们是怪兽的生命值。       

在Initial variable中输入初始值，即怪兽刚开始的血量。    

你可以输入5，也可以输入任何你喜欢的数字。     

![](https://www.scirra.com/images/articles/healthinstvar.png)      

然后点击OK。    

![](https://www.scirra.com/images/articles/healthadded.png)       



