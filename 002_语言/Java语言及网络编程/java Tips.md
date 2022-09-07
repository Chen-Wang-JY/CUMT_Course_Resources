> 计算机科学与技术2019-3 王杰永

# Java零碎的知识点

## 1. 取模运算

- 浮点数允许
- 结果绝对值大小取决于被取模数与取模数的绝对值
- 结果符号与被取模数相同，取模数符号不影响结果。

> tips_1

## 2. 0做除数与取模数

- int a = 10 / 0;

- int a = 10 % 0;

  > 均通过编译，但是运行时抛出ArithmeticException-算数异常

---

 ```java
 double a = 10.0 / 0;
 double b = -10.0 / 0;
 
 boolean x = Double.isInfinite(-10.0/0);
 ```

- 不会抛出异常，sout的结果分别是Infinity 与 -Infinity 与 true

---
```Java
double a = 10.0 % 0;
double b = -10.0 % 0;
boolean x = Double.isNaN(-10.0%0);
```

- 不会抛出异常，sout的结果分别是NaN与 NaN与 true

## 3.自动类型转换

```java
byte a = 1;
byte b = 1;
byte c = (a + b);
```
- 编译出错，原因byte类型运算时自动转为int

- 在运算过程中，运算的结果至少是int型，即如果参与运算的两个数级别比int型低或是int型，则结果为int。

```java
byte b=123;//合法
short s=123;//合法
b=b+3; //不合法
```

- Java中允许把int类型的常量赋给byte、short变量时不需要强制类型转换

---

```java
class test {
    public static void main(String[] args) {
        float x = 3.3f;
        double y = 2.9;
        var ans1 = x + (int)y / 3 * 3.3;
        var ans2 = x + (int)y / 3 * 3.3f;
        System.out.println(getType(ans1));
        System.out.println(ans1);
        System.out.println(getType(ans2));
        System.out.println(ans2);
    }

    private static String getType(Object a) {
        return a.getClass().toString();
    }
}
/*
class java.lang.Double
3.299999952316284
class java.lang.Float
3.3
*/
```

## 4.访问权限

- 首先是类内的访问权限
  - private：只有本类可以访问，子类、同包均不能访问
  - friendly：同包可以访问，哪怕没有子类关系
  - protected：同包可以访问（无论有无子类关系），不同包的子类关系也可以访问
  - public：怎样都可以。
- 类外通过对象的访问权限
  - private：不可以访问
  - friendly：不同包不可以访问，同包可以访问
  - protected：不同包不可以访问，同包可以访问
  - public：可以访问
- 特例***(似乎也不算特例)***
  - 不同包具有继承关系的子类，在某一个方法（无论是否static）中，创建本类（子类）对象，该对象竟然可以访问到protected

## 5. static final

- 类常量——static final，需要在定义时赋值，不能在**构造方法**中赋值（和下面对比很好理解）
- 对象常量——final，可以在构造方法中赋值（因为非static，每个对象均有一份，故可以在构造方法中赋值）

## 6. 方法重载除了在一个类中可以体现，在父类与子类中也可以方法重载；如果方法完全一样，那就是方法/属性的隐藏

## 7. 如何确保一个类之创建一个对象？

- 这也太神奇了

```java
class T
{
       static T tObj=new T();
       private T()
       {   	
       }
       public static T getinstance()
       {
   	       return tObj;
       }
}
```

## 8. 子类使用super调用父类构造方法，必须放在子类构造方法第一句。

## 9.方法可以多态，但是属性不可以

> tips_3

## 10.构造方法调用顺序

- 按顺序执行静态代码/代码块

- 父类的构造

- 本类的构造

## 11. 接口的默认修饰符

- 成员变量：public static final
- 方法：public abstract
  
  > 接口中的方法不能使用static、synchronized修饰符

## 12.内部类

- 要在除外部类的其他类内创建内部内，需要保证该类具有访问内部类的权限，并且已经创建了一个外部类对象

```java
Outer outer = new Outer();
Outer.Inner inner = outer.new Inner();
```

- 静态内部类的创建不需要外部类对象

```java
Outer.Inner inner = new Outer.Inner();
```

## 13. Object.hashCode()方法

- Java将数据存储在不同的区域中，区别这些区域的标识就是散列码。

- Object的hashCode()返回了该对象的散列码，默认情况下是对象的存储区域的地址。即Object类的hashCode()返回对象地址，用地址作为散列码，故任意两个对象的hashCode均不相同。

  > 故可以有多个对象的hashCode相同。

- 字符串的散列码是由内容导出的，故内容相同则hashCode一定相同。

- 当我们需要重写hashCode()与equals()方法时，需要保证一些特点：
  - 如果两个对象equals()结果为true，则两对象hashCode一定相同。
  - 如果两个对象的hashCode()结果相同，并不能代表两个对象的equals()一定为true，只能说明两个对象在一个散列存储结构中。
  - 如果equals()被重写，那么hashCode()一定也要被重写。

## StringPool

- Java在**编译**时，将相同的串合并，因此在运行过程中产生的相同的串变量地址不同。

```java
String a = "hellojava";
String b = "java";
String c = "hello" + b;
String d = "hellojava";
if (a == c) {
	System.out.println("相等");
} else {
    System.out.println("不等");
}
if(a == d){
    System.out.println("相等");
} else{
    System.out.println("不等");
}
```

> 运行程序，输出结果如下：
>
> 不等
>
> 相等

## 异常

- 在try块中产设了异常，如果当前方法使用catch捕获异常，则先执行catch块，再执行finally块
- 如果当前方法没有捕获异常，则会先执行finally（如果有的话），再抛出异常。
