# Linklist Note

核心觀念linklist是將單獨的記憶體空間利用指標連起來
只需要head跟end

```c
struct Node
{
    int val; -> 裡面除存的值
    struct Node *next; -> =這是一個Node的指標叫做*next
};
```



```txt
head
 |
 v
+-----+-------+
| 10  val |*--|----> *next 存放下個值的指標
+-----+-------+
              |
              v
        +-----+-----+
        | 20  | *-- |
        +-----+-----+
                      |
                      v
                +-----+------+
                | 30  | NULL | ---> end
                +------------+
```