typedef int qword __attribute__((mode(TI)));

struct Vec_001B3CF8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001B3CF8() {}
    Vec_001B3CF8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct C_001B3CF8 {
    char pad0[0x44];
    int m_prev;
    int m_cur;
    int m_next;
    Vec_001B3CF8 m_prevPos;
    Vec_001B3CF8 m_curPos;
    Vec_001B3CF8 m_nextPos;
    void PickNext();
};

extern char D_00362B20[];
extern "C" void* func_00229DF0(int node);
extern "C" int func_00229EB0(int node);
extern "C" int func_00229F48(int node, int i);
extern "C" void func_0022A090(int node, Vec_001B3CF8* out);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E53A0(unsigned int name, int flag);
extern "C" float func_001E5370(const char* name, int flag);
extern "C" float func_00101BC8(Vec_001B3CF8* a, Vec_001B3CF8* b);
extern "C" int func_00100030(int n);

void C_001B3CF8::PickNext()
{
    int noSkip = 0;
    unsigned int type;
    if (func_001E8398(func_00229DF0(m_prev), 0x963DC198, &type, 0))
        noSkip = type == 0xE41199AF;
    int n = func_00229EB0(m_cur);
    int result;
    if (n == 0) {
        result = m_prev;
    } else if (n == 1) {
        result = func_00229F48(m_cur, 0);
        if (result == m_prev) {
            unsigned int t;
            if (func_001E8398(func_00229DF0(m_cur), 0x963DC198, &t, 0) && t == 0x7D9D0008)
                result = m_cur;
        }
    } else {
        Vec_001B3CF8 dir(m_curPos.x - m_prevPos.x, m_curPos.y - m_prevPos.y, m_curPos.z - m_prevPos.z,
                         m_curPos.w - m_prevPos.w);
        int left[20];
        int right[20];
        for (int j = 0; j < n; j++) {
            left[j] = j;
            right[j] = j;
        }
        int nRight = 0;
        int minAngle = func_001E53A0(0xFE65D822, 1);
        float best = 0.0f;
        int bestIdx = 0;
        int nLeft = 0;
        for (int i = 0; i < n; i++) {
            int node = func_00229F48(m_cur, i);
            if (node == m_prev)
                continue;
            void* p = func_00229DF0(node);
            unsigned int kind = 0;
            unsigned int sub = 0;
            func_001E8398(p, 0x12B4E660, &kind, 0);
            func_001E8398(p, 0x7321A8D6, &sub, 0);
            if (kind != 0x4C23A77E)
                continue;
            if (sub != 0xCBA10FFA)
                continue;
            if (!noSkip) {
                unsigned int t;
                if (func_001E8398(p, 0x963DC198, &t, 0) && t == 0xE41199AF)
                    continue;
            }
            Vec_001B3CF8 pos;
            func_0022A090(node, &pos);
            Vec_001B3CF8 d(m_curPos.x - pos.x, m_curPos.y - pos.y, m_curPos.z - pos.z, m_curPos.w - pos.w);
            float ang = func_00101BC8(&dir, &d);
            if (ang > 360.0f)
                ang -= (float)(int)(ang * (1.0f / 360.0f)) * 360.0f;
            if (ang > best) {
                best = ang;
                bestIdx = i;
            }
            if ((float)minAngle <= ang) {
                unsigned int side;
                func_001E8398(p, 0x9D5923D8, &side, 1);
                if (side != 0x6D77875E) {
                    if (side == 0xDE7A971B)
                        left[nLeft++] = i;
                } else {
                    right[nRight++] = i;
                }
            }
        }
        if (!nLeft && !nRight) {
            result = func_00229F48(m_cur, bestIdx);
        } else {
            bool useRight = false;
            if (nLeft && nRight) {
                float pct = func_001E5370(D_00362B20, 1);
                if ((float)func_00100030(100) <= pct * 100.0f)
                    useRight = true;
            } else {
                useRight = nRight != 0;
            }
            if (useRight)
                result = func_00229F48(m_cur, right[func_00100030(nRight)]);
            else
                result = func_00229F48(m_cur, left[func_00100030(nLeft)]);
        }
    }
    if (result != -1) {
        m_next = result;
        func_0022A090(result, &m_nextPos);
    }
}
