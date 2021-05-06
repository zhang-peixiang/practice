#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
using namespace std;


// 有一颗无穷大的满二叉树，其结点按照根节点一层一层地往右依次编号，根结点编号为1。
// 现有两个节点a，b。设计一个算法求a和b点地最近公共祖先地编号

class LCA {
public:
	int getLCA(int a, int b) {
		// 保证a是最小数
		if (a>b)
		{
			swap(a, b);
		}
		int min = 0;
		int max = 0;
		int reta = 0;
		int retb = 0;
		// 确定a，b在二叉树的第几层
		while (1)
		{
			min = pow(2, reta);
			max = min * 2;
			if (a >= min && a<max)
			{
				break;
			}
			reta++;
		}
		retb = reta;
		while (1)
		{
			min = pow(2, retb);
			max = min * 2;
			if (b >= min && b<max)
			{
				break;
			}
			retb++;
		}
		// 将a和b放在二叉树的同一层
		while (reta<retb)
		{
			b /= 2;
			retb--;
		}
		// 判断是否是同一根节点
		while (a / 2 != b / 2)
		{
			a /= 2;
			b /= 2;
		}
		return a / 2;
	}
};
