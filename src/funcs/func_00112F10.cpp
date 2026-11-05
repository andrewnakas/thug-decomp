struct Cell_00112F10 {
    int m0;
    int m4;
    int m_row;
    int m_col;
};

struct Grid_00112F10 {
    Cell_00112F10 m_cells[2][4];
};

extern "C" void func_003234D8(Grid_00112F10* g);

extern "C" Grid_00112F10* func_00112F10(Grid_00112F10* g)
{
    func_003234D8(g);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            g->m_cells[i][j].m_row = i;
            g->m_cells[i][j].m_col = j;
        }
    }
    return g;
}
