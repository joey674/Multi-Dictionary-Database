Unordered_Map/Singlton/shared_ptr/init_list

note：
无序图的查询是n（1）的 基础是哈希表 有序图的查询是o（logn）基础是二叉树 按顺序排列。所以设计中，涉及到无序数据的用无序图更快，有序数据在有需求的时候可以善用有序图。

键值查询中尽量避免使用遍历的函数 比如equal_range这样的函数，或者是for循环。比如说与其用equalrange，相对应的可以用upperbound和lowerbound设计指针迭代，从而提高效率

在编程时，只设计有用的结构体。不设计中间结构体，而是相对应的设计最直接的结构体。比如这里面从一个struct到另一个strust，就不要先设计一个map从a拿出来，在设计一个map放进b去。相对应的，直接设计一个嵌套map从a拿出后放进b中。这样需要合理设计，但也更加简洁。

多使用智能指针。unique表示只允许单个指针指向一块内存，share可以让多个指针指向同一个内存的同时进行内存自动管理。

结构体的初始化可以使用初始化列表。这样做的好处是在初始化时直接赋值。如果先初始化再赋值，其实是做了一个先赋默认值再修改的动作。在编程中要避免数据拷贝。除此之外，其他避免数据拷贝的操作有：善用指针。不传变量，而是相对应的传指向变量的指针。

单例模式的作用是只返回类的一个对象，禁止这个类出现多个对象。这样做的好处是可以在类中定义全局可访问变量，以及设置程序中只能唯一的对象。单例模式的代码还需要再研究下。




