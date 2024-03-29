#include<bits/stdc++.h>
/*
    链接：https://ac.nowcoder.com/acm/problem/16694
    来源：牛客网

    题目描述
    有形如：ax3+bx2+cx+d=0  这样的一个一元三次方程。给出该方程中各项的系数(a，b，c，d  均为实数)，并约定该方程存在三个不同实根(根的范围在-100至100之间)，且根与根之差的绝对值 ≥ 1。要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后2位。
    提示：记方程f(x) = 0，若存在2个数x1和x2，且x1 < x2，f(x1)*f(x2) < 0，则在(x1，x2)之间一定有一个根。
    输入描述:
    一行，4个实数A,B,C,D。
    输出描述:
    一行，3个实根，并精确到小数点后2位。
    示例1
    输入
    复制
    1 -5 -4 20
    输出
    复制
    -2.00 2.00 5.00
 *
 */

double a,b,c,d;

double equation(double x){
    return a*x*x*x + b*x*x + c*x+ d;
}

int main(){
    std::cin >> a >> b >> c >> d;
    double l,r,m;// 二分查找需要的边界和中间值
    int ret = 0;
    for(int i=-100; i<100;i++){
        if(ret == 3) break;
        if(equation(i) == 0)
        {
            std::cout << std::fixed << std::setprecision(2) << i*1.0 << " ";
            ret++;
        }
        else if(equation(i)*equation(i+1) < 0){// 当符合根条件时，进行二分查找
            l=i,r=i+1;
            while(r-l >= 0.01)
            {
                m = (r+l)/2;
                if(equation(m)*equation(r) <= 0)// 等于0情况出现时，说明根为m,此时右边界r向m点靠拢
                    l = m;
                else
                    r = m;
            }
            std::cout << std::fixed << std::setprecision(2) << (r+l)/2 << " ";// 这里需要注意，输出值应该为中点值，因为存在r和l的小数点后两位相差0.01，但仍满足r-l<0.01，例如：0.124和0.132
            ret++;
        }
    }

    if(equation(100) == 0)
        std::cout << std::fixed << std::setprecision(2) << 100.0;

    return 0;
}

