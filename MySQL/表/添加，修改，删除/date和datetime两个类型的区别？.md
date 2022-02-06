# date和datetime两个类型的区别？
	date是短日期：只包括年月日信息。
	datetime是长日期：包括年月日时分秒信息。

	drop table if exists t_user;
	create table t_user(
		id int,
		name varchar(32),
		birth date,
		create_time datetime
	);


	id是整数
	name是字符串
	birth是短日期
	create_time是这条记录的创建时间：长日期类型

	mysql短日期默认格式：%Y-%m-%d
	mysql长日期默认格式：%Y-%m-%d %h:%i:%s

	insert into t_user(id,name,birth,create_time) values(1,'zhangsan','1990-10-01','2020-03-18 15:49:50');

	在mysql当中怎么获取系统当前时间？
		now() 函数，并且获取的时间带有：时分秒信息！！！！是datetime类型的。
	
		insert into t_user(id,name,birth,create_time) values(2,'lisi','1991-10-01',now());
