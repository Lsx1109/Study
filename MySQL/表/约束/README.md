# 什么是约束？
	约束对应的英语单词：constraint
	在创建表的时候，我们可以给表中的字段加上一些约束，来保证这个表中数据的
	完整性、有效性！！！

	约束的作用就是为了保证：表中的数据有效！！
# 约束包括哪些？
	非空约束：not null
	唯一性约束: unique
	主键约束: primary key （简称PK）
	外键约束：foreign key（简称FK）
	检查约束：check（mysql不支持，oracle支持）

	我们这里重点学习四个约束：
		not null
		unique
		primary key
		foreign key
# 主键值建议使用：
		int
		bigint
		char
		等类型。

		不建议使用：varchar来做主键。主键值一般都是数字，一般都是定长的！

