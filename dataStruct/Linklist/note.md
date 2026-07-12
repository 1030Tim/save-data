
# Linked List Note

## Linked List 核心思想

Linked List 是用「空間換時間」。

透過額外儲存 pointer（下一個 Node 的記憶體位置），
換取插入與刪除資料時，不需要大量搬移資料的效率。

代價：
- 增加記憶體使用量
- 無法像 Array 一樣快速透過 index 存取

----

## 核心觀念

Linked List（鏈結串列）不是將資料連續存放在記憶體中，而是：

> 將分散在不同記憶體位置的 Node，
> 利用 pointer（指標）串接起來。

每個 Node 包含兩個部分：

1. 自己儲存的資料 (`val`)
2. 下一個 Node 的記憶體位置 (`next`)

只需要保存：

- `head`：第一個 Node 的位置
- `end`：最後一個 Node 的位置（可選）
- 每個 Node 的 `next`

就可以走訪整個 Linked List。

---

# Node 結構

```c
struct Node
{
    int val;              // 儲存資料
    struct Node *next;    // 儲存下一個 Node 的記憶體位置
};
```

## 注意

`next` 不是存下一個值，而是存：

> 下一個 Node 的記憶體位址

例如：

```c
struct Node A;

A.val = 10;
A.next = &B;
```

代表：


A 的下一個 Node 在 B 的記憶體位置

---

# Linked List 結構

```txt
head
 |
 v
+-------+-------+
| val10 | next --------+
+-------+-------+      |
                       v
                 +-------+-------+
                 | val20 | next --------+
                 +-------+-------+      |
                                        v
                                  +-------+------+
                                  | val30 | NULL |
                                  +--------------+
                                         |
                                         v
                                        end
```

每個 Node 不需要在記憶體中連續排列。

例如：

```
記憶體位置：

0x1000        0x5000        0x8000

 Node10  --->  Node20  --->  Node30
```

pointer 負責連接它們。

---

# Linked List 優點

## 插入與刪除效率高

假設陣列：

```
{1,2,3,5,6}
```

要插入 `4`：

```
{1,2,3,4,5,6}
```

陣列需要：

```
5 往後移
6 往後移
```

時間複雜度：

```
O(N)
```

---

Linked List：

原本：

```
3 ---> 5
```

加入 4：

```
3 ---> 4 ---> 5
```

只需要修改 pointer：

```c
newNode->next = current->next;
current->next = newNode;
```

時間複雜度：

```
O(1)
```

---

# Linked List 缺點

## 1. 查找速度慢

陣列：

```c
arr[5]
```

可以直接透過 index 找到：

```
O(1)
```

原因：

> 陣列使用連續記憶體，可以直接計算位置。

---

Linked List：

如果要找第 5 個 Node：

```
head
 |
 v
Node1 -> Node2 -> Node3 -> Node4 -> Node5
```

必須從頭開始走：

```
O(N)
```

---

## 2. 額外記憶體消耗

陣列：

```
[value][value][value]
```

Linked List：

```
[value | pointer]
[value | pointer]
[value | pointer]
```

每個 Node 都需要額外儲存下一個 Node 的地址。

---



# 最重要觀念

> Array 靠「連續記憶體」快速存取。
> Linked List 靠「pointer 連接」快速修改結構。

Linked List 的核心不是資料本身，而是：

Node + Pointer = 動態資料結構


## 程式碼
```c
struct Node
{
    int val;
    struct Node *next;
};

int main(void)
{
    // 建立 頭跟尾
    struct Node *head = NULL;
    struct Node *end = NULL;

    int n;
    scanf("%d",&n);
    
    while (n--)
    {
        // 建立新的點
        struct Node *newNode = malloc(sizeof(struct Node));
        // 開立一個Node的空間
        scanf("%d", &newNode->val);
        // 下一個點為NULL
        newNode->next = NULL;
        // 代表還是獨立的點
        
        if (head == NULL)
        {// 更新頭跟尾
            head = newNode;
            end = newNode;
        }
        else
        {// 串串樂
            end->next = newNode;
            end = newNode;
        }
    }
}
```



