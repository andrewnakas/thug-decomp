/* fuzzy: 77.3 */
struct Sector_00208C50 {
    int m0;
    unsigned short m_flags;
    char m_pad6[0x10 - 0x6];
    unsigned char m_stamp;
    void SetStamp(unsigned char st) { m_stamp = st; }
};

struct Cell_00208C50 {
    int m0;
    int m_count;
    int m8;
    Sector_00208C50** m_items;
    char m_pad10[0x30 - 0x10];
};

struct Vec_00208C50 {
    float x, y, z, w;
};

struct Box_00208C50 {
    Vec_00208C50 min;
    Vec_00208C50 max;
};

struct Grid_00208C50 {
    float m_x;
    float m4;
    float m_z;
    char m_padC[0x20 - 0xC];
    float m_cellW;
    float m_cellD;
    int m_numX;
    int m_numZ;
    char m_pad30[0x50 - 0x30];
    Cell_00208C50 m_cells[1][20];
    Cell_00208C50& GetCell(int x, int z) { return m_cells[x][z]; }
};

extern Sector_00208C50* D_003F3F70[];
extern "C" int func_00207F80();

extern "C" Sector_00208C50** func_00208C50(Grid_00208C50* grid, Box_00208C50* box)
{
    int stamp = func_00207F80();
    int x0 = (int)((box->min.x - grid->m_x - 0.5f) / grid->m_cellW);
    int x1 = (int)((box->max.x - grid->m_x + 0.5f) / grid->m_cellW);
    int z0 = (int)((box->min.z - grid->m_z - 0.5f) / grid->m_cellD);
    int z1 = (int)((box->max.z - grid->m_z + 0.5f) / grid->m_cellD);
    if (x0 < 0)
        x0 = 0;
    else if (x0 >= grid->m_numX)
        x0 = grid->m_numX - 1;
    if (z0 < 0)
        z0 = 0;
    else if (z0 >= grid->m_numZ)
        z0 = grid->m_numZ - 1;
    if (x1 < 0)
        x1 = 0;
    else if (x1 >= grid->m_numX)
        x1 = grid->m_numX - 1;
    if (z1 < 0)
        z1 = 0;
    else if (z1 >= grid->m_numZ)
        z1 = grid->m_numZ - 1;
    int count = 0;
    for (int x = x0; x <= x1; x++) {
        for (int z = z0; z <= z1; z++) {
            for (int i = 0; i < grid->GetCell(x, z).m_count; i++) {
                Sector_00208C50* s = grid->GetCell(x, z).m_items[i];
                if (!(s->m_flags & 6) && s->m_stamp != stamp) {
                    D_003F3F70[count++] = s;
                    s->SetStamp(stamp);
                }
            }
        }
    }
    D_003F3F70[count] = 0;
    return D_003F3F70;
}
