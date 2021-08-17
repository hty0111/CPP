//
// Created by hty on 2021/8/12.
//

#ifndef C_PRIMER_PLUS_LIST_H
#define C_PRIMER_PLUS_LIST_H

typedef int Item;
typedef struct node{
    int number;     //节点位置
    Item item;      //节点内容
    struct node * next;
}Node;

class List {
private:
    enum {MaxNum = 20}; //最大成员数
    int currentNum;     //当前成员个数
    int currentIndex;   //当前指针的下标位置
    Node * head = new Node;        //头指针
public:
    List();     //创建空链表
    ~List();    //释放链表
    bool isEmpty();     //链表是否为空
    bool isFull();      //链表是否已满
    void insert(Item &, int n = MaxNum);//插入第n项的位置
    void delete_one(int n = MaxNum);    //删除第n项
//  void exchange(int n1, int n2);      //交换两项
    void show();
};


#endif //C_PRIMER_PLUS_LIST_H
