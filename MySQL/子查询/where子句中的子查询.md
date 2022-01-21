# where子句中的子查询

	案例：找出比最低工资高的员工姓名和工资？
		select 
			ename,sal
		from
			emp 
		where
			sal > min(sal);

		ERROR 1111 (HY000): Invalid use of group function
		where子句中不能直接使用分组函数。
	
	实现思路：
		第一步：查询最低工资是多少
			select min(sal) from emp;
			+----------+
			| min(sal) |
			+----------+
			|   800.00 |
			+----------+
		第二步：找出>800的
			select ename,sal from emp where sal > 800;
		
		第三步：合并
			select ename,sal from emp where sal > (select min(sal) from emp);
			+--------+---------+
			| ename  | sal     |
			+--------+---------+
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
