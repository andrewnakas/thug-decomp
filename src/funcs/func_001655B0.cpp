struct Size_001655B0 {
    int w;
    int h;
};

class Obj_001655B0 {
public:
    Size_001655B0 m_grid[4][10][10];
    Obj_001655B0();
};

extern "C" void func_00165610(Obj_001655B0* self, Size_001655B0 (*grid)[10], int n);

Obj_001655B0::Obj_001655B0()
{
    for (int i = 0; i < 4; i++)
        func_00165610(this, m_grid[i], i);
}
