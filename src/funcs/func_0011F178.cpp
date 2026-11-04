struct Array_0011F178 {
    char pad[0xC];
    unsigned int m_size;
};

extern "C" char* func_00336418(const char* s, int c);
extern "C" char* func_003317AC(char* s, int c);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_001E82B8(void* s, const char* name, Array_0011F178** out, int req);
extern "C" int func_001E7F50(void* s, const char* name, float* out, int req);
extern "C" void* func_001E9378(Array_0011F178* a, unsigned int i);
extern "C" unsigned int func_001E9300(Array_0011F178* a, unsigned int i);
extern char D_0035CA48[];
extern char D_0035CA58[];
extern const float D_00389444[];

class C_0011F178 {
public:
    char pad[0x308];
    int m_mask[0x40];
    float m_dist[0x40];
    void Load(const char* path);
    int Index(unsigned int id);
};

void C_0011F178::Load(const char* path)
{
    char name[128];
    const char* s = func_00336418(path, '/');
    if (s || (s = func_00336418(path, '\\')))
        func_00331A9C(name, s + 1);
    else
        func_00331A9C(name, path);
    char* dot = func_003317AC(name, '.');
    if (dot)
        *dot = 0;
    void* data = func_001E5548(0x7DA53781, 0);
    if (!data)
        return;
    Array_0011F178* list = 0;
    func_001E82B8(data, name, &list, 0);
    if (!list)
        return;
    unsigned int n = list->m_size;
    for (unsigned int i = 0; i < n; i++) {
        void* e = func_001E9378(list, i);
        float d = 0.0f;
        if (func_001E7F50(e, D_0035CA48, &d, 0)) {
            d *= 12.0f;
            if (i == n - 1)
                m_dist[i] = D_00389444[0];
            else
                m_dist[i] = d * d;
        }
        Array_0011F178* ids = 0;
        if (func_001E82B8(e, D_0035CA58, &ids, 0)) {
            unsigned int m = ids->m_size;
            for (unsigned int j = 0; j < m; j++)
                m_mask[Index(func_001E9300(ids, j))] = -1 << i;
        }
    }
}
