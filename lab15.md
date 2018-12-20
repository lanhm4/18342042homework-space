# 智能蛇实验报告            

## 目录     

* 实验目的                      
* 实验步骤与结果            
* C语言实现                 
* 实验小结              

## 一、实验目的     

了解 算法 与 “智能” 的关系 通过算法赋予蛇智能 了解 Linux IO 设计的控制               
## 二、实验步骤与结果            

编写人工智能程序，使得 snake 每秒自动走一步。       

## 三、C语言实现        

### 1、决策函数         

    char whereGoNext(int Hx, int Hy, int Fx, int Fy)
    {
    char movable[4] = {'a', 'd', 'w', 's'};
    int distance[4] = {0, 0, 0, 0};
    distance[0] = map[Hy][Hx - 1] == 0 || map[Hy][Hx - 1] == -1 ? abs(Fx - (Hx - 1)) + abs(Fy - Hy) : 9999;
    distance[1] = map[Hy][Hx + 1] == 0 || map[Hy][Hx + 1] == -1 ? abs(Fx - (Hx + 1)) + abs(Fy - Hy) : 9999;
    distance[2] = map[Hy - 1][Hx] == 0 || map[Hy - 1][Hx] == -1 ? abs(Fx - Hx) + abs(Fy - (Hy - 1)) : 9999;
    distance[3] = map[Hy + 1][Hx] == 0 || map[Hy + 1][Hx] == -1 ? abs(Fx - Hx) + abs(Fy - (Hy + 1)) : 9999;
    int i, min_index = 0;
    for (i = 0; i < 4; i++)
    {
        if (distance[i] < distance[min_index])
            min_index = i;
    }
    return movable[min_index];
    }

### 2、移动函数           

    int move(char cmd)
        {
        cmd = toupper(cmd);
        int row_head, col_head, i, j;
        for (i = 0; i < SIZE; i++)
        {
        for (j = 0; j < SIZE; j++)
        {
            //tail
            if (map[i][j] == snake_length)
                map[i][j] = 0;
            //body
            else if (map[i][j] > 1)
                map[i][j]++;
            //head
            else if (map[i][j] == 1)
            {
                map[i][j]++;
                switch (cmd)
                {
                case 'A':
                    row_head = i;
                    col_head = j - 1;
                    break;
                case 'D':
                    row_head = i;
                    col_head = j + 1;
                    break;
                case 'W':
                    row_head = i - 1;
                    col_head = j;
                    break;
                case 'S':
                    row_head = i + 1;
                    col_head = j;
                    break;
                default:
                    break;
                }
            }
        }
    }

    //eat food
    if (map[row_head][col_head] == -1)
    {
        map[row_head][col_head] = 1;
        snake_length++;
        //generate new food
        while (1)
        {
            i = rand() % SIZE;
            j = rand() % SIZE;
            if (map[i][j] == 0)
            {
                map[i][j] = -1;
                //计算新的食物位置Fx,Fy
                Fx = j;
                Fy = i;
                break;
            }
        }
    }
    //move blank
    else if (map[row_head][col_head] == 0)
    {
        map[row_head][col_head] = 1;
    }
    //run into wall or body, game over
    else
        return 0;

    return 1;
    }

### 3、输出函数             

    void printMap()
    {
    int i, j;
    system("clear");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (map[i][j] == -2)
                printf("%c", WALL);
            else if (map[i][j] == 0)
                printf("%c", BLANK);
            else if (map[i][j] == -1)
                printf("%c", FOOD);
            else if (map[i][j] == 1)
                printf("%c", HEAD);
            else if (map[i][j] > 1)
                printf("%c", BODY);
        }
        printf("\n");
    }
    }

### 4、代码             

    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #define SIZE 10
    #define HEAD 'H'
    #define BODY 'X'
    #define BLANK ' '
    #define FOOD '$'
    #define WALL '#'

    int map[SIZE][SIZE] = {
    {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
    {-2, 3, 2, 1, 0, 0, 0, 0, 0, -2},
    {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
    {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
    {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
    {-2, 0, 0, 0, -1, 0, 0, 0, 0, -2},
    {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
    {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
    {-2, 0, 0, 0, 0, 0, 0, 0, 0, -2},
    {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
    };

    int snake_length = 3;


    int move(char cmd);

    void printMap();

    int Hx = 3, Hy = 1, Fx = 4, Fy = 5;

    char whereGoNext(int Hx, int Hy, int Fx, int Fy);

    int main()
    {
    char cmd;
    printMap();
    while (1)
    {
        cmd = whereGoNext(Hx, Hy, Fx, Fy);

        switch (cmd)
        {
        case 'a':
            Hx--;
            break;
        case 'd':
            Hx++;
            break;
        case 'w':
            Hy--;
            break;
        case 's':
            Hy++;
            break;
        }
        // cmd = getchar();
        if (cmd == '\n')
            continue;

        if (move(cmd))
            printMap();
        else
        {
            printf("Game Over!\n");
            break;
        }
        sleep(1);
    }

    getchar();
    return 0;
    }

    function whereGoNext(Hx,Hy,Fx,Fy) {
	
    char whereGoNext(int Hx, int Hy, int Fx, int Fy)
    {
    char movable[4] = {'a', 'd', 'w', 's'};
    int distance[4] = {0, 0, 0, 0};
    distance[0] = map[Hy][Hx - 1] == 0 || map[Hy][Hx - 1] == -1 ? abs(Fx - (Hx - 1)) + abs(Fy - Hy) : 9999;
    distance[1] = map[Hy][Hx + 1] == 0 || map[Hy][Hx + 1] == -1 ? abs(Fx - (Hx + 1)) + abs(Fy - Hy) : 9999;
    distance[2] = map[Hy - 1][Hx] == 0 || map[Hy - 1][Hx] == -1 ? abs(Fx - Hx) + abs(Fy - (Hy - 1)) : 9999;
    distance[3] = map[Hy + 1][Hx] == 0 || map[Hy + 1][Hx] == -1 ? abs(Fx - Hx) + abs(Fy - (Hy + 1)) : 9999;
    int i, min_index = 0;
    for (i = 0; i < 4; i++)
    {
        if (distance[i] < distance[min_index])
            min_index = i;
    }
    return movable[min_index];
    }

    int move(char cmd)
    {
    cmd = toupper(cmd);
    int row_head, col_head, i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            //tail
            if (map[i][j] == snake_length)
                map[i][j] = 0;
            //body
            else if (map[i][j] > 1)
                map[i][j]++;
            //head
            else if (map[i][j] == 1)
            {
                map[i][j]++;
                switch (cmd)
                {
                case 'A':
                    row_head = i;
                    col_head = j - 1;
                    break;
                case 'D':
                    row_head = i;
                    col_head = j + 1;
                    break;
                case 'W':
                    row_head = i - 1;
                    col_head = j;
                    break;
                case 'S':
                    row_head = i + 1;
                    col_head = j;
                    break;
                default:
                    break;
                }
            }
            }
        }

    
    if (map[row_head][col_head] == -1)
    {
        map[row_head][col_head] = 1;
        snake_length++;
        //generate new food
        while (1)
        {
            i = rand() % SIZE;
            j = rand() % SIZE;
            if (map[i][j] == 0)
            {
                map[i][j] = -1;
                Fx = j;
                Fy = i;
                break;
            }
        }
    }
    else if (map[row_head][col_head] == 0)
    {
        map[row_head][col_head] = 1;
    }
    
    else
        return 0;

    return 1;
    }

    void printMap()
    {
    int i, j;
    system("clear");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (map[i][j] == -2)
                printf("%c", WALL);
            else if (map[i][j] == 0)
                printf("%c", BLANK);
            else if (map[i][j] == -1)
                printf("%c", FOOD);
            else if (map[i][j] == 1)
                printf("%c", HEAD);
            else if (map[i][j] > 1)
                printf("%c", BODY);
        }
        printf("\n");
    }
    }

## 四、实验小结     

本次实验主要就是利用一些函数将蛇的动作分解开，然后一一实现。通过编写这个程序，我的编程能力得到了进一步的提高。              