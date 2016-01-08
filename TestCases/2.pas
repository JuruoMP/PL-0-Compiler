var
    x, y: integer;

procedure swap1(var a, b: integer);
var
    t: integer;
begin
    t := a;
    a := b;
    b := t;
end;

procedure swap2(a, b: integer);
var
    t: integer;
begin
    t := a;
    a := b;
    b := t;
end;

begin
    x := 1;
    y := 2;
    swap1(x, y);
    if x = 2 
    then write("swap 1 succeed.\n")
    else write("swap 1 failed.", x);
    swap2(x, y);
    if x = 2
    then write("swap 2 succeed.\n")
    else write("swap 2 failed.", x);
end.
