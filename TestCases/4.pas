const a = 65, A = 'A';
var inputc : char;
	inputi : integer;

function fc : char;
begin
	fc := A;
end;


begin
	read(inputc);
	write(inputc);
	inputi := inputc;
	write(inputi);
	inputi := inputi + 65536;
	inputc := inputi;
	if inputc = inputi
	then write("failed\n")
	else write("succeed\n");
	write(fc);
	if fc <> a
	then write("failed\n")
	else write("succeed\n")
end.