# unique 和 not null联合
		drop table if exists t_vip;
		create table t_vip(
			id int,
			name varchar(255) not null unique
		);

		mysql> desc t_vip;
		+-------+--------------+------+-----+---------+-------+
		| Field | Type         | Null | Key | Default | Extra |
		+-------+--------------+------+-----+---------+-------+
		| id    | int(11)      | YES  |     | NULL    |       |
		| name  | varchar(255) | NO   | PRI | NULL    |       |
		+-------+--------------+------+-----+---------+-------+

		在mysql当中，如果一个字段同时被not null和unique约束的话，
		该字段自动变成主键字段。（注意：oracle中不一样！）

		insert into t_vip(id,name) values(1,'zhangsan');

		insert into t_vip(id,name) values(2,'zhangsan'); //错误了：name不能重复

		insert into t_vip(id) values(2); //错误了：name不能为NULL。
