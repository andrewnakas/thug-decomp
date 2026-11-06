/* sym: __13Base_00120168 = 0x00183CF8 */
/* sym: _vt$13Comp_00120168 = 0x0035CAE0 */
struct Base_00120168 {
    int m0;
    int m4;
    Base_00120168();
    virtual void V0();
};

struct Comp_00120168 : Base_00120168 {
    char padC[0x48 - 0xC];
    int m48;
    int m4C;
    Comp_00120168(int a, int b);
    virtual void V0();
};

Comp_00120168::Comp_00120168(int a, int b)
{
    m48 = a;
    m4C = b;
}
