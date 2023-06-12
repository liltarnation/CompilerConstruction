program permutations;

var n, lcm, l, i : integer;
var p, loopLength : array [0 .. 100] of integer;

function gcd(a : integer; b : integer): integer;
begin
    if a mod b <> 0 then
        gcd := gcd(b, a mod b)
    else
        gcd := b
end;

function loopLengthAt(p : array [0 .. 100] of integer; length : integer; start : integer; current : integer; n : integer; lengths : array [0 .. 100] of integer) : integer;
var isSet, result : integer;
begin
    isSet := 0;
    if lengths[current] <> 0 then
    begin
        loopLengthAt := lengths[current];
        isSet := 1
    end
    else if current = start then
        if n > 0 then
        begin
            lengths[current] := n;
            loopLengthAt := n;
            isSet := 1
        end
        else skip
    else skip;

    if isSet = 0 then
    begin
        result := loopLengthAt(p, length, start, p[current], n + 1, lengths);
        lengths[current] := result;
        loopLengthAt := result
    end
    else skip
end;

begin
    lcm := 1;
    i := 0;
    readln(n);

    while i < n do
    begin
        readln(p[i]);
        loopLength[i] := 0;
        i := i + 1
    end;

    i := 0;
    while i < n do
    begin
        l := loopLengthAt(p, n, i, i, 0, loopLength);
        lcm := lcm * l div gcd(lcm, l);
        i := i + 1
    end;

    writeln(lcm)
end.