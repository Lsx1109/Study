## between … and …. 两个值之间, 等同于 >= and <=
	查询薪资在2450和3000之间的员工信息？包括2450和3000
		第一种方式：>= and <= （and是并且的意思。）
			select empno,ename,sal from emp where sal >= 2450 and sal <= 3000;
			+-------+-------+---------+
			| empno | ename | sal     |
			+-------+-------+---------+
			|  7566 | JONES | 2975.00 |
			|  7698 | BLAKE | 2850.00 |
			|  7782 | CLARK | 2450.00 |
			|  7788 | SCOTT | 3000.00 |
			|  7902 | FORD  | 3000.00 |
			+-------+-------+---------+
		第二种方式：between … and …
			select 
				empno,ename,sal 
			from 
				emp 
			where 
				sal between 2450 and 3000;
			
			注意：
				使用between and的时候，必须遵循左小右大。
				between and是闭区间，包括两端的值。
