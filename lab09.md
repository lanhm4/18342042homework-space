# 洗衣机算法设计



## 注水、浸泡、洗涤、甩干。			
	

### 注水：	

WATER_IN_SWITCH(open)//放水进洗衣机。		

SET waterVolume//设置变量记录水位。			

SET standarWaterVolume//设置应该放入的水量。		

READ standarWaterVolume//等待用户输入。			

GET_WATER_VOLUME()//检测水位。		

SET waterVolume to GET_WATER_VOLUME()//赋值。		

WHILE(standarWaterVolume - waterVolume > 0)			

{			
}		

//水没满就什么都不做。		

WATER_IN_SWITCH(close)			

//水满了就关水龙头。		

### 浸泡：

SET soakTime				

READ soakTime//等待用户输入希望浸泡的时间。			

TIME_COUNTER()//读取时间。				

WHILE(soakTime > TIME_COUNTER())		

{			
}			

//浸泡时间不够就什么都不做。		

### 洗涤：

SET washTime		

READ washTime//等待用户输入希望洗涤的时间。			

TIME_COUNTER()//读取时间。				

WHILE(washTime > TIME_COUNTER())		

{
    
	MOTOR_RUN(left)			

	MOTOR_RUN(right)			
}

//没到时间就左转一次，右转一次，保证洗的干净。				

### 甩干：

WATER_OUT_SWITCH(open)//放水。			

WHILE(GET_WATER_VOLUME() != 0)				

{			

	MOTOR_RUN(left)			

	MOTOR_RUN(right)	

}			

//水没放完就转，把水全都转出去。