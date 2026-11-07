/* fuzzy: 76.7 */
/* Grass/ground-cover renderer around (x, z): walks the 33x33 cells of a 128-unit grid near the point, and for
   every cell's (up to 4) blades emits a 0x20-byte vertex record into VU1 packets of 0x50 records. */
struct Row_0015D8A0 {
    unsigned short m_start;
    unsigned short m_end;
    unsigned short m_offset;
};

struct Field_0015D8A0 {
    float m_height;
    int m_steps;
    float m_y;
    char padC[4];
    unsigned int m_10;
    unsigned int m_14;
    char pad18[0x28 - 0x18];
    int m_enabled;
    char pad2C[0x54 - 0x2C];
    unsigned char* m_cells;
    Row_0015D8A0* m_rows;
    int m_cellBase[0x101];
    int m_rowCount;
    float m_originX;
    float m_originZ;
    char pad46C[0x490 - 0x46C];
    unsigned char m_blade[0x400];
    unsigned char m_bladeX[0x400];
    unsigned char m_bladeZ[0x400];
    char pad1090[8];
    long m_tex;
};

extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern char D_200[];
extern char D_310[];

extern "C" void func_00174460(unsigned int mask);
extern "C" void func_00174680();
extern "C" void func_00168D98(int a, long b, int c, int d);

void func_0015D8A0(Field_0015D8A0* o, float x, float z)
{
    if (!o->m_enabled)
        return;
    int cx = (int)((x - o->m_originX) * (1.0f / 128.0f));
    int cz = (int)((z - o->m_originZ) * (1.0f / 128.0f));
    int x0 = cx - 16;
    int x1 = cx + 16;
    int z0 = cz - 16;
    int z1 = cz + 16;
    if (z1 < 0)
        return;
    if (z0 > o->m_rowCount - 1)
        return;

    func_00174460(0xFFFFFFFF);
    func_00174680();
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = 0x10000000;
    p[1] = 0;
    D_00394274 = p + 2;
    func_00168D98(0, o->m_tex, 0, 0);

    int height[0x100];
    int spread[0x100];
    unsigned int* out = D_00394274;
    int ox = (int)(o->m_originX * 16.0f);
    int oz = (int)(o->m_originZ * 16.0f);
    int oy = (int)(o->m_y * 16.0f);
    int n = o->m_steps;
    for (int i = 0xFE - n; i < 0x100; i++)
        height[i] = (int)((o->m_height - (float)(i + n - 0xFE) / (float)n * o->m_height) * 16.0f);
    for (int i = 0; i < 0x100; i++)
        spread[i] = (int)((float)i * (2048.0f / 255.0f));

    int left = 0;
    unsigned int* rec = 0;
    unsigned int* start = 0;
    for (int zi = z0; zi <= z1; zi++) {
int zc = zi >= 0 ? (zi > o->m_rowCount - 1 ? o->m_rowCount - 1 : zi) : 0;
        Row_0015D8A0* row = &o->m_rows[zc];
        if (row->m_start == 0x4000)
            continue;
        int sub = (zc & 0xF) << 4;
        int wz = (zc << 11) + oz;
        int wx = (x0 << 11) + ox;
        int cell = row->m_offset + (x0 - row->m_start);
        for (int xi = x0; xi <= x1; xi++) {
            row = &o->m_rows[zc];
            int xc = row->m_start;
            if (xc < xi) {
                xc = row->m_end;
                if (xi < xc)
                    xc = xi;
            }
            int base = o->m_cellBase[o->m_cells[cell]];
            cell++;
            wx += 0x800;
            int idx = sub + (xc & 0xF);
            for (int k = 0; k < 4; k++) {
                int b = o->m_blade[idx];
                if (b != 0xFF) {
                    int y = base + height[b];
                    int top = y + oy;
                    int px = wx + spread[o->m_bladeX[idx]];
                    int pz = wz + spread[o->m_bladeZ[idx]];
                    if (left == 0) {
                        out[0] = 0x01000102;
                        start = out;
                        left = 0x50;
                        *(float*)&out[2] = 2.3841858e-7f;
                        out[1] = (D_00394280 & 0x3FF) | 0x6C014000;
                        out[3] = ((unsigned int)D_200 >> 3) | 0x2024C000;
                        out[4] = 0x51;
                        out[2] |= 0x80A0;
                        out[5] = 0x140;
                        out[6] = ((D_00394280 + 1) & 0x3FF) | 0x6EA04000;
                        unsigned int* col = out + 7;
                        out = (unsigned int*)((char*)out + 0x29C);
                        out[0] = 0x05000001;
                        rec = out + 2;
                        out[1] = ((D_00394280 + 2) & 0x3FF) | 0x7CA00000;
                        out = (unsigned int*)((char*)out + 0xA08);
                        out[0] = 0x05000000;
                        D_00394280 += 0x141;
                        out[1] = ((unsigned int)D_310 >> 3) | 0x14000000;
                        out += 2;
                        D_00394294 = D_00394280;
                        for (int j = 0x4F; j >= 0; j--) {
                            col[0] = o->m_14;
                            col[1] = o->m_10;
                            col += 2;
                        }
                    }
                    rec[1] = y;
                    left--;
                    rec[4] = px;
                    rec[5] = top;
                    rec[6] = pz;
                    rec[0] = px;
                    rec[2] = pz;
                    rec[3] = 0;
                    rec[7] = 0;
                    rec += 8;
                }
                idx += 0x100;
            }
        }
    }

    if (left == 0x50) {
        out = start;
        D_00394280 -= 0x141;
    } else if (left != 0) {
        for (int j = 0; j < left; j++) {
            rec[0] = 0;
            rec[1] = 0;
            rec[2] = 0;
            rec[3] = 0;
            rec[4] = 0;
            rec[5] = 0;
            rec[6] = 0;
            rec[7] = 0;
            rec += 8;
        }
    }
    D_00394274 = out;

    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4)
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
}
