[TOC]

## 运行准备说明

1. 本用例使用gtest作为单元测试框架，并且已包含在本项目源代码中，不必下载，版本为`googletest-release-1.8.x`。
2. 本机有C++编译环境
3. 可以运行make命令

## 如何编译

```
 rm -rf build&&mkdir build&&cd build&&cmake ../&&make
```

## 如何运行

### 运行程序文件

在项目根目录执行下面命令

`./build/main`

### 运行单元测试

在项目根目录执行下面命令

`./build/test/unittest`
