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

## 左结合、右结合、不可结合分别是啥意思


