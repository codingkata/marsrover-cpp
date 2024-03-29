======================================
MarsRover 需求描述
======================================


## 题目背景

在火星的某个位置，新发现了一个高原区域。
经过初步探测后，NASA 发现，这个火星高原是个矩形区域，矩形区域之外是深不见底是深渊。
为了探测这块区域，NASA(美国国家航空航天局)将向该区域发送一小队火星探测车(Mars Rover)，
探测车将探测区域的详细地理情况，其上安装的发送器会将这些数据发送回地球。

### 业务需求

- NASA将这个高原已被划分成一个网格，并将该区域的左下角作为原点。

- 每个火星探测车有一个初始位置 (由一个坐标点 x,y 表示)和朝向(由四个方向的首字母 N，S，W，E 表示)。
```
  例如 0 0 N 表示探测车在原点，面向北放置。关于朝向的定义是：从点(x, y)向(x, y+1)的矢量方向为北(North)。
```

- 控制探测车可以根据收到一串指令，这串指令是由'L', 'R'和'M'组成的字串。
  - 'L'：车原地左转90 度
  - 'R'：则原地向右转 90 度
  - 'M'：原朝向前移一格。

- 火星车执行完所有指令后，会打印出它当前的位置，格式为 x y D（x和y表示坐标，D表求方向）
- 火星车接受指令后，如果移动超过高原边界，它就会掉落深渊。
  - 在其失足的同时，它会打印一个信号，来警告后来的探测车，使其不再重蹈覆辙。
  - 这个信号的格式为 x y D RIP。 RIP就是一个完整指令，表示一个警告"NoMove"。
  - 后面执行任务的火星车当其到达这个RIP位置时，若当前指令是向失足方向移动时，它会忽略该指令，而继续执行下一个指令。

*注意:控制中心一次接收到所有命令后。当前一辆探测车执行完成任务后，下一辆才出发。*

## 软件需求

你现在为 NASA开发一个软件，模拟上面所说的这些系统规则。

### 程序输入: 

程序会得到一个指令系列，这个指令系列如下所示：

- 这个指令系列由多行文本组成
- 第一行指定高原的大小，由两个数字组成，数字间为空格分隔(可能多个)。
- 后续是对多个火星车的指令，两行为一组。
   - 每组的第一行是指定火星车的初始位置。由两个整数和一个字符组成，由空格分隔(可能多个)，分别对应探测车 的 x 坐标和 y 坐标，以及它的朝向。
   - 每组的第二行是可能包含'LRM'的一系列字符串，告诉火星车如何移动。
   - 第一行的输入如果无法解析，程序要求重新输入新的位置

每个探测车按顺序完成任务的，也就是说，只有第一个车完成移动后，第二个车才会开始行动。

例如，当程序输入顺序如下如示时：

```
5 5
1 2 N 
LMLMLMLMM
3 3 E
MMM
```

程序输出应该为：

```
1 3 N
5 3 E RIP
```