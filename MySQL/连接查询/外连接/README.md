# 外连接

    mysql> select * from emp; e
    +-------+--------+-----------+------+------------+---------+---------+--------+
    | EMPNO | ENAME  | JOB       | MGR  | HIREDATE   | SAL     | COMM    | DEPTNO |
    +-------+--------+-----------+------+------------+---------+---------+--------+
    |  7369 | SMITH  | CLERK     | 7902 | 1980-12-17 |  800.00 |    NULL |     20 |
    |  7499 | ALLEN  | SALESMAN  | 7698 | 1981-02-20 | 1600.00 |  300.00 |     30 |
    |  7521 | WARD   | SALESMAN  | 7698 | 1981-02-22 | 1250.00 |  500.00 |     30 |
    |  7566 | JONES  | MANAGER   | 7839 | 1981-04-02 | 2975.00 |    NULL |     20 |
    |  7654 | MARTIN | SALESMAN  | 7698 | 1981-09-28 | 1250.00 | 1400.00 |     30 |
    |  7698 | BLAKE  | MANAGER   | 7839 | 1981-05-01 | 2850.00 |    NULL |     30 |
    |  7782 | CLARK  | MANAGER   | 7839 | 1981-06-09 | 2450.00 |    NULL |     10 |
    |  7788 | SCOTT  | ANALYST   | 7566 | 1987-04-19 | 3000.00 |    NULL |     20 |
    |  7839 | KING   | PRESIDENT | NULL | 1981-11-17 | 5000.00 |    NULL |     10 |
    |  7844 | TURNER | SALESMAN  | 7698 | 1981-09-08 | 1500.00 |    0.00 |     30 |
    |  7876 | ADAMS  | CLERK     | 7788 | 1987-05-23 | 1100.00 |    NULL |     20 |
    |  7900 | JAMES  | CLERK     | 7698 | 1981-12-03 |  950.00 |    NULL |     30 |
    |  7902 | FORD   | ANALYST   | 7566 | 1981-12-03 | 3000.00 |    NULL |     20 |
    |  7934 | MILLER | CLERK     | 7782 | 1982-01-23 | 1300.00 |    NULL |     10 |
    +-------+--------+-----------+------+------------+---------+---------+--------+

    mysql> select * from dept; d
    +--------+------------+----------+
    | DEPTNO | DNAME      | LOC      |
    +--------+------------+----------+
    |     10 | ACCOUNTING | NEW YORK |
    |     20 | RESEARCH   | DALLAS   |
    |     30 | SALES      | CHICAGO  |
    |     40 | OPERATIONS | BOSTON   |
    +--------+------------+----------+

    内连接：（A和B连接，AB两张表没有主次关系。平等的。）
    select 
	e.ename,d.dname
    from
	emp e
    join
	dept d
    on
	e.deptno = d.deptno; //内连接的特点：完成能够匹配上这个条件的数据查询出来。

    +--------+------------+
    | ename  | dname      |
    +--------+------------+
    | CLARK  | ACCOUNTING |
    | KING   | ACCOUNTING |
    | MILLER | ACCOUNTING |
    | SMITH  | RESEARCH   |
    | JONES  | RESEARCH   |
    | SCOTT  | RESEARCH   |
    | ADAMS  | RESEARCH   |
    | FORD   | RESEARCH   |
    | ALLEN  | SALES      |
    | WARD   | SALES      |
    | MARTIN | SALES      |
    | BLAKE  | SALES      |
    | TURNER | SALES      |
    | JAMES  | SALES      |
    +--------+------------+

    外连接（右外连接）：
    select 
	e.ename,d.dname
    from
	emp e 
    right join 
	dept d
    on
	e.deptno = d.deptno;

    // outer是可以省略的，带着可读性强。
    select 
	e.ename,d.dname
    from
	emp e 
    right outer join 
	dept d
    on
	e.deptno = d.deptno;

    right代表什么：表示将join关键字右边的这张表看成主表，主要是为了将
    这张表的数据全部查询出来，捎带着关联查询左边的表。
    在外连接当中，两张表连接，产生了主次关系。

    外连接（左外连接）：
    select 
	e.ename,d.dname
    from
	dept d 
    left join 
	emp e
    on
	e.deptno = d.deptno;

    // outer是可以省略的，带着可读性强。
    select 
	e.ename,d.dname
    from
	dept d 
    left outer join 
	emp e
    on
	e.deptno = d.deptno;

    带有right的是右外连接，又叫做右连接。
    带有left的是左外连接，又叫做左连接。
    任何一个右连接都有左连接的写法。
    任何一个左连接都有右连接的写法。

    +--------+------------+
    | ename  | dname      |
    +--------+------------+
    | CLARK  | ACCOUNTING |
    | KING   | ACCOUNTING |
    | MILLER | ACCOUNTING |
    | SMITH  | RESEARCH   |
    | JONES  | RESEARCH   |
    | SCOTT  | RESEARCH   |
    | ADAMS  | RESEARCH   |
    | FORD   | RESEARCH   |
    | ALLEN  | SALES      |
    | WARD   | SALES      |
    | MARTIN | SALES      |
    | BLAKE  | SALES      |
    | TURNER | SALES      |
    | JAMES  | SALES      |
    | NULL   | OPERATIONS |
    +--------+------------+

    思考：外连接的查询结果条数一定是 >= 内连接的查询结果条数？
	正确。


    案例：查询每个员工的上级领导，要求显示所有员工的名字和领导名？
	select 
		a.ename as '员工名', b.ename as '领导名'
	from
		emp a
	left join
		emp b
	on
		a.mgr = b.empno; 
	
	+--------+--------+
	| 员工名  | 领导名 |
	+--------+--------+
	| SMITH  | FORD   |
	| ALLEN  | BLAKE  |
	| WARD   | BLAKE  |
	| JONES  | KING   |
	| MARTIN | BLAKE  |
	| BLAKE  | KING   |
	| CLARK  | KING   |
	| SCOTT  | JONES  |
	| KING   | NULL   |
	| TURNER | BLAKE  |
	| ADAMS  | SCOTT  |
	| JAMES  | BLAKE  |
	| FORD   | JONES  |
	| MILLER | CLARK  |
	+--------+--------+
