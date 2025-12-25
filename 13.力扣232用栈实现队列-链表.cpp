/*
本题题目为《用栈实现队列》力扣题号为232
题目链接：https://leetcode.cn/problems/implement-queue-using-stacks/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// 定义链表节点结构体，规范typedef写法
typedef struct Node {
    int val;             // 变量名从x改为val，更语义化
    struct Node* next;   // 前向声明，避免编译器歧义
} Node;

class MyQueue {
private:
    int len;             // 成员变量私有化，符合封装原则
    Node* head;          // 哨兵头节点（原top，改名head更语义化）
    Node* tail;          // 尾节点（原end，改名tail更语义化）

public:
    // 构造函数：初始化哨兵节点和成员变量
    MyQueue() : len(0) {
        head = new Node();  // 哨兵节点，val无意义
        head->next = nullptr;
        tail = head;        // 初始时尾节点指向哨兵节点
    }

    // 析构函数：释放所有节点内存，避免内存泄漏
    ~MyQueue() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;  // C++中用delete释放new分配的内存
        }
    }

    // 入队：在尾节点后添加新节点
    void push(int x) {
        len++;
        Node* newNode = new Node();
        newNode->val = x;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;  // 更新尾节点
    }

    // 出队：移除队首节点并返回其值，队列为空时抛出异常
    int pop() {
        if (empty()) {
            throw std::underflow_error("Queue is empty, cannot pop.");
        }
        len--;
        Node* temp = head->next;  // 要删除的节点
        int data = temp->val;
        head->next = temp->next;  // 从链表中移除节点

        // 如果删除的是最后一个节点，更新尾节点
        if (tail == temp) {
            tail = head;
        }

        delete temp;  // 释放节点内存，避免内存泄漏
        return data;
    }

    // 查看队首元素：队列为空时抛出异常
    int peek() {
        if (empty()) {
            throw std::underflow_error("Queue is empty, cannot peek.");
        }
        return head->next->val;
    }

    // 判断队列是否为空：直接通过链表指针判断，更可靠
    bool empty() const {  // 成员函数加const，表明不修改对象状态
        return head->next == nullptr;
    }

    // 获取队列长度（可选接口，方便测试）
    int size() const {
        return len;
    }
};

/**
 * 测试示例：
 * MyQueue* obj = new MyQueue();
 * obj->push(1);
 * obj->push(2);
 * int param_2 = obj->pop();   // 返回1
 * int param_3 = obj->peek();  // 返回2
 * bool param_4 = obj->empty();// 返回false
 * delete obj;  // 调用析构函数，释放所有内存
 */
