单文件虚拟文件系统设计
=====================


这个项目的来源是咱在备份硬盘时发现的一个尴尬, 机械硬盘的4k读写能力实在太差, 备份项目时, 往往项目中包含大量的零碎小文件, 造成备份时间极其缓慢.

于是想到能不能做一个单文件的文件系统, 然后将这个文件"挂载"上, 就能够方便的读写和操作其中的内容, 甚至可以在里面make项目, 执行测试等, 需要备份时, 整个文件又可以直接拷走, 方便的移动位置.

于是就有了这个项目, 单文件系统除此以外, 还能怎么玩?

## 用法

### 游戏资源打包

用在游戏资源管理上, 由于有索引系统, 比一般的压缩打包速度更快, 可以做到随用随加载, 而不必占用大量内存将资源全部解包, 这样对于大型游戏(50G以上), 大大提高加载速度, 又能让游戏资源成为一个整体, 不显凌乱, 减小破解的风险. 并且可以把加密做到文件系统层次, 方便游戏开发.

### 程序部署

另外一个方便的用法就是快速部署, 将文件系统中内置meta数据, 在加载时允许执行特定动作或脚本. 这样可以让程序部署时非常方便, 直接挂载到固定的目录上, 而程序体本身可以在任意位置, 在磁盘空间不足时, 可以方便的移动, 而不需要手动配置.

90%的程序异常都是由于不正确的版本造成的。

这样对于一些应用来说非常方便, 我们在使用一些程序库时，make后的部分往往要复制到系统目录中，这有时会和系统包安装的程序冲突，如果我们使用文件系统的特性将make后的目录安装到项目目录中，之后将需要的目录挂载到系统目录中，不用时我们将其卸载掉，这样往往能够方便的处理版本问题，我们一些程序的目录不正确时，我们可以将文件系统挂载到对应的目录中。或者将不合适的版本卸载掉，这样更加容易修复问题。

整体卸载和清理log和缓存文件更加方便。

### 网站部署方案

已经使用虚拟机技术的部署方案的可以无视这部分了。

虚拟文件系统另外的使用方法则是适用于网站的整体部署，不同与docker和kvm的虚拟机方式，虚拟文件系统仅仅能解决文件系统方面的部分问题，不能够处理网站的端口和资源虚拟化问题。

不过虚拟文件系统有些类似于虚拟机文件系统的底层接口，相当于是网站系统的文件管理部分，我们可以用一个文件打包所有开发时数据，整体部署到网站上，也可以在服务器上挂载修改，这相比war包等打包方式，更为灵活一点，而且文件系统支持可写，如果要备份运行数据和log时，可以直接备份。



## 设计

下面我们将介绍单文件虚拟文件系统的设计方案。

### 依赖简介

libfuse是一款将文件系统转换到用户空间的库，对于开发独立的文件系统非常方便。


### 方案

使用单文件管理文件系统，使用仿ext2的文件管理结构，兼顾效率与空间使用效率，更多的使用内存缓存，减少磁盘读写，是针对个人系统及服务器设计的，对于需要轻量级的嵌入式文件系统，可以参考lwext4项目.

### 文件系统结构

整体：
| 文件头 | 根目录表 | 数据存储块 0 ~ n-1 |

一个存储块：
| super block | 块元信息 | bitmap | 目录表项 | 数据块 |
