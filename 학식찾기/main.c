#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define INF 100000
#define NUMBERR 13
#define NUMBER 24
int choose1;
int choose2;
int menu;

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
	int loc, i, j, kk, date;
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
	system("CLS");
	dijkstraa(loc);

	for (i = 0; i < 3; i++)
	{
		emp[i].location = i;
		emp[i].value = dd[i + 10];
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
	{
		strcpy(ch, name[0]);
		menu = 1;
	}
	else if (emp[0].location == 1)
	{
		strcpy(ch, name[1]);
		menu = 2;
	}
	else if (emp[0].location == 2)
	{
		strcpy(ch, name[2]);
		menu = 3;
	}

	printf("가장 가까운 식당은 %s입니다.\n", ch);
	printf("거리는 %dm입니다.\n", emp[0].value * 100);
	printf("도보로 %.2lf분 소요됩니다..\n", (double)emp[0].value * 10 / 6.6);
	printf("\n식단표를 출력하시겠습니까?(출력은 1을 입력, 출력하지 않을시 0을 입력하세요.\n");
	scanf("%d", &kk);
	if (kk == 1)
	{
		printf("\n12월 12~16일중 어떤 날짜를 선택하시겠습니까?");
		printf("\n날짜를 입력해주세요.");
		scanf("%d", &date);
		if (menu == 1)
		{
			if (date == 12)
			{
				printf("12월 12일 월요일 정보센터식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("불닭크림리조또           5,500원\n");
				printf("토마토제육치즈덮밥       5,000원\n");
				printf("쭈꾸미비빔밥             4,000원\n");
				printf("통등심돈가스             4,000원\n");
				printf("라면                     2,800원\n");
				printf("================================\n");
			}
			else if (date == 13)
			{
				printf("12월 13일 화요일 정보센터식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("동인동찜갈비             5,500원\n");
				printf("참치마요                 5,500원\n");
				printf("홍합수제비짬뽕           5,000원\n");
				printf("불고기비빔밥             4,000원\n");
				printf("통등심치즈돈가스         4.500원\n");
				printf("================================\n");
			}

			else if (date == 14)
			{
				printf("12월 14일 수요일 정보센터식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("불고기쌀국수             5,500원\n");
				printf("햄야채볶음밥             5,500원\n");
				printf("고추장불고기덮밥         5,000원\n");
				printf("닭불고기비빔밥           4,000원\n");
				printf("고구마치즈돈가스         4,500원\n");
				printf("================================\n");
			}

			else if (date == 15)
			{
				printf("12월 15일 목요일 정보센터식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("목살에그스테이크         5,500원\n");
				printf("메추리알품은찜닭         5,500원\n");
				printf("비빔만두                 5,500원\n");
				printf("오삼비빔밥               4,000원\n");
				printf("왕돈가스                 5,500원\n");
				printf("================================\n");
			}

			else if (date == 16)
			{
				printf("12월 16일 금요일 정보센터식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("제육치즈돌솥             5,000원\n");
				printf("봉골레파스타             5,000원\n");
				printf("참치비빔밥               4,000원\n");
				printf("치즈왕돈가스             5,500원\n");
				printf("어묵우동밥               3,800원\n");
				printf("================================\n");
			}
		}

		else if (menu == 2)
		{
			if (date == 12)
			{
				printf("12월 12일 월요일 복지관 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("육회비빔밥               5,500원\n");
				printf("등심돈가스               5,000원\n");
				printf("참치덮밥                 5,000원\n");
				printf("돼지고기김치볶음밥       5,000원\n");
				printf("프리미엄삼겹돼지국밥     6,000원\n");
				printf("================================\n");
			}

			else if (date == 13)
			{
				printf("12월 13일 화요일 복지관 식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("파스타                   5,500원\n");
				printf("고르곤졸라피자           5,500원\n");
				printf("청양풍삼겹살덮밥         4,000원\n");
				printf("참치비빔밥               4,000원\n");
				printf("치즈돈가스               4,500원\n");
				printf("================================\n");
			}

			else if (date == 14)
			{
				printf("12월 14일 수요일 복지관 식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("불고기필라프             5,000원\n");
				printf("허니브레드               5,000원\n");
				printf("카레닭볶음덮밥           4,000원\n");
				printf("고구마돈가스             4,500원\n");
				printf("================================\n");
			}

			else if (date == 15)
			{
				printf("12월 15일 목요일 복지관 식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("참치마요김치볶음밥       5,500원\n");
				printf("콘새우브레드             5,500원\n");
				printf("오므라이스               4,000원\n");
				printf("복돈이                   5,500원\n");
				printf("치즈복돈이               5,500원\n");
				printf("================================\n");
			}

			else if (date == 16)
			{
				printf("12월 16일 금요일 복지관 식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("갈릭목살필라프           5,500원\n");
				printf("만두그라탕               5,500원\n");
				printf("마라샹궈덮밥             4,500원\n");
				printf("통등심돈가스             4,000원\n");
				printf("라면                     2,800원\n");
				printf("================================\n");
			}
		}
		else if (menu == 3)
		{

			if (date == 12)
			{
				printf("12월 12일 월요일 공식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("육회비빔밥               5,500원\n");
				printf("등심돈가스               5,000원\n");
				printf("참치덮밥                 5,000원\n");
				printf("돼지고기김치볶음밥       5,000원\n");
				printf("프리미엄삼겹돼지국밥     6,000원\n");
				printf("================================\n");
			}


			else if (date == 13)
			{
				printf("12월 13일 화요일 공식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("쟁반수육                 5,500원\n");
				printf("땡초우동                 5,000원\n");
				printf("돈가스마요               5,000원\n");
				printf("훈제오리덮밥             5,500원\n");
				printf("특돼지국밥               5,000원\n");
				printf("================================\n");
			}

			else if (date == 14)
			{
				printf("12월 14일 수요일 공식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("치킨마요                 5,000원\n");
				printf("마제덮밥                 5,000원\n");
				printf("된장찌개정식             4,500원\n");
				printf("떡라면                   3,000원\n");
				printf("만두라면                 3,500원\n");
				printf("================================\n");
			}

			else if (date == 15)
			{
				printf("12월 15일 목요일 공식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("오므라이스               4,500원\n");
				printf("소고기국밥               4,500원\n");
				printf("바지락순두부찌개정식     5,000원\n");
				printf("최루탄라면               3,500원\n");
				printf("삼겹살김치전골(2인)     11,000원\n");
				printf("================================\n");
			}

			else if (date == 16)
			{
				printf("12월 16일 금요일 공식당 메뉴판입니다 \n");
				printf("\n");
				printf("\n메뉴 \n");
				printf("================================\n");
				printf("불돈쏘야덮밥             5,000원\n");
				printf("양푼이돈육양념찜         5,500원\n");
				printf("꼬마부대찌개             5,000원\n");
				printf("뚝배기알밥               4,500원\n");
				printf("양푼이비빔밥             5,000원\n");
				printf("================================\n");
			}
		}
	}
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
	system("CLS");
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

struct login
{
	char firstname[100];
	char lastname[20];
	char id[20];
	char password[20];
};

registration()
{
	char id[20];
	FILE* log;
	log = fopen("login12.txt", "at");
	struct login L;

	while (1)
	{
		printf("성을 입력해 주세요: ");
		scanf("%s", L.firstname);
		if (!strcmp(L.firstname, "X"))
		{
			break;
		}
		printf("이름을 입력해 주세요: ");
		scanf("%s", L.lastname);
		printf("아이디를 입력해 주세요: ");
		scanf("%s", L.id);
		printf("비밀번호를 입력해 주세요: ");
		scanf("%s", L.password);
		fprintf(log, "%s %s %s %s\n", L.firstname, L.lastname, L.id, L.password);
		printf("계정이 생성되었습니다. 바로 로그인 하시려면 다음 화면에서 'X'를 눌러 주세요.\n");
	}

	fclose(log);
}

int login()
{
	char id[20], password[20];
	FILE* log;
	log = fopen("login12.txt", "r");
	struct login L;
	int i, k;

	printf("ID: ");
	scanf("%s", id);
	printf("Password: ");
	scanf("%s", password);

	k = 0;
	while (fscanf(log, "%*s%*s%s%s", L.id, L.password) != EOF)
	{
		if (strcmp(L.id, id) == 0 && strcmp(L.password, password) == 0)
		{
			k = 1;
			break;
		}
	}
	fclose(log);

	if (k == 1)
	{
		printf("접속이 완료되었습니다.\n");
		system("CLS");
		return;
	}
	else
	{
		printf("로그인에 실패했습니다. 다시 시도하려면 1, 종료하시려면 2를 눌러 주세요\n");
	}

	scanf("%d", &choose1);
	if (choose1 == 1) {
		printf("ID:\n");
		scanf("%s", &id);

		printf("Password:\n");
		scanf("%s", &password);

		if (strcmp(L.id, id) == 0 && strcmp(L.password, password) == 0)
		{
			printf("접속이 완료되었습니다.");
			return;
		}


		else {
			printf("로그인에 실패했습니다. 다시 시도하려면 1, 종료하시려면 2를 눌러 주세요\n");
			scanf("%d", &choose2);
			if (choose2 == 1) {
				printf("ID:\n");
				scanf("%s", &id);
				printf("Password:\n");
				scanf("%s", &password);
				if (strcmp(L.id, id) == 0 && strcmp(L.password, password) == 0) {
					printf("로그인에 성공했습니다.");
				}
				else
					printf("횟수 초과로 접근이 거부되었습니다. 프로그램을 종료하겠습니다.");
			}

			else
				printf("프로그램이 종료되었습니다.");
		}




	}



	return k;

}

void main()
{
	int choose;

	printf("회원가입은 '1', 로그인은 '2'를 입력해 주세요\n");
	scanf("%d", &choose);
	if (choose == 1)
	{
		system("CLS");
		registration();
	}

	printf("ID와 Password를 입력해 주세요.");
	getch();
	system("cls");
	login();

	int check;
	printf("학생식당을 찾고싶으면 1을 입력\n");
	printf("편의점을 찾고싶으면 2을 입력하세요.\n");
	scanf_s("%d", &check);
	system("CLS");
	if (check == 1)
		run();
	else if (check == 2)
		run2();

	return 0;
}
