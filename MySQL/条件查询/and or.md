**and 并且**
## 	查询工作岗位是MANAGER并且工资大于2500的员工信息？
		select 
			empno,ename,job,sal 
		from 
			emp 
		where 
			job = 'MANAGER' and sal > 2500;
		
		+-------+-------+---------+---------+
		| empno | ename | job     | sal     |
		+-------+-------+---------+---------+
		|  7566 | JONES | MANAGER | 2975.00 |
		|  7698 | BLAKE | MANAGER | 2850.00 |
		+-------+-------+---------+---------+

**or 或者**
## 	查询工作岗位是MANAGER和SALESMAN的员工？
		select empno,ename,job from emp where job = 'MANAGER';
		select empno,ename,job from emp where job = 'SALESMAN';

		select 
			empno,ename,job
		from
			emp
		where 
			job = 'MANAGER' or job = 'SALESMAN';
		
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
	
# 	and和or同时出现的话，有优先级问题吗？
	查询工资大于2500，并且部门编号为10或20部门的员工？
		select 
			*
		from
			emp
		where
			sal > 2500 and deptno = 10 or deptno = 20;
		分析以上语句的问题？
			and优先级比or高。
			以上语句会先执行and，然后执行or。
			以上这个语句表示什么含义？
				找出工资大于2500并且部门编号为10的员工，或者20部门所有员工找出来。
		
		select 
			*
		from
			emp
		where
			sal > 2500 and (deptno = 10 or deptno = 20);
		
**and和or同时出现，and优先级较高。如果想让or先执行，需要加“小括号”
		以后在开发中，如果不确定优先级，就加小括号就行了。**
