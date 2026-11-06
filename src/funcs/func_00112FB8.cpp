struct Cell_00112FB8 {
    int m0[4];
};

extern "C" int func_00113200(Cell_00112FB8* c);

class Grid_00112FB8 {
public:
    int m0;
    Cell_00112FB8 m_cells[1][4];
    Cell_00112FB8* Get(int i, int j);
};

Cell_00112FB8* Grid_00112FB8::Get(int i, int j)
{
    Cell_00112FB8* c = &m_cells[i][j];
    int s = func_00113200(c);
    if (s == 1 || s == 2) {
        return c;
    }
    return 0;
}
