关于对 lex 和 yacc 的使用，可以先阅读这篇博客：https://blog.csdn.net/wp1603710463/article/details/50365640

构建 

```
make build && cd build && cmake .. && make
```

测试

```
make test_all
```

## yacc 使用

- `%start` 指定符号的起始规则

## 一些 tips

```
ty -> type-id
   -> { tyfields }
   -> array of type-id
```

## 左结合、右结合、不可结合的区别

https://blog.csdn.net/sgzwiz/article/details/7426448

## LL 分析和 LR 分析的区别

LL 分析：从左至右分析、最左推导和超前查看 k 个符号
LR 分析：从左至右分析、最右推导、超前查看 k 个符号
