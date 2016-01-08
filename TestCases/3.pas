const a = 1;
var b, c: integer;

function fib(b: integer): integer;
begin
	if b = a then begin
		fib := 1
	end
	else begin
		fib := b + fib(b - 1);
	end
end;

begin
	b := (a * (-2) + 10 - 1) / 2;
	if fib(fib(fib(b))) = 231 
	then write("success.")
	else write("failed.");
end.
