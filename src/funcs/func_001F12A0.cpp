/* sym: __13Comp_001F12A0 = 0x001E4ED8 */
struct Comp_001F12A0 {
    char m[0x10];
    Comp_001F12A0();
};

struct Obj_001F12A0 {
    int m0;
    Comp_001F12A0 m_comps[20];
    char pad144[0x1F8 - 0x144];
    int m1F8;
    Obj_001F12A0();
};
extern "C" void func_001F1318(Obj_001F12A0* self);

Obj_001F12A0::Obj_001F12A0()
{
    func_001F1318(this);
    m1F8 = 1;
}
