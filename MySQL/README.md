## MySQL数据库的完美卸载！
   第一步：双击安装包进行卸载删除。
   
   第二步：删除目录：
   
   把C:\ProgramData下面的MySQL目录干掉。
   
   把C:\Program Files (x86)下面的MySQL目录干掉。
	
   这样就卸载结束了！
## mysql安装了，服务启动了，怎么使用客户端登录mysql数据库呢？
  本地登录（显示编写密码的形式）：
  
  C:\Users\Administrator>mysql -uroot -p123456
  
  本地登录（隐藏密码的形式）：
  
  C:\Users\Administrator>mysql -uroot -p
		
  Enter password: ******
## mysql常用命令：
  退出mysql ：exit

  查看mysql中有哪些数据库？
  
  show databases; 
  
  mysql> show databases;
  
  +--------------------+
	
  | Database           |
	
  +--------------------+
  
  | information_schema |
	
  | mysql              |
	
  | performance_schema |
	
  | test               |
	
  +--------------------+
  
  mysql默认自带了4个数据库。
 
## 怎么选择使用某个数据库呢？
  mysql> use test;
  
  Database changed
  
  表示正在使用一个名字叫做test的数据库。
	
## 怎么创建数据库呢？
  mysql> create database bjpowernode;
  
  Query OK, 1 row affected (0.00 sec)

  mysql> show databases;
  
  +--------------------+
  
  | Database           |
  
  +--------------------+
  
  | information_schema |
  
  | bjpowernode        |
  
  | mysql              |
  
  | performance_schema |
  
  | test               |
  
  +--------------------+ 
  
  
  
## 数据库当中最基本的单元是表：table

    什么是表table？为什么用表来存储数据呢？

		姓名	性别	年龄(列：字段) 
		-------------------------------------------------------------------
		张三	男			20            ------->行（记录）
		李四	女			21            ------->行（记录）
		王五	男			22            ------->行（记录）
	
	数据库当中是以表格的形式表示数据的。
	因为表比较直观。

	任何一张表都有行和列：
		行（row）：被称为数据/记录。
		列（column）：被称为字段。
	
	姓名字段、性别字段、年龄字段。

	了解一下：
		每一个字段都有：字段名、数据类型、约束等属性。
		字段名可以理解，是一个普通的名字，见名知意就行。
		数据类型：字符串，数字，日期等，后期讲。

		约束：约束也有很多，其中一个叫做唯一性约束，
			这种约束添加之后，该字段中的数据不能重复。
  
## 关于SQL语句的分类？

    SQL语句有很多，最好进行分门别类，这样更容易记忆。
    
	分为：
			DQL：
			
				数据查询语言（凡是带有select关键字的都是查询语句）
				
				select...
				
				
			DML：
			
				数据操作语言（凡是对表当中的数据进行增删改的都是DML）
				
				insert delete update
				
				insert 增
				
				delete 删
				
				update 改

				这个主要是操作表中的数据data。

			DDL：
			
				数据定义语言
				
				凡是带有create、drop、alter的都是DDL。
				
				DDL主要操作的是表的结构。不是表中的数据。
				
				create：新建，等同于增
				
				drop：删除
				
				alter：修改
				
				这个增删改和DML不同，这个主要是对表结构进行操作。
				

			TCL：
			
				不是王牌电视。
				
				是事务控制语言
				
				包括：
				
					事务提交：commit;
					
					事务回滚：rollback;
					

			DCL：
			
				是数据控制语言。
				
				例如：授权grant、撤销权限revoke....
				
## 导入一下提前准备好的数据：

  bjpowernode.sql 这个文件中是我提前为大家练习准备的数据库表。
  
  怎么将sql文件中的数据导入呢？
  
  mysql> source D:\course\03-MySQL\document\bjpowernode.sql

  注意：路径中不要有中文！！！！
  
## 关于导入的这几张表？
	mysql> show tables;
	+-----------------------+
	| Tables_in_bjpowernode |
	+-----------------------+
	| dept                  |
	| emp                   |
	| salgrade              |
	+-----------------------+

	dept是部门表
	emp是员工表
	salgrade 是工资等级表

	怎么查看表中的数据呢？
		select * from 表名; //统一执行这个SQL语句。

	mysql> select * from emp; // 从emp表查询所有数据。
	+-------+--------+-----------+------+------------+---------+---------+--------+
	| EMPNO | ENAME  | JOB       | MGR  | HIREDATE   | SAL     | COMM    | DEPTNO |
	+-------+--------+-----------+------+------------+---------+---------+--------+
	|  7369 | SMITH  | CLERK     | 7902 | 1980-12-17 |  800.00 |    NULL |     20 |
	|  7499 | ALLEN  | SALESMAN  | 7698 | 1981-02-20 | 1600.00 |  300.00 |     30 |
	|  7521 | WARD   | SALESMAN  | 7698 | 1981-02-22 | 1250.00 |  500.00 |     30 |
	|  7566 | JONES  | MANAGER   | 7839 | 1981-04-02 | 2975.00 |    NULL |     20 |
	|  7654 | MARTIN | SALESMAN  | 7698 | 1981-09-28 | 1250.00 | 1400.00 |     30 |
	|  7698 | BLAKE  | MANAGER   | 7839 | 1981-05-01 | 2850.00 |    NULL |     30 |
	|  7782 | CLARK  | MANAGER   | 7839 | 1981-06-09 | 2450.00 |    NULL |     10 |
	|  7788 | SCOTT  | ANALYST   | 7566 | 1987-04-19 | 3000.00 |    NULL |     20 |
	|  7839 | KING   | PRESIDENT | NULL | 1981-11-17 | 5000.00 |    NULL |     10 |
	|  7844 | TURNER | SALESMAN  | 7698 | 1981-09-08 | 1500.00 |    0.00 |     30 |
	|  7876 | ADAMS  | CLERK     | 7788 | 1987-05-23 | 1100.00 |    NULL |     20 |
	|  7900 | JAMES  | CLERK     | 7698 | 1981-12-03 |  950.00 |    NULL |     30 |
	|  7902 | FORD   | ANALYST   | 7566 | 1981-12-03 | 3000.00 |    NULL |     20 |
	|  7934 | MILLER | CLERK     | 7782 | 1982-01-23 | 1300.00 |    NULL |     10 |
	+-------+--------+-----------+------+------------+---------+---------+--------+

	mysql> select * from dept;
	+--------+------------+----------+
	| DEPTNO | DNAME      | LOC      |
	+--------+------------+----------+
	|     10 | ACCOUNTING | NEW YORK |
	|     20 | RESEARCH   | DALLAS   |
	|     30 | SALES      | CHICAGO  |
	|     40 | OPERATIONS | BOSTON   |
	+--------+------------+----------+

	mysql> select * from salgrade;
	+-------+-------+-------+
	| GRADE | LOSAL | HISAL |
	+-------+-------+-------+
	|     1 |   700 |  1200 |
	|     2 |  1201 |  1400 |
	|     3 |  1401 |  2000 |
	|     4 |  2001 |  3000 |
	|     5 |  3001 |  9999 |
	+-------+-------+-------+

## 不看表中的数据，只看表的结构，有一个命令：

    desc 表名;
    mysql> desc dept;
    +--------+-------------+------+-----+---------+-------+
    | Field  | Type        | Null | Key | Default | Extra |
    +--------+-------------+------+-----+---------+-------+
    | DEPTNO | int(2)      | NO   | PRI | NULL    |       |部门编号
    | DNAME  | varchar(14) | YES  |     | NULL    |       |部门名字
    | LOC    | varchar(13) | YES  |     | NULL    |       |地理位置
    +--------+-------------+------+-----+---------+-------+
    mysql> desc emp;
    +----------+-------------+------+-----+---------+-------+
    | Field    | Type        | Null | Key | Default | Extra |
    +----------+-------------+------+-----+---------+-------+
    | EMPNO    | int(4)      | NO   | PRI | NULL    |       |员工编号
    | ENAME    | varchar(10) | YES  |     | NULL    |       |员工姓名
    | JOB      | varchar(9)  | YES  |     | NULL    |       |工作岗位
    | MGR      | int(4)      | YES  |     | NULL    |       |上级编号
    | HIREDATE | date        | YES  |     | NULL    |       |入职日期
    | SAL      | double(7,2) | YES  |     | NULL    |       |工资
    | COMM     | double(7,2) | YES  |     | NULL    |       |补助
    | DEPTNO   | int(2)      | YES  |     | NULL    |       |部门编号
    +----------+-------------+------+-----+---------+-------+
    mysql> desc salgrade;
    +-------+---------+------+-----+---------+-------+
    | Field | Type    | Null | Key | Default | Extra |
    +-------+---------+------+-----+---------+-------+
    | GRADE | int(11) | YES  |     | NULL    |       |工资等级
    | LOSAL | int(11) | YES  |     | NULL    |       |最低工资
    | HISAL | int(11) | YES  |     | NULL    |       |最高工资
    +-------+---------+------+-----+---------+-------+

    describe缩写为：desc
    mysql> describe dept;
    +--------+-------------+------+-----+---------+-------+
    | Field  | Type        | Null | Key | Default | Extra |
    +--------+-------------+------+-----+---------+-------+
    | DEPTNO | int(2)      | NO   | PRI | NULL    |       |
    | DNAME  | varchar(14) | YES  |     | NULL    |       |
    | LOC    | varchar(13) | YES  |     | NULL    |       |
    +--------+-------------+------+-----+---------+-------+

## 查看mysql数据库的版本号：
    mysql> select version();
		+-----------+
		| version() |
		+-----------+
		| 5.5.36    |
		+-----------+
	
## 查看当前使用的是哪个数据库？
	mysql> select database();
	+-------------+
	| database()  |
	+-------------+
	| bjpowernode |
	+-------------+
	
	mysql> show
    -> databases
    -> ;
	+--------------------+
	| Database           |
	+--------------------+
	| information_schema |
	| bjpowernode        |
	| mysql              |
	| performance_schema |
	| test               |
	+--------------------+

	注意：mysql是不见“;”不执行，“;”表示结束！

	mysql> show
    ->
    ->
    ->
    ->
    ->
    ->
    ->
    ->
    -> \c
	mysql>
	\c用来终止一条命令的输入。


