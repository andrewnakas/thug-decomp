/* sym: __12Tab_00262540i = 0x00263260 */
struct Tab_00262540 {
    int m0[6];
    Tab_00262540(int n);
};

struct Obj_00262540 {
    int m0;
    Tab_00262540 m4;
    int m1C[2];
    int m24;
    int m28;
    int m2C;
    Obj_00262540();
};

Obj_00262540::Obj_00262540() : m4(0x20)
{
    m24 = 0;
    for (int i = 1; i >= 0; i--) m1C[i] = 0;
    m28 = 0;
    m2C = 0;
}
