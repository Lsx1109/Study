**in 包含，相当于多个 or （not in 不在这个范围中）**
## 		查询工作岗位是MANAGER和SALESMAN的员工？
			select empno,ename,job from emp where job = 'MANAGER' or job = 'SALESMAN';
			select empno,ename,job from emp where job in('MANAGER', 'SALESMAN');
			+-------+--------+----------+
			| empno | ename  | job      |
			+-------+--------+----------+
			|  7499 | ALLEN  | SALESMAN |
			|  7521 | WARD   | SALESMAN |
			|  7566 | JONES  | MANAGER  |
			|  7654 | MARTIN | SALESMAN |
			|  7698 | BLAKE  | MANAGER  |
			|  7782 | CLARK  | MANAGER  |
			|  7844 | TURNER | SALESMAN |
			+-------+--------+----------+
			注意：in不是一个区间。in后面跟的是具体的值。

## 		查询薪资是800和5000的员工信息？
			select ename,sal from emp where sal = 800 or sal = 5000;
			select ename,sal from emp where sal in(800, 5000); //这个不是表示800到5000都找出来。
			+-------+---------+
			| ename | sal     |
			+-------+---------+
			| SMITH |  800.00 |
			| KING  | 5000.00 |
			+-------+---------+
			select ename,sal from emp where sal in(800, 5000, 3000);

			// not in 表示不在这几个值当中的数据。
			select ename,sal from emp where sal not in(800, 5000, 3000);
			+--------+---------+
			| ename  | sal     |
			+--------+---------+
			| ALLEN  | 1600.00 |
			| WARD   | 1250.00 |
			| JONES  | 2975.00 |
			| MARTIN | 1250.00 |
			| BLAKE  | 2850.00 |
			| CLARK  | 2450.00 |
			| TURNER | 1500.00 |
			| ADAMS  | 1100.00 |
			| JAMES  |  950.00 |
			| MILLER | 1300.00 |
			+--------+---------+

**not 可以取非，主要用在 is 或 in 中
		is null
		is not null
		in
		not in**
