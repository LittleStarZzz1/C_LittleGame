#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//完成对结构体的排序,通过传入判断大小的函数来实现
//模拟扑克牌的实现和手牌排序

//首先定义一个结构体
struct Poker
{
	char type;	//花色
	int point;	//大小
};

enum
{
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,
	JOKER
};

void inputpoker(Poker * pk)
{
	scanf("%c%d", &pk->type, &pk->point);

	pk->type -= 'a';
	if (pk->type == JOKER)
	{
		pk->point += 13;
	}

	while (getchar() != '\n');

}

void outputpoker(Poker k)
{
	char * type[5] = { "黑桃", "红桃", "梅花", "方片", "" };
	char * point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };

	printf("%s%s\n", type[k.type], point[k.point]);
}

bool cmppoker(Poker a, Poker b)
{
	return (a.point < b.point) || (a.point == b.point && a.type > b.type);
}

void InsertSort(Poker * src, int n, bool (*cmp)(Poker, Poker) = cmppoker)
{
	int i, j;
	Poker tmp;

	for (i = 1; i < n; ++i)
	{
		tmp = src[i];
		for (j = i; j > 0 && cmp(tmp, src[j - 1]); --j)
		{
			src[j] = src[j - 1];
		}

		src[j] = tmp;
	}

}

//此种排序方法3为最小，大王最大，小王次大，接着为2，1
bool PokerCmpPare(Poker a, Poker b)
{
	if (a.point <= 2)
	{
		a.point += 11;
	}
	else if (a.point <= 13)
	{
		a.point -= 2;
	}

	if (b.point <= 2)
	{
		b.point += 11;
	}
	else if (b.point <= 13)
	{
		b.point -= 2;
	}

	return (a.point < b.point) || (a.point == b.point && a.type < b.type);
}

int main()
{
	Poker p[5];

	int i;
	for (i = 0; i < 5; ++i)
	{
		inputpoker(p + i);
	}

	//InsertSort(p, 5);
	InsertSort(p, 5, PokerCmpPare);

	for (i = 0; i < 5; ++i)
	{
		outputpoker(p[i]);
	}

	//Poker p;

	//inputpoker(&p);

	//outputpoker(p);


	system("pause");
	return 0;
}