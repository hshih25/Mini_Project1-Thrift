struct another{
	1: i32 num1,
	2: i64 num2,
	3: string str1,
	4: double num3,
}
struct heavy{
	1: i32 num1,
	2: double num2,
	3: string str1,
	4: bool bool1,
	5: another an,
}

service Serv{
	void intPacking(1: i32 num1),
	void doublePacking(1: double num2),
	void stringPacking(1: string str1),
	void structPacking(1: heavy h)
}
