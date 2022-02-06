# 修改update（DML）

    语法格式：
	update 表名 set 字段名1=值1,字段名2=值2,字段名3=值3... where 条件;

	注意：没有条件限制会导致所有数据全部更新。

	update t_user set name = 'jack', birth = '2000-10-11' where id = 2;
	+------+----------+------------+---------------------+
	| id   | name     | birth      | create_time         |
	+------+----------+------------+---------------------+
	|    1 | zhangsan | 1990-10-01 | 2020-03-18 15:49:50 |
	|    2 | jack     | 2000-10-11 | 2020-03-18 15:51:23 |
	+------+----------+------------+---------------------+

	update t_user set name = 'jack', birth = '2000-10-11', create_time = now() where id = 2;

	更新所有？
		update t_user set name = 'abc';
