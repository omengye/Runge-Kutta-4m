#4阶龙格库塔(c++ version)
参考了[agodunov](http://ww2.odu.edu/~agodunov/book/programs.html)中的Ordinary Differential Equations,以及运用了stl的vector来操作数组。 

为了匹配使用matlab的一些习惯,编写了linspace和steps两个函数.其中使用steps用来控制龙格库塔计算时的步长. 

0:0.3:1 相当于 steps(0,0.3,1), 

linspace与matlab中linspace用法一致. 

编写了形如 y'=x 的,1维微分方程(rk4_1st),2维微分方程(rk4_2nd),以及n维微分方程(rk4_dn1)的c++实现.

