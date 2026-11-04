struct Vec_00257B58 {
    float x, y, z, w;
    Vec_00257B58() {}
    Vec_00257B58(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float LengthSqr() const { return x * x + y * y + z * z; }
};

static inline Vec_00257B58 operator-(const Vec_00257B58& a, const Vec_00257B58& b)
{
    return Vec_00257B58(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Node_00257B58 {
    void* m_data;
    unsigned int m_pri;
    Node_00257B58* m_prev;
    Node_00257B58* m_next;
    Node_00257B58* GetItem() { return m_pri == 0xFFFFFFFF ? 0 : this; }
};

struct Head_00257B58 {
    void* m_data;
    unsigned int m_pri;
    Node_00257B58* m_prev;
    Node_00257B58* m_next;
    Node_00257B58* FirstItem()
    {
        if (!~m_next->m_pri) {
            return 0;
        }
        return m_next;
    }
    int CountItems()
    {
        int count = 0;
        Node_00257B58* item = FirstItem();
        while (item) {
            item = item->m_next->GetItem();
            count++;
        }
        return count;
    }
};

struct Mgr_00257B58 {
    char m_pad[0x30];
    Head_00257B58 m_skaters;
};

struct Skater_00257B58 {
    char m_pad[0x50];
    Vec_00257B58 m_pos;
};

extern Mgr_00257B58* D_0038FC78;

extern "C" Skater_00257B58* func_0022DE70(Mgr_00257B58* self, int index);
extern "C" bool func_002577E0(Skater_00257B58* self, Skater_00257B58* other, unsigned int name);

bool func_00257B58(Skater_00257B58* self, unsigned int name, float dist_sqr)
{
    int num = D_0038FC78->m_skaters.CountItems();
    for (int i = 0; i < num; i++) {
        Skater_00257B58* other = func_0022DE70(D_0038FC78, i);
        if (other == self) {
            continue;
        }
        if (name) {
            if (func_002577E0(self, other, name)) {
                return true;
            }
        } else {
            Vec_00257B58 d(other->m_pos.x - self->m_pos.x, other->m_pos.y - self->m_pos.y,
                           other->m_pos.z - self->m_pos.z, other->m_pos.w - self->m_pos.w);
            if (d.LengthSqr() < dist_sqr) {
                return true;
            }
        }
    }
    return false;
}
