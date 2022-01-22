limit怎么用呢？

	完整用法：limit startIndex, length
		startIndex是起始下标，length是长度。
		起始下标从0开始。

	缺省用法：limit 5; 这是取前5.

	按照薪资降序，取出排名在前5名的员工？
	select 
		ename,sal
	from
		emp
	order by 
		sal desc
	limit 5; //取前5

	select 
		ename,sal
	from
		emp
	order by 
		sal desc
	limit 0,5;

	+-------+---------+
	| ename | sal     |
	+-------+---------+
	| KING  | 5000.00 |
	| SCOTT | 3000.00 |
	| FORD  | 3000.00 |
	| JONES | 2975.00 |
	| BLAKE | 2850.00 |
	+-------+---------+

*注意：mysql当中limit在order by之后执行！！！！！！*
