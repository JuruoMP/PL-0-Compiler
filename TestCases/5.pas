const one = 1, two = 2, five = 5, ten = 10;
var a, b, c, d : integer;

begin
	a := (one + two) + ten + (one + two) + ten + five;
	if a = 31
	then write("success\n")
	else write("failed\n", a);
	b := one + two + ten + five + ten + two + one;
	if b <> a
	then write("failed\n", b)
	else write("succeed\n");
	c := (a * five + b * five) / (a + b);
	if c * 2 = ten * 2 / 2 + 6 - 3 - 3
	then write("succeed\n")
	else write("failed\n", c);
	d := a + b + c + 1024;
	if d < 0
	then write("failed\n", d)
	else write("succeed\n");
end.