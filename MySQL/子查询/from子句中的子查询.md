# from子句中的子查询
	注意：from后面的子查询，可以将子查询的查询结果当做一张临时表。（技巧）

	案例：找出每个岗位的平均工资的薪资等级。

	第一步：找出每个岗位的平均工资（按照岗位分组求平均值）
		select job,avg(sal) from emp group by job;
		+-----------+-------------+
		| job       | avgsal      |
		+-----------+-------------+
		| ANALYST   | 3000.000000 |
		| CLERK     | 1037.500000 |
		| MANAGER   | 2758.333333 |
		| PRESIDENT | 5000.000000 |
		| SALESMAN  | 1400.000000 |
		+-----------+-------------+t表

	第二步：克服心理障碍，把以上的查询结果就当做一张真实存在的表t。
	mysql> select * from salgrade; s表
	+-------+-------+-------+
	| GRADE | LOSAL | HISAL |
	+-------+-------+-------+
	|     1 |   700 |  1200 |
	|     2 |  1201 |  1400 |
	|     3 |  1401 |  2000 |
	|     4 |  2001 |  3000 |
	|     5 |  3001 |  9999 |
	+-------+-------+-------+
	t表和s表进行表连接，条件：t表avg(sal) between s.losal and s.hisal;
		
		select 
			t.*, s.grade
		from
			(select job,avg(sal) as avgsal from emp group by job) t
		join
			salgrade s
		on
			t.avgsal between s.losal and s.hisal;
		
		+-----------+-------------+-------+
		| job       | avgsal      | grade |
		+-----------+-------------+-------+
		| CLERK     | 1037.500000 |     1 |
		| SALESMAN  | 1400.000000 |     2 |
		| ANALYST   | 3000.000000 |     4 |
		| MANAGER   | 2758.333333 |     4 |
		| PRESIDENT | 5000.000000 |     5 |
		+-----------+-------------+-------+
