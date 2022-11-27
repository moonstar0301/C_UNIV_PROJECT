#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define INF 100000
#define NUMBERR 13
#define NUMBER 24

//전체 그래프를 초기화 합니다.
int aa[13][13] = {
	{0,3,INF,INF,INF,INF,INF,INF,INF,INF,3,INF,INF},
	{INF,0,4,INF,INF,INF,INF,INF,INF,INF,3,INF,INF},
	{3,4,0,3,3,INF,6,INF,INF,INF,INF,INF,INF},
	{INF,INF,3,0,1,INF,INF,INF,INF,INF,4,INF,INF},
	{INF,INF,3,1,0,INF,INF,6,INF,INF,INF,INF,3},
	{INF,INF,INF,INF,INF,0,2,3,INF,INF,INF,INF,2},
	{INF,INF,6,INF,INF,2,0,INF,INF,INF,INF,INF,2},
	{INF,INF,INF,INF,6,3,INF,0,INF,INF,INF,5,4},
	{INF,INF,INF,INF,INF,INF,INF,INF,0,3,INF,2,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,3,0,3,3,INF},
	{3,3,INF,4,INF,INF,INF,INF,INF,3,0,INF,INF},
	{INF,INF,INF,INF,INF,INF,INF,5,2,3,INF,0,6},
	{INF,INF,INF,INF,3,2,2,4,INF,INF,INF,6,0},


};

bool vv[13]; //방문한 노드입니다.
int dd[13]; //거리입니다.

int a[24][24] = {
	{0,2,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,4,4,INF,INF,INF,INF,INF,INF,INF,INF,INF},
	{2,0,3,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,5,INF,INF,INF,INF,INF,INF,INF,INF},
	{INF,3,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,2,4,INF,INF,INF,INF,INF},
	{INF,INF,INF,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,4,4,INF,4,INF,INF,INF},
	{INF,INF,INF,INF,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,2,INF,INF,INF,INF,INF},
	{INF,INF,INF,INF,INF,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,2,INF,INF,INF,INF,INF},
	{INF,INF,INF,INF,INF,INF,0,3,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,3},
	{INF,INF,INF,INF,INF,INF,3,0,3,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,5},
	{INF,INF,INF,INF,INF,INF,INF,3,0,3,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,5,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,3,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,4,INF,3,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,INF,0,3,INF,INF,INF,INF,INF,INF,INF,INF,5,2,4,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,3,0,INF,INF,INF,INF,INF,INF,INF,INF,4,INF,INF,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,INF,INF,3,3,4,INF,INF,INF,INF,INF,INF},
	{4,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,3,3,INF,INF,INF,INF,INF,INF,INF,INF},
	{4,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,3,0,INF,INF,INF,INF,INF,INF,INF,INF,INF},
	{INF,5,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,3,3,INF,0,INF,INF,INF,INF,INF,INF,INF,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,3,INF,INF,INF,0,INF,INF,INF,INF,INF,INF,INF},
	{INF,INF,2,4,INF,INF,INF,INF,INF,INF,INF,INF,4,INF,INF,INF,INF,0,4,INF,INF,INF,INF,INF},
	{INF,INF,4,4,2,2,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,4,0,INF,INF,INF,INF,INF},
	{INF,INF,INF,INF,INF,2,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,INF,INF,INF,INF},
	{INF,INF,INF,4,INF,INF,INF,INF,INF,4,5,4,INF,INF,INF,INF,INF,INF,INF,INF,0,INF,INF,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,2,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,INF,INF},
	{INF,INF,INF,INF,INF,INF,INF,INF,5,3,4,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,INF},
	{INF,INF,INF,INF,INF,INF,3,5,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0},
};

bool v[24]; //방문한 노드입니다.
int d[24]; //거리입니다.

//가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallINdexx() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < NUMBERR; i++) {
		if (dd[i] < min && !vv[i]) {
			min = dd[i];
			index = i;
		}
	}
	return index;
}

void dijkstraa(int start) {
	for (int i = 0; i < NUMBERR; i++) {
		dd[i] = aa[start][i];
	}
	vv[start] = true;
	for (int i = 0; i < NUMBERR - 2; i++) {
		int current = getSmallINdexx();
		vv[current] = true;
		for (int j = 0; j < 13; j++) {
			if (!vv[j]) {
				if (dd[current] + aa[current][j] < dd[j]) {
					dd[j] = dd[current] + aa[current][j];
				}
			}
		}
	}
}

void run(void)
{
	int loc, i, j;
	char* name[3] = { "정보센터식당", "복지관", "공식당" };
	char ch[20] = "";
	typedef struct {
		int location;
		int value;
	} EMP;

	EMP emp[3];
	EMP temp;

	printf("위치를 입력해주세요\n");
	printf("농대4호관 : 0\n");
	printf("예대 : 1\n");
	printf("농대1,2,3호관 : 2\n");
	printf("인문대 : 3\n");
	printf("인문진흥관 : 4\n");
	printf("공대1,2호관 : 5\n");
	printf("공대3,6호관 : 6\n");
	printf("IT대학 : 7\n");
	printf("경상대 : 8\n");
	printf("사범대 : 9\n");

	scanf_s("%d", &loc);
	dijkstraa(loc);

	for (i = 0; i < 3; i++)
	{
		emp[i].location = i;
		emp[i].value = dd[i+10];
	}

	//오름차순 정렬
	for (i = 2; i > 0; i--)
		for (j = 0; j < i; j++)
		{
			if (emp[j].value > emp[j + 1].value)
			{
				temp = emp[j];
				emp[j] = emp[j + 1];
				emp[j + 1] = temp;
			}
		}

	if (emp[0].location == 0)
		strcpy(ch, name[0]);
	else if (emp[0].location == 1)
		strcpy(ch, name[1]);
	else if (emp[0].location == 2)
		strcpy(ch, name[2]);


	printf("가장 가까운 식당은 %s입니다.\n", ch);
	printf("거리는 %dm입니다.\n", emp[0].value * 100);
	printf("도보로 %.2lf분 소요됩니다..\n", (double)emp[0].value * 10 / 6.6);
}

//가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallINdex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < NUMBER; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < NUMBER; i++) {
		d[i] = a[start][i];
	}
	v[start] = true;
	for (int i = 0; i < NUMBER - 2; i++) {
		int current = getSmallINdex();
		v[current] = true;
		for (int j = 0; j < 13; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

void run2(void)
{
	int loc, i, j;
	char* name[10] = {
		"GS25 경북대점",
		"GS25 복현회관점",
		"세븐일레븐 경대북문점",
		"세븐일레븐 경대공학관점",
		"GS25 경북대생활관점",
		"이마트24 경북대남문점",
		"GS25 경북대도서관점",
		"세븐일레븐 경대테크노파크점",
		"GS25 경북대첨성관점",
		"GS25 경북대정문점"
	};
	char ch[40] = "";
	typedef struct {
		int location;
		int value;
	} EMP;

	EMP emp[10];
	EMP temp;

	printf("위치를 입력해주세요\n");
	printf("야구장 : 0\n");
	printf("축구장 : 1\n");
	printf("공대1,2호관 : 2\n");
	printf("IT대학 : 3\n");
	printf("공대3,6,7 : 4\n");
	printf("기숙사 : 5\n");
	printf("수의대 : 6\n");
	printf("센트럴파크 : 7\n");
	printf("경상대학 : 8\n");
	printf("사범대학 : 9\n");
	printf("농대4호관 : 10\n");
	printf("예술대학 : 11\n");
	printf("농대1,2,3호관 : 12\n");
	printf("체육관 : 13\n");

	scanf_s("%d", &loc);
	dijkstra(loc);

	for (i = 0; i < 10; i++)
	{
		emp[i].location = i;
		emp[i].value = d[i + 14];
	}

	//오름차순 정렬
	for (i = 9; i > 0; i--)
		for (j = 0; j < i; j++)
		{
			if (emp[j].value > emp[j + 1].value)
			{
				temp = emp[j];
				emp[j] = emp[j + 1];
				emp[j + 1] = temp;
			}
		}

	if (emp[0].location == 0)
		strcpy(ch, name[0]);
	else if (emp[0].location == 1)
		strcpy(ch, name[1]);
	else if (emp[0].location == 2)
		strcpy(ch, name[2]);
	else if (emp[0].location == 3)
		strcpy(ch, name[3]);
	else if (emp[0].location == 4)
		strcpy(ch, name[4]);
	else if (emp[0].location == 5)
		strcpy(ch, name[5]);
	else if (emp[0].location == 6)
		strcpy(ch, name[6]);
	else if (emp[0].location == 7)
		strcpy(ch, name[7]);
	else if (emp[0].location == 8)
		strcpy(ch, name[8]);
	else if (emp[0].location == 9)
		strcpy(ch, name[9]);

	printf("가장 가까운 편의점은 %s입니다.\n", ch);
	printf("거리는 %dm입니다.\n", emp[0].value * 100);
	printf("도보로 %.2lf분 소요됩니다..\n", (double)emp[0].value * 10 / 6.6);
}

int main(void) {
	int check;
	printf("학생식당을 찾고싶으면 1을 입력\n");
	printf("편의점을 찾고싶으면 2을 입력하세요.\n");
	scanf_s("%d", &check);
	if (check == 1)
		run();
	else if (check == 2)
		run2();

	return 0;
} 
