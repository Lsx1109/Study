#  插入数据insert （DML）
	
	语法格式：
		insert into 表名(字段名1,字段名2,字段名3...) values(值1,值2,值3);

		注意：字段名和值要一一对应。什么是一一对应？
			数量要对应。数据类型要对应。
	
	insert into t_student(no,name,sex,age,email) values(1,'zhangsan','m',20,'zhangsan@123.com');
	insert into t_student(email,name,sex,age,no) values('lisi@123.com','lisi','f',20,2);

	insert into t_student(no) values(3);

	+------+----------+------+------+------------------+
	| no   | name     | sex  | age  | email            |
	+------+----------+------+------+------------------+
	|    1 | zhangsan | m    |   20 | zhangsan@123.com |
	|    2 | lisi     | f    |   20 | lisi@123.com     |
	|    3 | NULL     | NULL | NULL | NULL             |
	+------+----------+------+------+------------------+
	insert into t_student(name) values('wangwu');
	+------+----------+------+------+------------------+
	| no   | name     | sex  | age  | email            |
	+------+----------+------+------+------------------+
	|    1 | zhangsan | m    |   20 | zhangsan@123.com |
	|    2 | lisi     | f    |   20 | lisi@123.com     |
	|    3 | NULL     | NULL | NULL | NULL             |
	| NULL | wangwu   | NULL | NULL | NULL             |
	+------+----------+------+------+------------------+
	注意：insert语句但凡是执行成功了，那么必然会多一条记录。
	没有给其它字段指定值的话，默认值是NULL。
	
	drop table if exists t_student;
	create table t_student(
		no int,
		name varchar(32),
		sex char(1) default 'm',
		age int(3),
		email varchar(255)
	);

	+-------+--------------+------+-----+---------+-------+
	| Field | Type         | Null | Key | Default | Extra |
	+-------+--------------+------+-----+---------+-------+
	| no    | int(11)      | YES  |     | NULL    |       |
	| name  | varchar(32)  | YES  |     | NULL    |       |
	| sex   | char(1)      | YES  |     | m       |       |
	| age   | int(3)       | YES  |     | NULL    |       |
	| email | varchar(255) | YES  |     | NULL    |       |
	+-------+--------------+------+-----+---------+-------+
	insert into t_student(no) values(1);
	mysql> select * from t_student;
	+------+------+------+------+-------+
	| no   | name | sex  | age  | email |
	+------+------+------+------+-------+
	|    1 | NULL | m    | NULL | NULL  |
	+------+------+------+------+-------+
	
	insert语句中的“字段名”可以省略吗？可以
		insert into t_student values(2); //错误的

		// 注意：前面的字段名省略的话，等于都写上了！所以值也要都写上！
		insert into t_student values(2, 'lisi', 'f', 20, 'lisi@123.com');
		+------+------+------+------+--------------+
		| no   | name | sex  | age  | email        |
		+------+------+------+------+--------------+
		|    1 | NULL | m    | NULL | NULL         |
		|    2 | lisi | f    |   20 | lisi@123.com |
		+------+------+------+------+--------------+
