typedef int qword __attribute__((mode(TI)));

struct Vec_001990F0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001990F0() {}
    Vec_001990F0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Ray_001990F0 {
    Vec_001990F0 m_pos;
    Vec_001990F0 m_dir;
};

struct Box_001990F0 {
    char pad0[0x30];
    Vec_001990F0 m_center;
    char pad40[0x60 - 0x40];
    Vec_001990F0 m_axisX;
    Vec_001990F0 m_axisY;
    float m_sizeX;
    float m_sizeY;
};

class Obj_001990F0 {
public:
    float Dist(Ray_001990F0* r, Box_001990F0* b);
};

float Obj_001990F0::Dist(Ray_001990F0* r, Box_001990F0* b)
{
    Vec_001990F0 d(r->m_pos.x - b->m_center.x, r->m_pos.y - b->m_center.y, r->m_pos.z - b->m_center.z, r->m_pos.w - b->m_center.w);
    int side = 0;
    float best = d.x * b->m_axisX.x + d.y * b->m_axisX.y + d.z * b->m_axisX.z;
    float t = b->m_sizeX - best;
    if (t < best) {
        best = t;
        side = 1;
    }
    t = d.x * b->m_axisY.x + d.y * b->m_axisY.y + d.z * b->m_axisY.z;
    if (t < best) {
        best = t;
        side = 2;
    }
    t = b->m_sizeY - t;
    if (t < best) {
        best = t;
        side = 3;
    }
    if (best < 0.01f) {
        return 0.0f;
    }
    switch (side) {
    case 0:
        t = best / (b->m_axisX.x * r->m_dir.x + b->m_axisX.y * r->m_dir.y + b->m_axisX.z * r->m_dir.z);
        break;
    case 1:
        t = -best / (b->m_axisX.x * r->m_dir.x + b->m_axisX.y * r->m_dir.y + b->m_axisX.z * r->m_dir.z);
        break;
    case 2:
        t = best / (b->m_axisY.x * r->m_dir.x + b->m_axisY.y * r->m_dir.y + b->m_axisY.z * r->m_dir.z);
        break;
    case 3:
        t = -best / (b->m_axisY.x * r->m_dir.x + b->m_axisY.y * r->m_dir.y + b->m_axisY.z * r->m_dir.z);
        break;
    }
    return t;
}
