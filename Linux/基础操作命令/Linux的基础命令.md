#### 重启系统
    (1)立刻关机
      shutdown -h now 或者 poweroff
    (2)两分钟后关机
      shutdown -h 2
#### 关闭系统
    (1)立刻重启
      shutdown -r now 或者 reboot
    (2)两分钟后重启
      shutdown -r 2 
#### 帮助命令（help）
    ifconfig  --help     //查看 ifconfig 命令的用法
#### 命令说明书（man）
    man shutdown         //打开命令说明后，可按"q"键退出
#### 切换用户（su）
    su yao               //切换为用户"yao",输入后回车需要输入该用户的密码
    exit                 //退出当前用户
## 目录的相关操作
    .         代表此层目录
    ..        代表上一层目录
    -         代表前一个工作目录
    ~         代表“目前使用者身份”所在的主文件夹
    ~account  代表 account 这个使用者的主文件夹（account是个帐号名称）
    
几个常见的处理目录的指令：

    cd：变换目录
    pwd：显示目前的目录
    mkdir：创建一个新的目录
    rmdir：删除一个空的目录
    cd （change directory, 变换目录）
    
我们知道dmtsai这个使用者的主文件夹是/home/dmtsai/，而root主文件夹则是/root/，假设我以root身份在 Linux系统中，那么简单的说明一下这几个特殊的目录的意义是：

    [dmtsai@study ~]$ su -  # 先切换身份成为 root 看看！
    [root@study ~]# cd [相对路径或绝对路径]
    # 最重要的就是目录的绝对路径与相对路径，还有一些特殊目录的符号啰！
    [root@study ~]# cd ~dmtsai
    # 代表去到 dmtsai 这个使用者的主文件夹，亦即 /home/dmtsai
    [root@study dmtsai]# cd ~
    # 表示回到自己的主文件夹，亦即是 /root 这个目录
    [root@study ~]# cd
    # 没有加上任何路径，也还是代表回到自己主文件夹的意思喔！
    [root@study ~]# cd ..
    # 表示去到目前的上层目录，亦即是 /root 的上层目录的意思；
    [root@study /]# cd -
    # 表示回到刚刚的那个目录，也就是 /root 啰～
    [root@study ~]# cd /var/spool/mail
    # 这个就是绝对路径的写法！直接指定要去的完整路径名称！
    [root@study mail]# cd ../postfix
    # 这个是相对路径的写法，我们由/var/spool/mail 去到/var/spool/postfix 就这样写！
