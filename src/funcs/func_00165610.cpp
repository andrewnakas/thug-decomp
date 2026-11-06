struct Size_00165610 {
    int w;
    int h;
};

struct Obj_00165610 {
    void Fn(Size_00165610 (*grid)[10], int n);
};

extern "C" void func_001656E8(Obj_00165610* self, int* w, int* h, int n);

void Obj_00165610::Fn(Size_00165610 (*grid)[10], int n)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[j][i].h = 1 << i;
            grid[j][i].w = 1 << j;
            func_001656E8(this, &grid[j][i].w, &grid[j][i].h, n);
        }
    }
}
