{ Some program with 2-D arrays converted to 1D }
program sparsematrix;

const N = 100;
var sz, len, val, x, y, succ : integer;
var im : array [1 .. 10000] of integer;

begin
    succ := 0;
    readln(sz);
    y := 0;
    while y < sz do
    begin
        x := 0;
        val := 0;
        while x < sz do
        begin
            readln(len);
            len := x + len;
            while x < len do
            begin
                im[y * N + x] := val;
                x := x + 1
            end;
            val := 1 - val
        end;
        y := y + 1
    end;
    x := 0;
    while x < sz and succ = 0 do
    begin
        y := 0;
        val := 0;
        while y < sz and succ = 0 do
        begin
            readln(len);
            len := y + len;
            while y < len and succ = 0 do
            begin
                if im[y * N + x] <> val then
                    succ := 1
                else
                    y := y + 1
            end;
            val := 1 - val
        end;
        x := x + 1
    end;

    writeln(succ)
end.