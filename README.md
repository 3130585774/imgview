# imgview - 基于命令行的图像预览工具

[![CI](https://github.com/3130585774/imgview/actions/workflows/ci.yml/badge.svg)](https://github.com/3130585774/imgview/actions/workflows/ci.yml)
[![Release](https://github.com/3130585774/imgview/actions/workflows/release.yml/badge.svg)](https://github.com/3130585774/imgview/actions/workflows/release.yml)

使用 ASCII 字符将图片渲染到终端窗口中，适合快速查看图片结构或内容轮廓。

## ✨ 特性

- 🖼️ 支持多种图片格式（JPEG, PNG, BMP, GIF 等）
- 📏 自动适配终端窗口大小
- 🎨 使用 ASCII 字符渐变显示图像
- ⚡ 轻量级，无需额外依赖
- 🔧 简单易用的命令行界面

## 🧱 依赖

- C++11 或更高版本的编译器（g++, clang++）
- `stb_image.h`（已包含在本项目中）

> 仅依赖单头文件库 [`stb_image.h`](https://github.com/nothings/stb)，无需链接其他图形库或依赖项。

## 📦 安装

### 从源码编译

```bash
# 克隆仓库
git clone https://github.com/3130585774/imgview.git
cd imgview

# 使用 Makefile 编译
make

# 可选：安装到系统路径
sudo make install
```

### 手动编译

```bash
# 使用 g++
g++ -std=c++11 -Wall -Wextra -O2 imgview.cpp -o imgview

# 或使用 clang++
clang++ -std=c++11 -Wall -Wextra -O2 imgview.cpp -o imgview
```

### 下载预编译版本

访问 [Releases](https://github.com/3130585774/imgview/releases) 页面下载适合你系统的预编译二进制文件。

## 🚀 使用方法

基本用法：

```bash
./imgview path/to/image.jpg
```

示例：

```bash
# 查看 PNG 图片
./imgview screenshot.png

# 查看 JPEG 图片
./imgview photo.jpg

# 查看 BMP 图片
./imgview image.bmp
```

## 🛠️ 开发

### 清理构建文件

```bash
make clean
```

### 支持的图片格式

imgview 使用 stb_image 库，支持以下格式：
- JPEG
- PNG
- BMP
- GIF
- PSD
- TGA
- HDR
- PIC
- PNM

## 📄 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件

## 🤝 贡献

欢迎贡献！请随时提交 Issue 或 Pull Request。

## 📸 截图

![示例](screenshot.png)