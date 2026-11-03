struct Obj10EC78;
extern "C" Obj10EC78* func_0010EE50(int a, int b, int c);
extern "C" int func_0010E860(Obj10EC78* o, int a, int b, int c);
extern "C" void func_0010EF80(Obj10EC78* o);
extern "C" Obj10EC78* func_0010EC78(int a, int b, int c)
{
    Obj10EC78* o = func_0010EE50(a, b, c);
    if (o) {
        if (!func_0010E860(o, a, b, c)) {
            func_0010EF80(o);
            return 0;
        }
        return o;
    }
    return 0;
}
