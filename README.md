# Unordered_Map
Unordered_Map/Singlton/shared_ptr/init_list

无序图的查询是n（1）的 基础是哈希表 有序图的查询是o（logn）基础是二叉树 按顺序排列

键值查询中尽量避免使用遍历的函数 比如equal_range这样的函数，或者是for循环。比如说与其用equalrange，相对应的可以用upperbound和lowerbound设计指针迭代，从而提高效率

在编程时，只设计有用的结构体。不设计中间结构体，而是相对应的设计最直接的结构体
