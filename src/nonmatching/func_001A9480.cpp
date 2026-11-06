/* fuzzy: 88.3 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001A9480 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern "C" float sqrtf(float);

struct Obj_001A9480 {
    int m_pad[20];
    Vec_001A9480 m50;
    int m60[12];
    Vec_001A9480 m90;
};

struct Entry_001A9480 {
    Obj_001A9480* m_obj;
    int m4[2];
};

extern "C" void* func_00185578(Obj_001A9480* obj, unsigned int name);
extern "C" int func_001A67B0(void* comp);
extern "C" int func_001A67E0(void* comp);

struct C_001A9480 {
    int m_pad[3];
    Obj_001A9480* mC;
    int m10[68];
    Entry_001A9480* m120;
    Obj_001A9480* FindNearest(float range);
};

Obj_001A9480* C_001A9480::FindNearest(float range)
{
    Obj_001A9480* best = 0;
    Entry_001A9480* e = m120;
    if (e) {
        float bestd = 0.0f;
        for (int i = 49; i >= 0; i--, e++) {
            Obj_001A9480* o = e->m_obj;
            if (o) {
                Obj_001A9480* p = o;
                Obj_001A9480* me = mC;
                if (p != me) {
                    if (0.0f <= me->m90.x * p->m90.x + me->m90.y * p->m90.y + me->m90.z * p->m90.z) {
                        float dx = p->m50.x - me->m50.x;
                        float dy = p->m50.y - me->m50.y;
                        float dz = p->m50.z - me->m50.z;
                        float dw = p->m50.w - me->m50.w;
                        Vec_001A9480 d;
                        d.x = dx;
                        d.y = dy;
                        d.z = dz;
                        d.w = dw;
                        if (0.0f <= me->m90.x * dx + me->m90.y * dy + me->m90.z * dz) {
                            if (func_001A67B0(func_00185578(p, 0x0A015E17)) != func_001A67B0(this)
                                || func_001A67E0(func_00185578(p, 0x0A015E17)) == func_001A67E0(this)) {
                                me = mC;
                                float ex = me->m50.x - p->m50.x;
                                float ey = me->m50.y - p->m50.y;
                                float ez = me->m50.z - p->m50.z;
                                float ew = me->m50.w - p->m50.w;
                                Vec_001A9480 d2;
                                d2.x = ex;
                                d2.y = ey;
                                d2.z = ez;
                                d2.w = ew;
                                float dist = sqrtf(ex * ex + ey * ey + ez * ez);
                                if (dist <= range) {
                                    if (!best || dist < bestd) {
                                        bestd = dist;
                                        best = o;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return best;
}
