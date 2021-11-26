**is null 为 null（is not null 不为空）**
## 	查询哪些员工的津贴/补助为null？
		mysql> select empno,ename,sal,comm from emp where comm = null;
		Empty set (0.00 sec)

		mysql> select empno,ename,sal,comm from emp where comm is null;
		+-------+--------+---------+------+
		| empno | ename  | sal     | comm |
		+-------+--------+---------+------+
		|  7369 | SMITH  |  800.00 | NULL |
		|  7566 | JONES  | 2975.00 | NULL |
		|  7698 | BLAKE  | 2850.00 | NULL |
		|  7782 | CLARK  | 2450.00 | NULL |
		|  7788 | SCOTT  | 3000.00 | NULL |
		|  7839 | KING   | 5000.00 | NULL |
		|  7876 | ADAMS  | 1100.00 | NULL |
		|  7900 | JAMES  |  950.00 | NULL |
		|  7902 | FORD   | 3000.00 | NULL |
		|  7934 | MILLER | 1300.00 | NULL |
		+-------+--------+---------+------+
		10 rows in set (0.00 sec)

		注意：在数据库当中null不能使用等号进行衡量。需要使用is null
		因为数据库中的null代表什么也没有，它不是一个值，所以不能使用
		等号衡量。

## 	查询哪些员工的津贴/补助不为null？
		select empno,ename,sal,comm from emp where comm is not null;
		+-------+--------+---------+---------+
		| empno | ename  | sal     | comm    |
		+-------+--------+---------+---------+
		|  7499 | ALLEN  | 1600.00 |  300.00 |
		|  7521 | WARD   | 1250.00 |  500.00 |
		|  7654 | MARTIN | 1250.00 | 1400.00 |
		|  7844 | TURNER | 1500.00 |    0.00 |
		+-------+--------+---------+---------+
