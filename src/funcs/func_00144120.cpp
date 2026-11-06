struct Col_00144120 {
    unsigned char r, g, b, a;
    Col_00144120(const Col_00144120& o) { *this = o; }
};

extern Col_00144120 D_00393F10;
extern "C" void func_00152028(Col_00144120 c);

extern "C" void func_00144120(Col_00144120 c)
{
    D_00393F10 = c;
    func_00152028(c);
}
