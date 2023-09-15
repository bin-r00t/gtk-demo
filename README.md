# 使用指南

## intro
```bash
 gcc `pkg-config --cflags gtk+-3.0` -o output/out main.c `pkg-config --libs gtk+-3.0`
```

## steps
1. 安装编译环境和对应的工具 build-essential or "Development Tools"

2. 按照对应的开发包：gtk+3.0 glib-2.0 gdk-xxx pixbuf 之类的，详见官网（或自行编译）

3. 将 .vscode 复制到vscode当前打开项目的平行目录中，根据具体环境调整 includePath, 以便获得
代码提示和vscode不报错

4. 编写对应代码，注意gtk4和gtk3的API有些不同，可能需要频繁google或者
仔细阅读对应文档/tutorials，比如gtk4中使用
gtk_window_set_child(GTK_WINDOW(window), button);将button添加到window，
而gtk3可能就要改用gtk_container_add来替代

5. 编译，使用 pkg-config 自动查找库目录和头文件等。
pkg-config 还可以用于辅助配置上面的那个vscode json文件


## Issues
1. 当编译使用了 builder.ui 的程序后，执行时，必须在含 builder.ui 文件的目录下（以此为工作目录），
否则会提示找不到 builder.ui 文件，所以有可能该文件是动态加载的，而不是编译时加载

## tips
Glade 工具可以用拖拽的方式创建组件。最好是将组件的描述文件单独放置，如放在 /usr/common/appname 下，
当然也可以写死在程序里（用字符串 + gtk_builder_add_from_string()），不过这样想要更新的话就需要重新编译了。

