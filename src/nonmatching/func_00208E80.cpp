/* fuzzy: 69.1 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00208E80 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00208E80() {}
    Vec_00208E80(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Box_00208E80 {
    Vec_00208E80 mn;
    Vec_00208E80 mx;
};

struct Item_00208E80 {
    int m0;
    unsigned short m4;
    char pad6[0xA];
    unsigned char m10;
};

struct Cell_00208E80 {
    Box_00208E80 m_box;
    int m20;
    int m_count;
    int m28;
    Item_00208E80** m_items;
};

extern Item_00208E80* D_003F3F70[];
extern "C" void func_00101F38(Box_00208E80* b);
extern "C" void func_003233B8(Vec_00208E80* dst, Vec_00208E80* src);
static inline void Wrap_003233B8(Vec_00208E80* dst, Vec_00208E80* src) { func_003233B8(dst, src); }
extern "C" int func_00207F80();

struct Grid_00208E80 {
    Vec_00208E80 m_origin;
    char pad10[0x10];
    float m_cellW;
    float m_cellH;
    int m_w;
    int m_h;
    Cell_00208E80 m_cells[20][20];
    Item_00208E80** Query(Box_00208E80* box);
};

Item_00208E80** Grid_00208E80::Query(Box_00208E80* box)
{
    int n = 0;
    Box_00208E80 b;
    func_00101F38(&b);
    Vec_00208E80 d;
    d = Vec_00208E80(box->mx.x - box->mn.x, box->mx.y - box->mn.y, box->mx.z - box->mn.z, 1.0f);
    Wrap_003233B8(&d, &d);
    d.x *= 0.5f;
    d.y *= 0.5f;
    d.z *= 0.5f;
    d.w *= 0.5f;
    b.mn.x = box->mn.x - d.x;
    b.mn.y = box->mn.y - d.y;
    b.mn.z = box->mn.z - d.z;
    b.mx.x = box->mx.x + d.x;
    b.mx.y = box->mx.y + d.y;
    b.mx.z = box->mx.z + d.z;
    int x0 = (int)((b.mn.x - m_origin.x) / m_cellW);
    int z0 = (int)((b.mn.z - m_origin.z) / m_cellH);
    if (x0 < 0) x0 = 0;
    else if (x0 >= m_w) x0 = m_w - 1;
    if (z0 < 0) z0 = 0;
    else if (z0 >= m_h) z0 = m_h - 1;
    int x1 = (int)((b.mx.x - m_origin.x) / m_cellW);
    int z1 = (int)((b.mx.z - m_origin.z) / m_cellH);
    if (x1 < 0) x1 = 0;
    else if (x1 >= m_w) x1 = m_w - 1;
    if (z1 < 0) z1 = 0;
    else if (z1 >= m_h) z1 = m_h - 1;
    if (x1 < x0) {
        int t = x1;
        x1 = x0;
        x0 = t;
    }
    if (z1 < z0) {
        int t = z1;
        z1 = z0;
        z0 = t;
    }
    if (x0 == x1 && z0 == z1) {
        Cell_00208E80* c = &m_cells[x1][z1];
        Item_00208E80** out = D_003F3F70;
        Item_00208E80** in = c->m_items;
        for (int k = c->m_count; k > 0; k--) {
            Item_00208E80* it = *in++;
            if (!(it->m4 & 6)) {
                *out++ = it;
            }
        }
        *out = 0;
        return D_003F3F70;
    }
    int stamp = func_00207F80();
    for (int i = x0; i <= x1; i++) {
        for (int j = z0; j <= z1; j++) {
            Cell_00208E80* c = &m_cells[i][j];
            for (int k = 0; k < c->m_count; k++) {
                Item_00208E80* it = c->m_items[k];
                if (!(it->m4 & 6) && it->m10 != stamp && n < 0x3FF) {
                    D_003F3F70[n] = it;
                    n++;
                    it->m10 = stamp;
                }
            }
        }
    }
    D_003F3F70[n] = 0;
    return D_003F3F70;
}
