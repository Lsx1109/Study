# 非空约束：not null

	非空约束not null约束的字段不能为NULL。
	drop table if exists t_vip;
	create table t_vip(
		id int,
		name varchar(255) not null  // not null只有列级约束，没有表级约束！
	);
	insert into t_vip(id,name) values(1,'zhangsan');
	insert into t_vip(id,name) values(2,'lisi');

	insert into t_vip(id) values(3);
	ERROR 1364 (HY000): Field 'name' doesn't have a default value

	小插曲：
		xxxx.sql这种文件被称为sql脚本文件。
		sql脚本文件中编写了大量的sql语句。
		我们执行sql脚本文件的时候，该文件中所有的sql语句会全部执行！
		批量的执行SQL语句，可以使用sql脚本文件。
		在mysql当中怎么执行sql脚本呢？
			mysql> source D:\course\03-MySQL\document\vip.sql
		
		你在实际的工作中，第一天到了公司，项目经理会给你一个xxx.sql文件，
		你执行这个脚本文件，你电脑上的数据库数据就有了！
