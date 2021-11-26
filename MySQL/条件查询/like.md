# like 
		称为模糊查询，支持%或下划线匹配
		%匹配任意多个字符
		下划线：任意一个字符。
		（%是一个特殊的符号，_ 也是一个特殊符号）

## 		找出名字中含有O的？
		mysql> select ename from emp where ename like '%O%';
		+-------+
		| ename |
		+-------+
		| JONES |
		| SCOTT |
		| FORD  |
		+-------+

## 		找出名字以T结尾的？
			select ename from emp where ename like '%T';
			
## 		找出名字以K开始的？
			select ename from emp where ename like 'K%';

## 		找出第二个字每是A的？
			select ename from emp where ename like '_A%';
		
## 		找出第三个字母是R的？
			select ename from emp where ename like '__R%';
		
		t_student学生表
		name字段
		----------------------
		zhangsan
		lisi
		wangwu
		zhaoliu
		jack_son

### 		找出名字中有“_”的？
			select name from t_student where name like '%_%'; //这样不行。

			mysql> select name from t_student where name like '%\_%'; // \转义字符。
			+----------+
			| name     |
			+----------+
			| jack_son |
			+----------+
