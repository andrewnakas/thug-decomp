/* fuzzy: 95.0 */
struct Size_001657F0 {
    int w;
    int h;
};

extern "C" int func_001657A0(int n);
extern "C" int func_00165AC8(int v);

static inline Size_001657F0* At_001657F0(Size_001657F0* base, int g, int i, int j)
{
    Size_001657F0* p = (Size_001657F0*)((char*)base + (j * 8 + i * 0x50 + g * 0x320));
    return p;
}

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
    Size_001657F0* e = At_001657F0(m_grid[0][0], g, i, j);
    *w = e->w;
    *h = e->h;
}
