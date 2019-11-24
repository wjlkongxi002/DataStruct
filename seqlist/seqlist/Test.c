#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"
//#include<vld.h>

int main()
{
	SeqList mylist;//mylist是定义了的一个结构体类型变量 构造一个顺序表
	SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);
	int pos;//定义位置
	int select = 1;
	DataType item, key;//item是定义的要输入的数据key是按值查找的值
	DataType ret;//返回值
	bool flag;
	while (select)
	{
		printf("*****************************************\n");
		printf("* [1] push_back         [2] push_front  *\n");
		printf("* [3] show_list         [0] quit_system *\n");
		printf("* [4] pop_back          [5] pop_front   *\n");
		printf("* [6] insert_pos        [7] insert_val  *\n");
		printf("* [8] delete_pos        [9] delete_val  *\n");
		printf("* [10] find_pos         [11] find_val   *\n");
		printf("* [12] sort             [13] reverse    *\n");
		printf("* [14] length           [15] clear      *\n");
		printf("* [16] modify_pos       [17] modify_val *\n");
		printf("* [18] capacity                         *\n");
		printf("*****************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &key);
			SeqListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			flag = SeqListFindByPos(&mylist, pos, &ret);
			if (flag)
				printf("查找的数据为:> %d\n", ret);
			else
				printf("查找的数据不存在.\n");
			break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFindByVal(&mylist, key);
			if (pos == -1)
				printf("查找的数据不存在.\n");
			else
				printf("数据所在的下标为:> %d\n", pos);
			break;
		case 12:
			SeqListSort(&mylist);
			break;
		case 13:
			SeqListReverse(&mylist);
			break;
		case 14:
			printf("SeqList Length = %d\n", SeqListLength(&mylist));
			break;
		case 15:
			SeqListClear(&mylist);
			break;
		case 16:
			SeqListModifyByPos(&mylist, pos, item);
			break;
		case 17:
			SeqListModifyByVal(&mylist, key, item);
			break;
		case 18:
			printf("capacity = %d\n", SeqListCapacity(&mylist));
			break;
		default:
			printf("输入错误，请重新输入......\n");
			break;
		}
		//system("pause");//暂停
		//system("cls");//清屏
	}
	SeqListDestroy(&mylist);
	return 0;
}

