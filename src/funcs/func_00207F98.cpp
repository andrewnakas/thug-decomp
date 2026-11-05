typedef int qword_00207F98 __attribute__((mode(TI)));

struct Vec_00207F98 {
    union {
        struct { float x, y, z; int w; } f;
        qword_00207F98 q;
    };
};

struct Box_00207F98 {
    Vec_00207F98 min;
    Vec_00207F98 max;
    Box_00207F98& operator=(const Box_00207F98& o)
    {
        min.q = o.min.q;
        max.q = o.max.q;
        return *this;
    }
};

struct Cell_00207F98 {
    Box_00207F98 box;
    char pad20[0x10];
};

struct Grid_00207F98 {
    Box_00207F98 m_box;
    float m_dx;
    float m_dz;
    int m_rows;
    int m_cols;
    Cell_00207F98 m_cells[20][20];

    void Init(const Box_00207F98& b);
};

void Grid_00207F98::Init(const Box_00207F98& b)
{
    Box_00207F98 cell;
    cell.min.f.w = 0;
    m_box.min.q = b.min.q;
    cell.max.f.w = 0;
    m_box.max.q = b.max.q;
    float w = b.max.f.x - b.min.f.x;
    float d = b.max.f.z - b.min.f.z;
    m_dx = w * 0.05f;
    m_dz = d * 0.05f;
    float x = b.min.f.x;
    for (int i = 0; i < 20; i++) {
        float z = b.min.f.z;
        for (int j = 0; j < 20; j++) {
            cell.min.f.x = x;
            cell.min.f.y = -1e12f;
            cell.min.f.z = z;
            cell.max.f.x = x + m_dx;
            cell.max.f.y = 1e12f;
            cell.max.f.z = z + m_dz;
            m_cells[i][j].box = cell;
            z += m_dz;
        }
        x += m_dx;
    }
    m_rows = 20;
    m_cols = 20;
}
