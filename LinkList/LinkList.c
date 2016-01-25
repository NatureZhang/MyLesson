//
//  main.c
//  LinkList
//
//  Created by 张东 on 15/12/30.
//  Copyright © 2015年 Nature. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

// 带有头结点的单链表
void linklist()
{
    struct node *head, *p, *q = NULL, *t;
    int i, n, a;
    scanf("%d", &n);
    
    // 创建一个头结点，内容存放数据个数
    head = (struct node *)malloc(sizeof(struct node));
    head->data = n;
    head->next = NULL;
    
    // 循环读入n个数
    q = head;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        
        // 动态申请一块空间，用来存放一个结点，并用临时指针p指向这个节点
        p = (struct node *)malloc(sizeof(struct node));
        
        p->data = a; //把a的值付给这个结点
        p->next = NULL; //设置后置结点
        q->next = p;
        q = p; // q指向当前结点
    }
    
    // 输出链表中的数
    t = head->next;
    while (t != NULL) {
        printf(" %d", t->data);
        t = t->next;
    }
    
    // 向链表中插入一个结点
    scanf("%d", &a);
    
    t = head;
    while (t != NULL)
    {
        if (t->next == NULL || t->next->data > a)
        {
            p = (struct node *)malloc(sizeof(struct node)); // 创建一个结点；
            p->data = a;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }
    
    t = head->next;
    while (t != NULL) {
        printf(" %d", t->data);
        t = t->next;
    }
    printf("\n");

}

// 模拟链表 用两个数组来模拟链表（一个数组存数据，一个数组存索引）
/*
 *   第一个数组data是用来存放序列中具体数字的，另一个整形数组right是用来存放当前序列中每一个元素右边的元素在数组data中位置的。
 */
void simulationLinkList()
{
    int data[101], right[101];//data用来存放数据 right用来存放当前序列中每一个元素右边的元素在data中的位置
    int i, n, t, len;
    
    // 读入已有的数
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &data[i]);
    }
    
    len = n;
    
    // 初始化数组right
    for (i = 1; i <= n; i++)
    {
        if (i != n)
        {
            right[i] = i + 1;
        }
        else
        {
            right[i] = 0;//表示结束
        }
    }
    
    len++; //在链表的末尾加入一个数
    scanf("%d", &data[len]);
    
    // 从链表的头部开始遍历
    t = 1;
    while (t != 0)
    {
        if (data[right[t]] > data[len]) // 如果当前结点的下一个结点大于新插入的结点
        {
            right[len] = right[t];
            right[t] = len;
            break;
        }
        
        t = right[t];
    }
    
    // 输出链表中所有的数
    t = 1;
    while (t != 0)
    {
        printf("%d ", data[t]);
        t = right[t];
    }
    
}

int main(int argc, const char * argv[]) {
    
//    linklist(); // 创建单链表
    simulationLinkList(); // 模拟单链表
    return 0;
}
