const ca = 'a', cz = 'z', ia = +65, split = 'o';
var a, b, i, j : integer;
	c, c1, c2 : char;
	i1, i2 : integer;
	n : integer;

procedure swap(var a, b : integer);
	var temp : integer;
	begin
		temp := a;
		a := b;
		b := temp;
	end;

procedure empty;
begin
end;

function calcfib(n : integer) : integer;
	var num1, num2 : integer;
		i : integer;
	begin
		num1 := 1;
		num2 := num1 * 1;
		if n <= 2
		then calcfib := 1
		else
		begin
			for i := 3 to n do
			begin
				swap(num1, num2);
				num2 := num2 + num1;
			end;
			calcfib := num2;
		end;
	end;

procedure paint(n : integer; c : char);
	var i : integer;
		arr : array[20] of char;
	procedure paintsingle(n : integer; c : char);
		var i, j : integer;
			arr : array[20] of char;
		begin
			for i := 1 to n do
			begin
				for j := 1 to n do
				begin
					if j <= i
					then arr[j] := c
					else arr[j] := split;
				end;
				for j := 1 to n do
					write(arr[j]);
				write("\n");
			end;
			write("\n");
		end;
	begin
		i := 1;
		do
		begin
			paintsingle(i, c);
			i := i + 1;
		end
		while i <= n;
	end;

function catalan(var n : integer) : integer;
	function C(n, m : integer) : integer;
		var i : integer;
			result : integer;
		begin
			result := 1;
			for i := n - m + 1 to n do
				result := result * i;
			for i := m downto 1 do
				result := result / i;
			C := result;
		end;
	begin
		write("catalan(n) = C(2n, n) / (n + 1)\n");
		if n > 8
		then
		begin
			write("cannot output such a big number");
			catalan := -1;
		end
		else catalan := C(2 * n, n) / (n + 1);
	end;

procedure game;
	begin
		write("Tips: the number is between 1 to 10, good luck!\n");
		i1 := -1;
		do
		begin
			write("Input number:");
			read(i1);
			if i1 <> 6
			then write("Wrong, try again.\n");
		end
		while i1 <> 6;
		write("Correct, congratulations!");
	end;

begin
	c1 := ca;
	c2 := cz - 3;
	write(c1);
	write("," ,c2);
	write("=", ca + 0);
	write(",", cz - 3);
	write("\n");

	write("Input n, output fibonacci(n):\n");
	read(n);
	write(calcfib(n));

	write("Now we are going to paint a picture.\n");
	write("input size(int, <=6) & character(char):");
	read(n, c);
	if n > 6
	then write("n is too big")
	else paint(n, c);

	write("Input n(<=8), output Catalan(n):\n");
	read(n);
	a := catalan(n);
	if a <> -1
	then write(a);

	write("\n");
	write("At last, let's play a game.\n");
	write("Guess what is the number I'm thinking.\n");
	game;
end.