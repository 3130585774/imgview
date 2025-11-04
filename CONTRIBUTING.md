# 贡献指南

感谢您对 imgview 项目的关注！我们欢迎所有形式的贡献。

## 如何贡献

### 报告 Bug

如果您发现了 bug，请通过 [GitHub Issues](https://github.com/3130585774/imgview/issues) 创建一个新的 issue，并包含以下信息：

- 详细的问题描述
- 复现步骤
- 期望的行为
- 实际的行为
- 您的操作系统和编译器版本

### 提交功能建议

如果您有新功能的想法，请先创建一个 issue 进行讨论。

### 提交代码

1. Fork 本仓库
2. 创建您的特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交您的更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启一个 Pull Request

## 代码规范

- 使用 C++11 标准
- 遵循现有代码的风格
- 确保代码能够通过编译（无警告）
- 添加适当的注释（如果需要）

## 构建和测试

```bash
# 编译项目
make

# 测试
./imgview screenshot.png

# 清理
make clean
```

## 提交信息规范

- 使用清晰、简洁的提交信息
- 使用现在时态（"Add feature" 而不是 "Added feature"）
- 第一行应该是简短的总结（不超过 50 字符）

## 许可证

通过贡献代码，您同意您的贡献将在 MIT 许可证下发布。
