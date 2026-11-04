extern "C" void func_0010BEB8(int a);

struct Cell_00208BB8 {
    char pad0[0x24];
    int m_24;
    int m28;
    int m_2C;
};

struct Obj_00208BB8 {
    char pad0[0x30];
    Cell_00208BB8 m_grid[20][20];
    void Clear();
};

void Obj_00208BB8::Clear()
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            Cell_00208BB8* c = &m_grid[i][j];
            if (c->m_2C) {
                func_0010BEB8(c->m_2C);
                c->m_2C = 0;
            }
            c->m_24 = 0;
        }
    }
}
