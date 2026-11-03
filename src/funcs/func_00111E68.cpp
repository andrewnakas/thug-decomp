struct Obj111E68;
extern "C" Obj111E68* func_0010EE50(int a, int b, int c);
extern "C" int func_00111CF8(Obj111E68* o, int a, int b, int c);
extern "C" void func_0010EF80(Obj111E68* o);
extern "C" Obj111E68* func_00111E68(int a, int b, int c)
{
    Obj111E68* o = func_0010EE50(a, b, c);
    if (o) {
        if (!func_00111CF8(o, a, b, c)) {
            func_0010EF80(o);
            return 0;
        }
        return o;
    }
    return 0;
}
