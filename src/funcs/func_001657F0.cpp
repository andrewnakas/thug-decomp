struct Size_001657F0 {
    int w;
    int h;
};

extern "C" int func_001657A0(int n);
extern "C" int func_00165AC8(int v);

class Obj_001657F0 {
public:
    Size_001657F0 m_grid[4][10][10];
    void Fn(int* w, int* h, int n);
};

void Obj_001657F0::Fn(int* w, int* h, int n)
{
    int g = func_001657A0(n);
    int i = func_00165AC8(*w) - 1;
    int j = func_00165AC8(*h) - 1;
    *w = m_grid[g][i][j].w;
    *h = m_grid[g][i][j].h;
}
