# imgview - 基于命令行的图像预览工具

使用 ASCII 字符将图片渲染到终端窗口中适合快速查看图片结构或内容轮廓。

## 🧱依赖
- C++11 或更高版本的编译器
- `stb_image.h`（已包含在本项目中）

> 仅依赖单头文件库 [`stb_image.h`](https://github.com/libigl/libigl-stb)，无需链接其他图形库或依赖项。

## 🛠️编译

```bash
clang++ imgview.cpp -o imgview
# 或者
g++ -std=c++11 imgview.cpp -o imgview
```

## 🚀 使用方法
```bash
./imgview path/to/image.jpg
```