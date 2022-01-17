把查询结果去除重复记录【distinct】
	注意：原表数据不会被修改，只是查询结果去重。
	去重需要使用一个关键字：distinct

	mysql> select distinct job from emp;
	+-----------+
	| job       |
	+-----------+
	| CLERK     |
	| SALESMAN  |
	| MANAGER   |
	| ANALYST   |
	| PRESIDENT |
	+-----------+

	// 这样编写是错误的，语法错误。
	// distinct只能出现在所有字段的最前方。
	mysql> select ename,distinct job from emp;

	// distinct出现在job,deptno两个字段之前，表示两个字段联合起来去重。
	mysql> select distinct job,deptno from emp;
	+-----------+--------+
	| job       | deptno |
	+-----------+--------+
	| CLERK     |     20 |
	| SALESMAN  |     30 |
	| MANAGER   |     20 |
	| MANAGER   |     30 |
	| MANAGER   |     10 |
	| ANALYST   |     20 |
	| PRESIDENT |     10 |
	| CLERK     |     30 |
	| CLERK     |     10 |
	+-----------+--------+

	统计一下工作岗位的数量？
		select count(distinct job) from emp;
		+---------------------+
		| count(distinct job) |
		+---------------------+
		|                   5 |
		+---------------------+
