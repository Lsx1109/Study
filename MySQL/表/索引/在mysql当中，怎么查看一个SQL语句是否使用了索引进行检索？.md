# 在mysql当中，怎么查看一个SQL语句是否使用了索引进行检索？

	mysql> explain select * from emp where ename = 'KING';
	+----+-------------+-------+------+---------------+------+---------+------+------+-------------+
	| id | select_type | table | type | possible_keys | key  | key_len | ref  | rows | Extra       |
	+----+-------------+-------+------+---------------+------+---------+------+------+-------------+
	|  1 | SIMPLE      | emp   | ALL  | NULL          | NULL | NULL    | NULL |   14 | Using where |
	+----+-------------+-------+------+---------------+------+---------+------+------+-------------+
	扫描14条记录：说明没有使用索引。type=ALL

	mysql> create index emp_ename_index on emp(ename);

	mysql> explain select * from emp where ename = 'KING';
	+----+-------------+-------+------+-----------------+-----------------+---------+-------+------+-------------+
	| id | select_type | table | type | possible_keys   | key             | key_len | ref   | rows | Extra       |
	+----+-------------+-------+------+-----------------+-----------------+---------+-------+------+-------------+
	|  1 | SIMPLE      | emp   | ref  | emp_ename_index | emp_ename_index | 33      | const |    1 | Using where |
	+----+-------------+-------+------+-----------------+-----------------+---------+-------+------+-------------+
