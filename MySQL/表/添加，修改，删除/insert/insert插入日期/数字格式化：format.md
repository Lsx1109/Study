# 数字格式化：format
		select ename,sal from emp;
		+--------+---------+
		| ename  | sal     |
		+--------+---------+
		| SMITH  |  800.00 |
		| ALLEN  | 1600.00 |
		| WARD   | 1250.00 |
		| JONES  | 2975.00 |
		| MARTIN | 1250.00 |
		| BLAKE  | 2850.00 |
		| CLARK  | 2450.00 |
		| SCOTT  | 3000.00 |
		| KING   | 5000.00 |
		| TURNER | 1500.00 |
		| ADAMS  | 1100.00 |
		| JAMES  |  950.00 |
		| FORD   | 3000.00 |
		| MILLER | 1300.00 |
		+--------+---------+

		格式化数字：format(数字, '格式')
			select ename,format(sal, '$999,999') as sal from emp;
			+--------+-------+
			| ename  | sal   |
			+--------+-------+
			| SMITH  | 800   |
			| ALLEN  | 1,600 |
			| WARD   | 1,250 |
			| JONES  | 2,975 |
			| MARTIN | 1,250 |
			| BLAKE  | 2,850 |
			| CLARK  | 2,450 |
			| SCOTT  | 3,000 |
			| KING   | 5,000 |
			| TURNER | 1,500 |
			| ADAMS  | 1,100 |
			| JAMES  | 950   |
			| FORD   | 3,000 |
			| MILLER | 1,300 |
			+--------+-------+

	str_to_date：将字符串varchar类型转换成date类型
	date_format：将date类型转换成具有一定格式的varchar字符串类型。

	drop table if exists t_user;
	create table t_user(
		id int,
		name varchar(32),
		birth date // 生日也可以使用date日期类型
	);

	create table t_user(
		id int,
		name varchar(32),
		birth char(10) // 生日可以使用字符串，没问题。
	);

	生日：1990-10-11 （10个字符）

	注意：数据库中的有一条命名规范：
		所有的标识符都是全部小写，单词和单词之间使用下划线进行衔接。

	mysql> desc t_user;
	+-------+-------------+------+-----+---------+-------+
	| Field | Type        | Null | Key | Default | Extra |
	+-------+-------------+------+-----+---------+-------+
	| id    | int(11)     | YES  |     | NULL    |       |
	| name  | varchar(32) | YES  |     | NULL    |       |
	| birth | date        | YES  |     | NULL    |       |
	+-------+-------------+------+-----+---------+-------+

