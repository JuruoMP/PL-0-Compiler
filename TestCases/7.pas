var a : integer;

function fun1(a, b, c : integer) : integer;
begin
	fun1 := 2 * a + b + c;
end;

function fun2 : char;
const b = 'b';
begin
	fun2 := fun1(b, b);
end;

begin
	a := fun2
end.
