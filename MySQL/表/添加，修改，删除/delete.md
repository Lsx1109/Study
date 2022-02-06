# 删除数据 delete （DML）
	语法格式？
		delete from 表名 where 条件;

	注意：没有条件，整张表的数据会全部删除！

	delete from t_user where id = 2;

	insert into t_user(id) values(2);

	delete from t_user; // 删除所有！
